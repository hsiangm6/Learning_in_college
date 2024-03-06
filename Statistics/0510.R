#https://colab.research.google.com/drive/1AhEMXoF8zbn33B4s9-1wpMv25Ugoxe53?usp=sharing#scrollTo=03u32AWll7ym
#install.packages("ggfortify")
#install.packages("caTools")
#install.packages("car")
#install.packages("ggpubr")


library(ggplot2)
library(ggfortify)
library(caTools)
library(car)


ggplot(mtcars, aes(x = wt, y = mpg)) +
  geom_point() +
  labs(
    y = "Miles per gallon",
    x = "Car's weight (1000 lbs)"
  )


model <- lm(mpg ~ wt, mtcars)
#lm(): 拟合线性模型:Value ~ Group来指定因变量（观测值)和自变量（组）
summary(model)

# load necessary libraries
library(ggpubr)

# create plot with regression line, regression equation and R^2
ggplot(mtcars, aes(x = wt, y = mpg)) +
  geom_smooth(method = "lm") + #在散點圖上添加一條線性回歸線
  geom_point() +
  stat_regline_equation(label.x = 3, label.y = 32) + 
  # stat_regline_equation()用於在圖表中添加回歸線方程式的標籤
  # label.x = 3 表示標籤位於 x 軸上的坐標 3 的位置，
  # label.y = 32 表示標籤位於 y 軸上的坐標 32 的位置
  stat_cor(aes(label = after_stat(rr.label)), label.x = 3, label.y = 30) + # for R^2
  # stat_cor()用於在圖表中添加相關係數的標籤
  theme_minimal() #用於設置圖表的主題風格為簡約風格

##Normality test of residual(常態性檢測)
shapiro.test(model$residual)

##Indepenence test of residuals(獨立性檢測)
durbinWatsonTest(model)

##Homoscedasticity of the residuals(同質性檢測)
ncvTest(model)

##用於自動繪製統計模型的圖表，根據模型的類型和結果，自動生成適當的圖表，
##  以視覺化模型的結果和診斷
autoplot(model)













