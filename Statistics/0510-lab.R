#MIS241-0510LAB
library(ggplot2)
library(ggfortify)
library(caTools)

## 讀取資料集BankChurners.csv
data <- read.csv("BankChurners.csv")
View(data)
### 小考題目：嘗試建立一個簡單線性模型，以總交易次數(Total_Trans_Ct)去預測總交易金額(Total_Trans_Amt)

## 畫出散佈圖 (20%)
ggplot(data, aes(x = Total_Trans_Ct, y = Total_Trans_Amt)) +
  geom_point() +
  labs(
    y = "總交易金額",
    x = "總交易次數"
  )
## 建立模型 (20%)
model <- lm(Total_Trans_Amt ~ Total_Trans_Ct, data) 
            #Total_Trans_Amt(要預測的變數)
summary(model)
#Residuals:
#  Min      1Q  Median      3Q     Max 
#-3523.1 -1390.2  -259.2   816.5  7839.2 

#Coefficients:
#               Estimate Std. Error t value Pr(>|t|)    
#(Intercept)     -3136.1      178.5  -17.57   <2e-16 ***
# Total_Trans_Ct    116.1        2.6   44.63   <2e-16 ***
#  ---
#  Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

#Residual standard error: 1993 on 1017 degrees of freedom
#Multiple R-squared:  0.662,	Adjusted R-squared:  0.6617 
#F-statistic:  1992 on 1 and 1017 DF,  p-value: < 2.2e-16

## 檢查模型是否符合assumption (20%)
##Normality test of residual
shapiro.test(model$residual)
#p-value < 2.2e-16，殘差不符合常態分佈

##Indepenence test of residuals
durbinWatsonTest(model)
#p = 0，殘差間有關連

##Homoscedasticity of the residuals
ncvTest(model)
#p = < 2.22e-16，殘差間的變異數不具有同質性

##
autoplot(model)
## 請解釋模型的beta0與beta1的意義 (40%)
#beta0：當總交易量為0時，模型預測的總交易金額為-3136.1元。
#       這個數字並沒有實際意義，因為總交易次數為0是不可能的情況。
#       這個參數的主要作用是調整回歸線的位置。
#beta1：當總交易次數每增加1次時，模型預測的總交易金額會增加116.1元