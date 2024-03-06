#Read the file
data <- read.csv("C:/Users/hsian/Documents/GitHub/Learning_in_college/Statistics/R_statistics/DiamondsPrices.csv")
View(data)
summary(data)

library(dplyr)
library(ggplot2) #ggplot2:https://hackmd.io/@mutolisp/rJAzWj4x4#19-%E5%A4%9A%E5%9C%96%E6%8E%92%E5%88%97facet
#綜合圖表，但資訊太多，呈現模糊
ggplot(data=data)+
  geom_point(mapping = aes(x=carat, y=price, color=cut, shape = cut))+
  facet_grid(rows = vars(clarity), cols = vars(color))

#color--price distribution
data %>% 
  ggplot(aes(x = color, y = price, color = color)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) + #mean point
  stat_summary( #mean number text
    fun = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  #coord_cartesian(ylim=c(50,80))+ #zoom in
  xlab("Color") + 
  ylab("Price")

#color
D_price <- data$price[data$color=='D']
E_price <- data$price[data$color=='E']
F_price <- data$price[data$color=='F']
G_price <- data$price[data$color=='G']
H_price <- data$price[data$color=='H']
I_price <- data$price[data$color=='I']
J_price <- data$price[data$color=='J']
#根據box-plot假設:J_price>I_price>H_price>G_price>F_price>D_price>E_price
#1. color J的price平均是否大於color I的price平均
#H0:μJ - μI <= 0, H1:μJ - μI > 0

var.test(J_price, I_price) #p-value = 0.0001801(<0.05)，表示兩組變異數有顯著差異

t.test(J_price, I_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 2.1988, df = 5996.3, p-value = 0.01397(>0.05)，
#無法拒絕H0，表示沒有足夠的證據證明color J的price平均大於color I的price平均

#2. color I的price平均是否大於color H的price平均
#H0:μI - μH <= 0, H1:μI - μH > 0

var.test(I_price, H_price) #p-value < 2.2e-16(<0.05)，表示兩組變異數有顯著差異

t.test(I_price, H_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 7.6532, df = 10648, p-value = 1.065e-14(<0.05)，
#拒絕H0，表示有足夠的證據證明color I的price平均大於color H的price平均

#3. color H的price平均是否大於color G的price平均
#H0:μH - μG <= 0, H1:μH - μG > 0

var.test(H_price, G_price) #p-value = 9.232e-05(<0.05)，表示兩組變異數有顯著差異

t.test(H_price, G_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 8.1326, df = 17480, p-value = 2.241e-16(<0.05)，
#拒絕H0，表示有足夠的證據證明color H的price平均大於color G的price平均

#4. color G的price平均是否大於color F的price平均
#H0:μG - μF <= 0, H1:μG - μF > 0

var.test(G_price, F_price) #p-value = 5.445e-12(<0.05)，表示兩組變異數有顯著差異

t.test(G_price, F_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 5.0453, df = 20623, p-value = 2.284e-07(<0.05)，
#拒絕H0，表示有足夠的證據證明color G的price平均大於color F的price平均

#5. color F的price平均是否大於color D的price平均
#H0:μF - μD <= 0, H1:μF - μD > 0

var.test(F_price, D_price) #p-value < 2.2e-16(<0.05)，表示兩組變異數有顯著差異

t.test(F_price, D_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 9.865, df = 15536, p-value < 2.2e-16(<0.05)，
#拒絕H0，表示有足夠的證據證明color F的price平均大於color D的price平均

#6. color D的price平均是否大於color E的price平均
#H0:μD - μE <= 0, H1:μD - μE > 0

var.test(D_price, E_price) #p-value = 0.7387(>0.05)，表示兩組變異數沒有顯著差異

t.test(D_price, E_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = TRUE,
       conf.level = 0.95)

#t = 1.7611, df = 16570, p-value = 0.03912(<0.05)，
#拒絕H0，表示有足夠的證據證明color D的price平均大於color E的price平均

#ANOVA檢定
#(1) 常態性檢查
install.packages("nortest")
library(nortest)
#因為sharpiro.text的sample size要在3~5000，所以用Anderson-Darling 常態性檢定
data %>% group_by(color) %>% summarize(p_value=ad.test(price)$p.value)
#<chr>   <dbl>
#1 D     3.7e-24
#2 E     3.7e-24
#3 F     3.7e-24
#4 G     3.7e-24
#5 H     3.7e-24
#6 I     3.7e-24
#7 J     3.7e-24
#各顏色的價格皆不符合常態分佈

# (2) 同質性檢查
library(car)
leveneTest(price ~ color, data)
# P < 2.2e-16 各組別變異數不相等


#不同顏色對於鑽石價格是否有差異? 
#(因為實際上常態性和同質性皆不符合ANOVA定義，所以這裡是強制符合定義)
#H0: D = E = F = G = H = I = J (price)。
#HA: Otherwise 
aov.color <- aov(price ~ color, data = data)
summary(aov.color)

result <- TukeyHSD(aov.color, conf.level=0.95)
plot(result, las=1, col="red", cex.axis=1)







#clarity
#clarity--price distribution
data %>% 
  mutate(clarity_flawless=factor(clarity, levels=c(  "I1",   "SI2","SI1","VS2","VS1","VVS2","VVS1", "IF"))) %>%
  ggplot(aes(x = clarity_flawless, y = price, color = clarity_flawless)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) + #mean point
  stat_summary( #mean number text
    fun = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  xlab("Clarity") + 
  ylab("Price")

SI2_price <- data$price[data$clarity=='SI2']
SI1_price <- data$price[data$clarity=='SI1']
VS2_price <- data$price[data$clarity=='VS2']
I1_price <- data$price[data$clarity=='I1']
VS1_price <- data$price[data$clarity=='VS1']
VVS2_price <- data$price[data$clarity=='VVS2']
IF_price <- data$price[data$clarity=='IF']
VVS1_price <- data$price[data$clarity=='VVS1']

#根據box-plot假設:SI2_price>SI1_price>VS2_price>I1_price>
#                     VS1_price>VVS2_price>IF_price>VVS1_price
#1. SI2的price平均是否大於SI1 I的price平均
#H0:μSI2 - μSI1 <= 0, H1:μSI2 - μSI1 > 0

var.test(SI2_price, SI1_price) #p-value = < 2.2e-16(<0.05)，表示兩組變異數有顯著差異

t.test(SI2_price, SI1_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 19.229, df = 18324, p-value < 2.2e-16(<0.05)，
#拒絕H0，表示有足夠的證據證明SI2的price平均大於SI1的price平均

#2. SI1的price平均是否大於VS2的price平均
#H0:μSI1 - μVS2 <= 0, H1:μSI1 - μVS2 > 0

var.test(SI1_price, VS2_price) #p-value = 3.184e-12，表示兩組變異數有顯著差異

t.test(SI1_price, VS2_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 1.4382, df = 24928, p-value = 0.0752(>0.05)，
#無法拒絕H0，表示沒有足夠的證據證明SI1的price平均大於VS2的price平均

#3. VS2的price平均是否大於I1的price平均
#H0:μVS2 - μI1 <= 0, H1:μVS2 - μI1 > 0

var.test(VS2_price, I1_price) #p-value < 2.2e-16(<0.05)，表示兩組變異數有顯著差異

t.test(VS2_price, I1_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 0.007503, df = 936.31, p-value = 0.497(>0.05)，
#無法拒絕H0，表示沒有足夠的證據證明VS2的price平均大於I1的price平均

#4. I1的price平均是否大於VS1的price平均
#H0:μI1 - μVS1 <= 0, H1:μI1 - μVS1 > 0

var.test(I1_price, VS1_price) #p-value < 2.2e-16(<0.05)，表示兩組變異數有顯著差異

t.test(I1_price, VS1_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 0.75465, df = 1036.4, p-value = 0.2253(>0.05)，
#無法拒絕H0，表示沒有足夠的證據證明I1的price平均大於VS1的price平均

#5. VS1的price平均是否大於VVS2的price平均
#H0:μVS1 - μVVS2 <= 0, H1:μVS1 - μVVS2 > 0

var.test(VS1_price, VVS2_price) #p-value = 0.0001326(<0.05)，表示兩組變異數有顯著差異

t.test(VS1_price, VVS2_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 7.9775, df = 11130, p-value = 8.197e-16(<0.05)，
#拒絕H0，表示有足夠的證據證明VS1的price平均大於VVS2的price平均

#6. VVS2的price平均是否大於IF的price平均
#H0:μVVS2 - μIF <= 0, H1:μVVS2 - μIF > 0

var.test(VVS2_price, IF_price) #p-value = 0.1864(>0.05)，表示兩組變異數沒有顯著差異

t.test(VVS2_price, IF_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = TRUE,
       conf.level = 0.95)

#t = 3.9595, df = 6854, p-value = 3.794e-05(<0.05)，
#拒絕H0，表示有足夠的證據證明VVS2的price平均大於IF的price平均

#7. IF的price平均是否大於VVS1的price平均
#H0:μIF - μVVS1 <= 0, H1:μIF - μVVS1 > 0

var.test(IF_price, VVS1_price) #p-value = 8.882e-16(<0.05)，表示兩組變異數有顯著差異

t.test(IF_price, VVS1_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 3.169, df = 3091.6, p-value = 0.0007724(<0.05)，
#拒絕H0，表示有足夠的證據證明IF的price平均大於VVS1的price平均

#ANOVA檢定
#(1) 常態性檢查
#install.packages("nortest")
library(nortest)
#因為sharpiro.text的sample size要在3~5000，所以用Anderson-Darling 常態性檢定
data %>% group_by(clarity) %>% summarize(p_value=ad.test(price)$p.value)
#<chr>     <dbl>
#1 I1      3.7e-24
#2 IF      3.7e-24
#3 SI1     3.7e-24
#4 SI2     3.7e-24
#5 VS1     3.7e-24
#6 VS2     3.7e-24
#7 VVS1    3.7e-24
#8 VVS2    3.7e-24
#各顏色的價格皆不符合常態分佈

# (2) 同質性檢查
library(car)
leveneTest(price ~ clarity, data)
# P < 2.2e-16 各組別變異數不相等


#不同澄清度對於鑽石價格是否有差異? 
#(因為實際上常態性和同質性皆不符合ANOVA定義，所以這裡是強制符合定義)
#H0: SI2=SI1=VS2=I1=VS1=VVS2=IF=VVS1 (price)。
#HA: Otherwise 
aov.clarity <- aov(price ~ clarity, data = data)
summary(aov.clarity)

result2 <- TukeyHSD(aov.clarity, conf.level=0.95)
plot(result2, las=1, col="blue", cex.axis=0.6)

R.version


#cut():將連續變數分割:https://bultle.pixnet.net/blog/post/176240283-r-tips%3A-cut%28%29,
#       https://blog.csdn.net/AhaBob/article/details/120639097
#cut
#cut--price distribution
data %>% 
  mutate(cut_order=factor(cut, levels=c("Ideal", "Good", "Very Good", "Fair", "Premium"))) %>%
  ggplot(aes(x = cut_order, y = price, color = cut_order)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) + #mean point
  stat_summary( #mean number text
    fun = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  #coord_cartesian(ylim=c(50,80))+ #zoom in
  xlab("Cut") + 
  ylab("Price")

Premium_price <- data$price[data$cut=='Premium']
Fair_price <- data$price[data$cut=='Fair']
Very_Good_price <- data$price[data$cut=='Very Good']
Good_price <- data$price[data$cut=='Good']
Ideal_price <- data$price[data$cut=='Ideal']
#根據box-plot假設:Premium_price>Fair_price>Very_Good_price>Good_price>
#                     Ideal_price
#1. 
#H0:μPremium - μFair <= 0, H1:μPremium - μFair > 0

var.test(Premium_price, Fair_price) #p-value = < 2.2e-16(<0.05)，表示兩組變異數有顯著差異

t.test(Premium_price, Fair_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 2.3453, df = 2210.6, p-value = 0.009551(<0.05)，
#拒絕H0，表示有足夠的證據證明Premium的price平均大於Fair的price平均

#2. SI1的price平均是否大於Very_Good的price平均
#H0:μFair - μVery_Good <= 0, H1:μFair - μVery_Good > 0

var.test(Fair_price, Very_Good_price) #p-value = 2.013e-07，表示兩組變異數有顯著差異

t.test(Fair_price, Very_Good_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 3.94, df = 2168, p-value = 4.203e-05(<0.05)，
#拒絕H0，表示有足夠的證據證明Fair的price平均大於Very_Good的price平均

#3. Very_Good的price平均是否大於Good的price平均
#H0:μVery_Good - μGood <= 0, H1:μVery_Good - μGood > 0

var.test(Very_Good_price, Good_price) #p-value = 3.363e-08(<0.05)，表示兩組變異數有顯著差異

t.test(Very_Good_price, Good_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 0.83169, df = 9668.6, p-value = 0.2028(>0.05)，
#無法拒絕H0，表示沒有足夠的證據證明Very_Good的price平均大於Good的price平均

#4. Good的price平均是否大於Ideal的price平均
#H0:μGood - μIdeal <= 0, H1:μGood - μIdeal > 0

var.test(Good_price, Ideal_price) #p-value = 0.002691(<0.05)，表示兩組變異數有顯著差異

t.test(Good_price, Ideal_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 8.0409, df = 7484.7, p-value = 5.144e-16(<0.05)，
#拒絕H0，表示有足夠的證據證明Good的price平均大於Ideal的price平均

#ANOVA檢定
#(1) 常態性檢查
#install.packages("nortest")
library(nortest)
#因為sharpiro.text的sample size要在3~5000，所以用Anderson-Darling 常態性檢定
data %>% group_by(cut) %>% summarize(p_value=ad.test(price)$p.value)
#cut       p_value
#<chr>       <dbl>
#1 Fair      3.7e-24
#2 Good      3.7e-24
#3 Ideal     3.7e-24
#4 Premium   3.7e-24
#5 Very Good 3.7e-24
#各顏色的價格皆不符合常態分佈

# (2) 同質性檢查
library(car)
leveneTest(price ~ cut, data)
# P < 2.2e-16 各組別變異數不相等


#(因為實際上常態性和同質性皆不符合ANOVA定義，所以這裡是強制符合定義)
#H0: Fair=Good=Ideal=Premium=Very Good (price)。
#HA: Otherwise 
aov.cut <- aov(price ~ cut, data = data)
summary(aov.cut)

result_cut <- TukeyHSD(aov.cut, conf.level=0.95)
plot(result_cut, las=1, col="purple", cex.axis=0.5)

#Error---
#View(result_cut)
result_cut
result_cut_diff <- as.data.frame(result_cut$cut)
ggplot(result_cut_diff, aes(x=factor(cut), y=diff))+
  geom_point()+
  geom_errorbar(aes(ymin=lwr, ymax=upr))+
  labs(x="Cut", y="Price Difference")+ 
  ggtitle("TukeyHSD Test for Diamond Price by Cut")
#View(result_cut_diff)
#---

#carat--price distribution
data %>% 
  ggplot(aes(x = carat, y = price, color = carat)) + 
  geom_point()+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  xlab("Carat") + 
  ylab("Price")

carat <- data %>% mutate(carat_group=cut(data$carat, breaks=c(0, 1, 2, Inf), labels = c('<1', '1~2', '2<')))
carat %>% 
  ggplot(aes(x = carat_group, y = price, color = carat_group)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) + #mean point
  stat_summary( #mean number text
    fun = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  #coord_cartesian(ylim=c(50,80))+ #zoom in
  xlab("Carat") + 
  ylab("Price")

#carat
less_1_carat_price <- data$price[data$carat< 1]
less_2_carat_price <- data$price[data$carat>=1 & data$carat<2]
greater_2_carat_price <- data$price[data$carat>=2]
#根據box-plot假設:greater_2_carat_price>less_2_carat_price>less_1_carat_price
#1. 
#H0:μgreater_2_carat - μless_2_carat <= 0, H1:μgreater_2_carat - μless_2_carat > 0

var.test(greater_2_carat_price, less_2_carat_price) #p-value = 2.656e-15

t.test(greater_2_carat_price, less_2_carat_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 117.83, df = 2917.3, p-value < 2.2e-16

#2. 
#H0:μless_2_carat - μless_1_carat <= 0, H1:μless_2_carat - μless_1_carat > 0

var.test(less_2_carat_price, less_1_carat_price) #p-value < 2.2e-16

t.test(less_2_carat_price, less_1_carat_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 226.9, df = 18996, p-value < 2.2e-16

#ANOVA檢定
#(1) 常態性檢查
#install.packages("nortest")
library(nortest)
#因為sharpiro.text的sample size要在3~5000，所以用Anderson-Darling 常態性檢定
carat %>% group_by(carat_group) %>% summarize(p_value=ad.test(price)$p.value)
#cut       p_value
#<chr>       <dbl>
#1 <1      3.7e-24
#2 1~2      3.7e-24
#3 2<     3.7e-24
#各顏色的價格皆不符合常態分佈

# (2) 同質性檢查
library(car)
leveneTest(price ~ carat_group, carat)
# P < 2.2e-16 各組別變異數不相等

#(因為實際上常態性和同質性皆不符合ANOVA定義，所以這裡是強制符合定義)
#H0: greater_2_carat_price=less_2_carat_price=less_1_carat_price (price)。
#HA: Otherwise 
aov.carat <- aov(price ~ carat_group, data = carat)
summary(aov.carat)

result_carat <- TukeyHSD(aov.carat, conf.level=0.95)
plot(result_carat, las=1, col="orange", cex.axis=1)







#depth
#depth--price distribution
data %>% 
  ggplot(aes(x = depth, y = price, color = depth)) + 
  geom_point()+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  xlab("Depth") + 
  ylab("Price")

#將x-axis的組別自訂排序ex:ggplot(aes(x = factor(depth_group, levels=c('60~62.5', '<57.5', '62.5~65', '65<', '57.5~60')), y = price, color = depth_group))
depth <- data %>% mutate(depth_group=cut(data$depth, breaks=c(0, 57.5, 60, 62.5, 65, Inf), labels = c('<57.5', '57.5~60', '60~62.5', '62.5~65', '65<')))
depth %>% 
  ggplot(aes(x = factor(depth_group, levels=c('60~62.5', '<57.5', '62.5~65', '65<', '57.5~60')), y = price, color = depth_group)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) + #mean point
  stat_summary( #mean number text
    fun = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  #coord_cartesian(ylim=c(50,80))+ #zoom in
  xlab("Depth") + 
  ylab("Price")

less_57.5_depth_price <- depth$price[depth$depth_group == '<57.5']
less_60_depth_price <- depth$price[depth$depth_group == '57.5~60']
less_62.5_depth_price <- depth$price[depth$depth_group == '60~62.5']
less_65_depth_price <- depth$price[depth$depth_group == '62.5~65']
greater_65_depth_price <- depth$price[depth$depth_group == '65<']
#根據box-plot假設:'60~62.5' < '<57.5' < '62.5~65' < '65<' < '57.5~60'
#1. 
var.test(less_60_depth_price, greater_65_depth_price) #p-value = 1.581e-10

t.test(less_60_depth_price, greater_65_depth_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 1.1366, df = 1243.3, p-value = 0.128

#2. 
var.test(greater_65_depth_price, less_65_depth_price) #p-value = 0.000328

t.test(greater_65_depth_price, less_65_depth_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 1.8159, df = 976.45, p-value = 0.03484

#3
var.test(less_65_depth_price, less_57.5_depth_price) #p-value = 4.52e-06

t.test(less_65_depth_price, less_57.5_depth_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 1.8417, df = 395.98, p-value = 0.03314

#4
var.test(less_57.5_depth_price, less_62.5_depth_price) #p-value = 1.26e-06

t.test(less_57.5_depth_price, less_62.5_depth_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 0.10431, df = 375.17, p-value = 0.4585

#ANOVA檢定
#(1) 常態性檢查
#install.packages("nortest")
library(nortest)
#因為sharpiro.text的sample size要在3~5000，所以用Anderson-Darling 常態性檢定
depth %>% group_by(depth_group) %>% summarize(p_value=ad.test(price)$p.value)
#<fct>         <dbl>
#1 <57.5       3.7e-24
#2 57.5~60     3.7e-24
#3 60~62.5     3.7e-24
#4 62.5~65     3.7e-24
#5 65<         3.7e-24
#各顏色的價格皆不符合常態分佈

# (2) 同質性檢查
library(car)
leveneTest(price ~ depth_group, depth)
# P =6.74e-16 各組別變異數不相等

aov.depth <- aov(price ~ depth_group, data = depth)
summary(aov.depth)

result_depth <- TukeyHSD(aov.depth, conf.level=0.95)
plot(result_depth, las=1, col="green", cex.axis=1)






#table--price distribution
data %>% 
  ggplot(aes(x = table, y = price, color = table)) + 
  geom_point()+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  xlab("Table") + 
  ylab("Price")
#non-order table
table <- data %>% mutate(table_group=cut(data$depth, breaks=c(0, 55, 60, 65, Inf), labels = c('<55', '55~60', '60~65', '65<')))
table %>% 
  ggplot(aes(x = table_group, y = price, color = table_group)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) + #mean point
  stat_summary( #mean number text
    fun = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  #coord_cartesian(ylim=c(50,80))+ #zoom in
  xlab("Table") + 
  ylab("Price")

#order-table
table %>% 
  ggplot(aes(x = factor(table_group, levels=c('<55', '60~65', '65<', '55~60')), y = price, color = table_group)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) + #mean point
  stat_summary( #mean number text
    fun = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  #coord_cartesian(ylim=c(50,80))+ #zoom in
  xlab("Table") + 
  ylab("Price")

less_55_table_price <- table$price[table$table_group == '<55']
less_60_table_price <- table$price[table$table_group == '55~60']
less_65_table_price <- table$price[table$table_group == '60~65']
greater_65_table_price <- table$price[table$table_group == '65<']
#根據box-plot假設:'<55' < '60~65' < '65<' < '55~60'
#1. 
var.test(less_60_table_price, greater_65_table_price) #p-value = 1.739e-09

t.test(less_60_table_price, greater_65_table_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 0.86815, df = 1208, p-value = 0.1927

#2. 
var.test(greater_65_table_price, less_65_table_price) #p-value = 7.355e-05

t.test(greater_65_table_price, less_65_table_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 3.8858, df = 870.32, p-value = 5.487e-05

#3
var.test(less_65_table_price, less_55_table_price) #p-value = 4.607e-06

t.test(less_65_table_price, less_55_table_price,
       alternative = "greater",
       paired = FALSE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = 4.1845, df = 23.139, p-value = 0.0001759

#ANOVA檢定
#(1) 常態性檢查
library(nortest)
#因為sharpiro.text的sample size要在3~5000，所以用Anderson-Darling 常態性檢定
table %>% group_by(table_group) %>% summarize(p_value=ad.test(price)$p.value)
#table_group  p_value
#<fct>          <dbl>
#1 <55         6.39e- 3
#2 55~60       3.7 e-24
#3 60~65       3.7 e-24
#4 65<         3.7 e-24
#各顏色的價格皆不符合常態分佈

# (2) 同質性檢查
library(car)
leveneTest(price ~ table_group, table)
# P =1.526e-11 各組別變異數不相等

aov.table <- aov(price ~ table_group, data = table)
summary(aov.table)
# P <2e-16

result_table <- TukeyHSD(aov.table, conf.level=0.95)
plot(result_table, las=1, col="darkgreen", cex.axis=1)









#volumn--price distribution
data %>% 
  mutate(volumn=x*y*z) %>%
  ggplot(aes(x = volumn, y = price, color = volumn)) + 
  geom_point()+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  xlab("Volumn") + 
  ylab("Price")

