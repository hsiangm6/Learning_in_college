library(dplyr)
library(ggplot2)
#read the file
data <- read.csv("C:/Users/hsian/Documents/GitHub/Learning_in_college/Statistics/R_statistics/StudentPockeyMoneyInSunYatSen.csv")
View(data)
class(data)
column_names <- colnames(data)
print(column_names)

#家庭網路購物頻率
data$家庭網路購物頻率 <- factor(data$家庭網路購物頻率)

ggplot(data, aes(x = 家庭網路購物頻率, y = 目前一個月.的零用金.全部.有多少呢.....單位..新台幣, group=家庭網路購物頻率, color=家庭網路購物頻率)) +
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) +
  stat_summary( #mean number text
    fun.y = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  xlab("家庭網路購物頻率") + 
  ylab("一個月的全部零用金")

shopping_frequency_group <- data%>%
  mutate(家庭網路購物頻率分組=factor(data$家庭網路購物頻率, levels=0:7, labels=c("0", "1", "2", "3", "4", "5", "6", "7")))
shopping_frequency_result <- shopping_frequency_group%>%
  group_by(家庭網路購物頻率分組)%>%
  summarise(mean=mean(目前一個月.的零用金.全部.有多少呢.....單位..新台幣))
print(shopping_frequency_result)  
print(table(shopping_frequency_group$家庭網路購物頻率分組))

#星座
# 零用金金額由"父"決定的父親星座的零用錢平均
dad_decision_money<- data%>%
  filter(您的家庭所提供零用金的金額主要是由誰所決定.=="父")
nrow(dad_decision_money) #資料數:52
dad_constellation_result <- dad_decision_money%>%
  group_by(父母星座..父.)%>%
  summarise(mean=mean(目前一個月.的零用金.全部.有多少呢.....單位..新台幣))
print(dad_constellation_result)
#零用金金額由"母"決定的母親星座的零用錢平均
mom_decision_money<- data%>%
  filter(您的家庭所提供零用金的金額主要是由誰所決定.=="母")
nrow(mom_decision_money) #資料數:41
mom_constellation_result <- mom_decision_money%>%
  group_by(父母星座..母.)%>%
  summarise(mean=mean(目前一個月.的零用金.全部.有多少呢.....單位..新台幣))
print(mom_constellation_result)
#零用金金額由"根據您的要求"決定的自己星座的零用錢平均
self_decision_money<- data%>%
  filter(您的家庭所提供零用金的金額主要是由誰所決定.=="根據您的要求")
nrow(self_decision_money) #資料數:51
self_constellation_result <- self_decision_money%>%
  group_by(父母星座..自己.)%>%
  summarise(mean=mean(目前一個月.的零用金.全部.有多少呢.....單位..新台幣))
print(self_constellation_result)

ggplot()+
  geom_point(data=dad_constellation_result, aes(x=父母星座..父., y=mean, group = 1, color = "blue"))+
  geom_point(data=mom_constellation_result, aes(x=父母星座..母., y=mean, group = 2, color = "red"))+
  geom_point(data=self_constellation_result, aes(x=父母星座..自己., y=mean, group = 3, color = "green"))+
  labs(title = "父、母、自己決定金額下，不同星座的零用金金額平均", x = "星座", y = "平均值", color = "類別") +
  scale_color_manual(values = c("blue", "red", "green"), labels = c("父", "母", "自己"))

ggplot() +
  geom_col(data = dad_constellation_result, aes(x = 父母星座..父., y = mean, fill = "父"), alpha = 0.5, position = "dodge") +
  geom_col(data = mom_constellation_result, aes(x = 父母星座..母., y = mean, fill = "母"), alpha = 0.5, position = "dodge") +
  geom_col(data = self_constellation_result, aes(x = 父母星座..自己., y = mean, fill = "自己"), alpha = 0.5, position = "dodge") +
  labs(title = "父、母、自己決定金額下，不同星座的零用金金額平均", x = "星座", y = "平均值", fill = "類別") +
  scale_fill_manual(values = c("父" = "blue", "母" = "red", "自己" = "green"))

#"家庭成員喜歡.擅長的運動"
baseball <- data%>%
  filter(grepl("棒球", 家庭成員喜歡.擅長的運動))
nrow(baseball) #40
basketball <- data%>%
  filter(grepl("籃球", 家庭成員喜歡.擅長的運動))
nrow(basketball) #59
badminton <- data%>%
  filter(grepl("羽球", 家庭成員喜歡.擅長的運動))
nrow(badminton) #64
horsemanship <- data%>%
  filter(grepl("馬術", 家庭成員喜歡.擅長的運動))
nrow(horsemanship) #0
fencing <- data%>%
  filter(grepl("擊劍", 家庭成員喜歡.擅長的運動))
nrow(fencing) #1
swimming <- data%>%
  filter(grepl("游泳", 家庭成員喜歡.擅長的運動))
nrow(swimming) #32
golf <- data%>%
  filter(grepl("高爾夫球", 家庭成員喜歡.擅長的運動))
nrow(golf) #13
tennis <- data%>%
  filter(grepl("網球", 家庭成員喜歡.擅長的運動))
nrow(tennis) #9
racing_car <- data%>%
  filter(grepl("賽車", 家庭成員喜歡.擅長的運動))
nrow(racing_car) #5
light_boat <- data%>%
  filter(grepl("輕艇", 家庭成員喜歡.擅長的運動))
nrow(light_boat) #0
none <- data%>%
  filter(grepl("無", 家庭成員喜歡.擅長的運動))
nrow(none) #116

# 建立資料框
sport <- data.frame(
  Category = c("棒球", "籃球", "羽球", "游泳", "高爾夫球", "網球", "賽車", "無"),
  Value = c(
    mean(baseball$目前一個月.的零用金.全部.有多少呢.....單位..新台幣),
    mean(basketball$目前一個月.的零用金.全部.有多少呢.....單位..新台幣),
    mean(badminton$目前一個月.的零用金.全部.有多少呢.....單位..新台幣),
    mean(swimming$目前一個月.的零用金.全部.有多少呢.....單位..新台幣),
    mean(golf$目前一個月.的零用金.全部.有多少呢.....單位..新台幣),
    mean(tennis$目前一個月.的零用金.全部.有多少呢.....單位..新台幣),
    mean(racing_car$目前一個月.的零用金.全部.有多少呢.....單位..新台幣),
    mean(none$目前一個月.的零用金.全部.有多少呢.....單位..新台幣)
  )
)

# 繪製盒狀圖
ggplot(sport, aes(x = Category, y = Value, fill=Category)) +
  geom_bar(stat = "identity") + #, fill = "steelblue"
  labs(x = "運動類別", y = "目前一個月的平均零用金（新台幣）") +
  ggtitle("運動類別與零用金的關係")
