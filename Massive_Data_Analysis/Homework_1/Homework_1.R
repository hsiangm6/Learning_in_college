library(dplyr)
library(ggplot2)

# 1.1
# 讀取2018年的數據
data_2008_2018 <- read.csv("GitHub/Learning_in_college/Massive_Data_Analysis/Homework_1_dataset/Dengue_y2008_2018.csv")

# 讀取2019年的數據
data_2019 <- read.csv("GitHub/Learning_in_college/Massive_Data_Analysis/Homework_1_dataset/Dengue_y2019_.csv")

# 合併數據
merged_data <- bind_rows(data_2008_2018, data_2019)

# 檢查合併後數據
dim(data_2008_2018) # 135   7
dim(data_2019)      # 2 7
dim(merged_data)    # 137   7


# 1.2 
#檢查缺失值
missing_values <- which(is.na(merged_data), arr.ind = TRUE)
# arr.ind = TRUE返回為缺失值的row, col
# arr.ind = FALSE返回整個資料框，非缺失值為FALSE，缺失值為TRUE
missing_values
#      row col
# [1,]  41   4
# [2,]  41   7
missing_values[, 1] # row number

# 如果有缺失值，顯示整个包含缺失值的資料
if (nrow(missing_values) > 0) {
  print("Observations containing NAs:")
  print(merged_data[missing_values[, 1], ])
  # [1] "Observations containing NAs:"
  # YEAR MONTH      MIN MAX HUMIDITY RAINFALL DENGUE
  # 41   2009    12 18.88889  NA 78.88889 0.888888     NA
  # 41.1 2009    12 18.88889  NA 78.88889 0.888888     NA
  
  # 删除包含缺失值的資料
  df <- merged_data[-missing_values[, 1], ]
}


# 1.3
# 檢查重複的觀測
duplicates <- duplicated(df)
# 顯示每一筆資料，非重複為FALSE，重複為TRUE
duplicates

# 顯示重覆的觀測
print("Duplicate observations:")
print(df[duplicates, ])
# YEAR MONTH      MIN      MAX HUMIDITY  RAINFALL DENGUE
# 38 2008     2 13.65829 26.38345 72.60296 0.6876847      0
# 49 2008     1 12.99393 25.05954 78.82488 1.2866359      0

# 移除重覆的觀測，保留第一次出现的
df_unique <- df[!duplicates, ]
View(df_unique)


# 1.4
# 創建一個新的季節欄位
# 0~2->winter, 3~5->spring, 6~8->summer, 9~11->fall, 12->winter
df_unique$SEASON <- cut(df_unique$MONTH, 
                   breaks = c(0, 2, 5, 8, 11, 12), 
                   labels = c("winter", "spring", "summer", "fall", "winter"), 
                   include.lowest = TRUE) #  表示包括左边界

# 分組按季節計算"DENGUE"的總和
seasonal_sum <- aggregate(df_unique$DENGUE, by = list(df_unique$SEASON), sum)
print("按季節分組後的DENGUE總和:")
print(seasonal_sum)
#   Group.1     x
# 1  winter  1002
# 2  spring   515
# 3  summer 10537
# 4    fall 16298


# 1.5 
# 将"YEAR"列轉換為factor，表達類別信息，使其適用於統計建模和可視化
df_unique$YEAR <- as.factor(df_unique$YEAR)

# 将"MONTH"列轉換為factor
df_unique$MONTH <- as.factor(df_unique$MONTH)

# 将"SEASON"列轉換為factor
df_unique$SEASON <- as.factor(df_unique$SEASON)


# 1.6
# 選擇所有的連續變數
continuous_vars <- sapply(df_unique, is.numeric)

# 為每個連續變數建立密度圖
density_plots <- lapply(names(df_unique)[continuous_vars], function(var) {
  ggplot(df_unique, aes(x = df_unique[[var]])) +
    geom_density(fill = "skyblue", color = "black", alpha = 0.7) +
    labs(title = paste("Density Plot of", var),
         x = var,
         y = "Density")
})
# names(): 1.取得資料框 df 的列名(獲取物件的名稱) 2. 設定物件的名稱
# 顯示所有的密度圖
print(density_plots)


# 1.7 
# Correlation Analysis
# Assuming df is your data frame
correlation_matrix <- cor(df_unique[, c("DENGUE", "MIN","MAX","HUMIDITY","RAINFALL")])
correlation_matrix
#           DENGUE       MIN        MAX   HUMIDITY   RAINFALL
#DENGUE   1.0000000 0.3013156 0.17781094 0.27536273 0.36867454
#MIN      0.3013156 1.0000000 0.87990305 0.50235215 0.23149933
#MAX      0.1778109 0.8799031 1.00000000 0.08785615 0.06459323
#HUMIDITY 0.2753627 0.5023522 0.08785615 1.00000000 0.09496835
#RAINFALL 0.3686745 0.2314993 0.06459323 0.09496835 1.00000000

