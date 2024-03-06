#MIS241-0412LAB

str(iris)
View(iris)

#花萼長度(Sepal.Length)：計算單位是公分。(連續)
#花萼寬度(Sepal.Width)：計算單位是公分。(連續)
#花瓣長度(Petal.Length) ：計算單位是公分。(連續)
#花瓣寬度(Petal.Width)：計算單位是公分。(連續)
#品種(Species)：可分為Setosa，Versicolor和Virginica。(類別)


### 小考題目：探討不同品種(Species)的花瓣長度(Petal.Length)是否有差異？（80%）
library(ggplot2)
ggplot(iris, aes(x = Species, y = Petal.Length)) +
  geom_boxplot()

# (1) 常態性檢查
# 使用shapiro.test：
#shapiro.test函數檢查資料是否為常態分布。
# p-value > 0.05，不拒絕虛無假設，資料符合常態分布。
# p-value < 0.05，拒絕虛無假設，資料不符合常態分布。

library(dplyr)
iris %>% group_by(Species) %>% summarize(p_value=shapiro.test(Petal.Length)$p.value)

#Species    p_value
#<fct>        <dbl>
#1 setosa      0.0548
#2 versicolor  0.158 
#3 virginica   0.110


# (2) 同質性檢查
#使用leveneTest：
#確認不同組別數值是否變異數相等。
# p-value > 0.05，資料數值符合相同變異數。
# p-value < 0.05，資料數值不符合相同變異數。
#install.packages("car")
library(car)
leveneTest(Petal.Length ~ Species, iris)
# P = 3.129e-08<0.05 不符合相同變異數


#ANOVA 
#不同品種(Species)的花瓣長度(Petal.Length)是否有差? 
#H0: setosa = versicolor = virginica  (Petal.Length)。
#HA: Otherwise 

aov.species <- aov(Petal.Length ~ Species, data = iris)
summary(aov.species)

## p-value <2e-16 具顯著性，拒絕H0，代表不同品種(Species)的花瓣長度(Petal.Length)有顯著差異

## Follow-up analysis
result <- TukeyHSD(aov.species, conf.level=0.95)

## las=1 -> 使y軸的標題為橫向
plot(result, las=1, col="red", cex.axis=0.5)
#信賴區間有包含0的話，代表沒有顯著差距



### 若ANOVA為拒絕虛無假設，請由「大到小」排出不同品種的花瓣長度 (20%)
#根據turkey plot，
#因為versicolor-setosa>0，所以versicolor>setosa
#因為virginica-versicolor>0，所以virginica>versicolor
#結論: virginica>versicolor>setosa