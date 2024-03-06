library(ggplot2)
library(dplyr)
library(stats)
data <- read.csv("DiamondsPrices.csv")
#題目：利用卡方檢定探討鑽石的clarity、carat和price之間的關係
View(data)

clarity <- data$clarity[data$clarity!="I1"]
clarity
clarity_table <- table(clarity)
clarity_table
clarity_frame <- as.data.frame(clarity_table)
clarity_frame
ggplot(data.frame(clarity_frame), aes(x=clarity, y=Freq))+
  geom_bar(stat = "identity")

data.frame(clarity_frame)%>%
  mutate(order=factor(clarity, levels=c("SI2","SI1","VS2","VS1","VVS2","VVS1", "IF")))%>%
  ggplot(aes(x=order, y=Freq, fill = order))+
  geom_bar(stat = "identity")+
  xlab("Clarity")+
  theme(axis.text.x=element_text(size=15)) #axis-x label size

carat <- data$carat[data$clarity!="I1"]
carat_group = ifelse(carat<1, "<1", "1<=")
carat_group
carat_table <- table(carat_group)
carat_table
carat_frame <- as.data.frame(carat_table)
carat_frame
ggplot(data.frame(carat_frame), aes(x=carat_group, y=Freq, fill = carat_group))+
  geom_bar(stat = "identity")+
  xlab("Carat")+
  theme(axis.text.x=element_text(size=15)) #axis-x label size

p <- filter(data, data$clarity!="I1")
p
price <- p %>% 
  mutate(price_group=cut(p$price, breaks=c(0, 2500, 5000, 7500, 10000, Inf), labels = c('0~2500', '2500~5000', '5000~7500', '7500~10000', '10000<')))
price_group <- price$price_group
price_group
price_table <- table(price_group)
price_table
price_frame <- as.data.frame(price_table)
price_frame
ggplot(data.frame(price_frame), aes(x=price_group, y=Freq, fill = price_group))+
  geom_bar(stat = "identity")+
  xlab("Price")+
  theme(axis.text.x=element_text(size=15)) #axis-x label size


#適合度檢定:
# 資料集的clarity的資料分布是否符合網頁上的clarity期望值(剃除I2I1)
#H0 : 資料集的clarity和期望的clarity分布相同
#H1 : 資料集的clarity和期望的clarity不相同
#clarity
#IF   SI1   SI2   VS1   VS2  VVS1  VVS2 
#1790 13065  9194  8171 12258  3655  5066
chisq.test(table(clarity), p = c(0.04,0.23,0.21,0.14,0.16,0.10,0.12))   
#X-squared = 2972.1, df = 6, p-value < 2.2e-16
#卡方值 = 2972.1，p-value < 2.2e-16，p-value < 0.05 
#   表示有足夠證據拒絕 H0，資料集的clarity和期望的clarity分布不相同


#獨立性:鑽石的clarity與鑽石的price是否有關係
#H0 : 鑽石的clarity與鑽石的price無關
#H1 : 鑽石的clarity與鑽石的price有關

chisq.test(table(clarity,price_group)) 

#X-squared = 5907.3, df = 24, p-value < 2.2e-16
#卡方值 = 5907.3，p-value < 2.2e-16，p-value < 0.05 
#   表示有足夠證據拒絕 H0，鑽石的clarity與鑽石的price有關


#同質性:不同carat，對於price是否有差異
#H0 : 不同carat，對於price沒有差異
#H1 : 不同carat，對於price有差異
chisq.test(table(carat_group,price_group))
#X-squared = 40386, df = 4, p-value < 2.2e-16
#卡方值 = 40386，p-value < 2.2e-16，p-value < 0.05 
#   表示有足夠證據拒絕 H0，不同carat，對於price有差異