# Scatter Plots
plot(df_unique$HUMIDITY, df_unique$DENGUE, main = "Scatter Plot of HUMIDITY and DENGUE", xlab = "HUMIDITY", ylab = "DENGUE")

# Box Plot
boxplot(df_unique$DENGUE ~ df_unique$HUMIDITY, main = "Boxplot of DENGUE by HUMIDITY", xlab = "HUMIDITY", ylab = "DENGUE")

# ANOVA
#常態性檢定: Shapiro-Wilk檢定
shapiro.test(df_unique$DENGUE) 
# p-value < 2.2e-16<0.05，不符合正態分佈
shapiro.test(df_unique$HUMIDITY)
# p-value = 9.646e-05<0.05不符合正態分佈
# 不符合常態分佈就已經不適合用anova，以下anova分析當參考
# determine if there are significant differences in the mean of "DENGUE" across different levels of each continuous variable.
# Assuming df is your data frame
anova_result <- aov(DENGUE ~ HUMIDITY, data = df_unique)
summary(anova_result)
# p-value=0.00128<0.05，我們有足夠的證據認為，至少有一組的平均值不相等，即存在組間差異。


# 1.8
# Function to compute Mean Absolute Error (MAE)
compute_mae <- function(actual, predicted) {
  # Check if the lengths of actual and predicted are the same
  if (length(actual) != length(predicted)) {
    stop("Lengths of actual and predicted vectors must be the same.")
  }
  
  # Calculate absolute differences
  absolute_diff <- abs(actual - predicted)
  
  # Calculate mean absolute error
  mae <- mean(absolute_diff)
  
  return(mae)
}


#1.9
# 設定隨機種子
set.seed(1)

# 使用createDataPartition函數劃分訓練集和測試集
index <- sample(1:nrow(df_unique), size = 0.8 * nrow(df_unique))
index
train_data <- df_unique[index, ]
test_data <- df_unique[-index, ]


# 1.10
# 創建並擬合線性模型
model1 <- lm(DENGUE ~ YEAR + MONTH + MIN + MAX + HUMIDITY + RAINFALL + SEASON, data = train_data)
model2 <- lm(DENGUE ~ YEAR + MONTH + MIN + MAX + HUMIDITY, data = train_data)

# 進行預測
train_preds1 <- predict(model1, newdata = train_data)
test_preds1 <- predict(model1, newdata = test_data)

train_preds2 <- predict(model2, newdata = train_data)
test_preds2 <- predict(model2, newdata = test_data)

# 計算 MAE
train_mae1 <- compute_mae(train_data$DENGUE, train_preds1)
test_mae1 <- compute_mae(test_data$DENGUE, test_preds1)

train_mae2 <- compute_mae(train_data$DENGUE, train_preds2)
test_mae2 <- compute_mae(test_data$DENGUE, test_preds2)

# 印出 MAE
# round():用於四捨五入
cat("Model 1 - Training MAE:", round(train_mae1, 4), "\n")
# Model 1 - Training MAE: 164.9726
cat("Model 1 - Testing MAE:", round(test_mae1, 4), "\n")
# Model 1 - Testing MAE: 297.3922

cat("Model 2 - Training MAE:", round(train_mae2, 4), "\n")
# Model 2 - Training MAE: 165.7522
cat("Model 2 - Testing MAE:", round(test_mae2, 4), "\n")
# Model 2 - Testing MAE: 293.9091

# Model 1 的測試 MAE 為 297.3922
# Model 2 的測試 MAE 為 293.9091
# 在這種情況下，Model 2 在測試集上的 MAE 較小，
#   因此在測試集上表現較好。因為 MAE 越小表示模型的
#   預測值與實際值的差異越小，模型的表現越好。


# 二
# 讀取鑽石的數據
diamonds <- read.csv("GitHub/Learning_in_college/Massive_Data_Analysis/Homework_1_dataset/Diamonds.csv")
# 2.1
# Display the first few rows of the dataset
head(diamonds)

# Remove the extraneous column "Unnamed: 0"
diamonds <- diamonds[, -1] #移除第0 column
# Rename the columns "x", "y", "z" with meaningful names
colnames(diamonds)[colnames(diamonds) %in% c("x", "y", "z")] <- c("length_mm", "width_mm", "depth_mm")

# Display the updated dataset
head(diamonds)


# 2.2
# 列出所有欄位的資料型態
data_types <- sapply(diamonds, class)

# 找出字符欄位
character_columns <- names(data_types[data_types == "character"])

# 將字符欄位轉換為因子
diamonds[character_columns] <- lapply(diamonds[character_columns], as.factor)

# 對 "price" 執行對數轉換
diamonds$log_price <- log(diamonds$price)


#2.3 
# 散點圖
ggplot(diamonds, aes(x = carat, y = price)) +
  geom_point() +
  ggtitle("Scatter Plot of carat vs. price")

# boxplot
ggplot(diamonds, aes(x = cut, y = price)) +
  geom_boxplot() +
  ggtitle("Boxplot of cut vs. price")

# 進行 t-test
correlation_carat_price <- cor(diamonds$carat, diamonds$price)
print(paste("Correlation between carat and price:", correlation_carat_price))
# Correlation between carat and price: 0.921591301193477

# ANOVA
anova_cut_price <- aov(price ~ cut, data = diamonds)
print(summary(anova_cut_price))
# p-value<2e-16<0.05，有足夠的證據來認為，至少有兩個組別的平均值是不同的


# 2.4
set.seed(1)
# 隨機將資料分為訓練集（80%）和測試集（20%）
diamonds_indices <- sample(1:nrow(diamonds), size = 0.8 * nrow(diamonds))
train_data_diamonds <- diamonds[diamonds_indices, ]
test_data_diamonds <- diamonds[-diamonds_indices, ]
# 歸一化連續變數
min_max_scale <- function(x) {
  return((x - min(x)) / (max(x) - min(x)))
}

# 提取連續變數的欄位名稱
continuous_vars <- c("carat", "length_mm", "width_mm", "depth_mm", "depth", "table")

# 對連續變數進行歸一化
train_data_diamonds[, continuous_vars] <- lapply(train_data_diamonds[, continuous_vars], min_max_scale)
test_data_diamonds[, continuous_vars] <- lapply(test_data_diamonds[, continuous_vars], min_max_scale)


# 2.5
# 建立線性模型
lm_model_diamonds <- lm(price ~ ., data = train_data_diamonds)

# 在訓練集上進行預測
train_preds_diamonds <- predict(lm_model_diamonds, newdata = train_data_diamonds)

# 在測試集上進行預測
test_preds_diamonds <- predict(lm_model_diamonds, newdata = test_data_diamonds)

# 計算訓練集和測試集的MAE
train_mae_diamonds <- compute_mae(train_data_diamonds$price, train_preds_diamonds)
test_mae_diamonds <- compute_mae(test_data_diamonds$price, test_preds_diamonds)

# 印出結果
cat("Training MAE:", round(train_mae_diamonds, 4), "\n")
# Training MAE: 700.664
cat("Testing MAE:", round(test_mae_diamonds, 4), "\n")
# Testing MAE: 1232.625


# 2.7
# install.packages("rpart")
library(rpart)
# 創建一個決策數模型，考慮所有倆倆交互作用
model_tree <- rpart(price ~ ., data = train_data_diamonds)
# 在訓練集上進行預測
train_preds_tree <- predict(model_tree, newdata = train_data_diamonds)

# 在測試集上進行預測
test_preds_tree <- predict(model_tree, newdata = test_data_diamonds)

# 計算MAE
train_mae_tree <- compute_mae(train_data_diamonds$price, train_preds_tree)
test_mae_tree <- compute_mae(test_data_diamonds$price, test_preds_tree)

# 打印结果
cat("Decision Tree - Training MAE:", round(train_mae_tree, 4), "\n")
# Decision Tree - Training MAE: 400.808
cat("Decision Tree - Testing MAE:", round(test_mae_tree, 4), "\n")
# Decision Tree - Testing MAE: 403.9053
# 相較於2.5題的模型(testing mae: 1232.625)，此模型(testing mae: 403.9053)有更低的錯誤


# 3

#登革熱數據集
# 線性回歸通常適用於預測變量和目標變量之間的關係大致是線性的數據集。
# 對於登革熱數據集，如果連續變量與目標變量（登革熱病例數）之間的關係
#   大致是線性的話，線性回歸可能是合適的。
# 第一題登革熱數據集的MAE(約293)和第二題鑽石數據集的MAE(約1232)說明
#   登革熱數據集比鑽石數據集更適合線性回歸。

# 鑽石數據集
# 線性回歸可能不適用於鑽石數據集，
# 特別是如果預測變量（例如克拉、切割、顏色、淨度、尺寸等）與目標變量（價格）
#   之間的關係不是嚴格線性的話。
# 數據集包含分類變量（切割、顏色、淨度），而這些關係可能涉及非線性模式。
# 在這種情況下，線性回歸可能無法捕捉到關係的複雜性。
# 反而是使用Regression Trees處理這種混合數據類型，回歸樹MAE(約403)的表現
#   比線性回歸好。

# 提高準確性的方法
# 特徵工程： 創建新的有意義的特徵或對現有特徵進行轉換，以更好地表示底層關係。
#             這可能涉及結合或轉換變量以更好地符合線性回歸的假設。
# 正則化： 如果過擬合是一個問題，可以應用正則化技術（例如Ridge或Lasso回歸）
#           以防止模型變得過於複雜。
# 數據預處理： 確保進行適當的預處理，包括處理異常值、處理缺失值，
#               以及適當編碼分類變量。