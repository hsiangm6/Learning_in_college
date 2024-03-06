library(ggplot2)
library(dplyr)
library(stats)

#function for goodness of fit test
g_test <- function(o, e){ #o=觀察值, e=期望值
  chi <- sum((o-e)^2/e)
  df <- length(o)-1
  p_value <- 1 - round(pchisq(chi, df), 4) #pchisq():
  print(paste("卡方值:", chi, ", ", "df:", df, ", ", "p-value:", p_value))
}

#卡方適合度檢定
#主要使用於抽樣一組(次)的樣本
#H0 : 資料分配符合期望值(1-6出現機率一樣)
#H1 : 資料分配不符合期望值
#想知道這顆骰子是不是公正的，因此我們檢查骰子出現1到6的機率是不是都是1/6
set.seed(11) 
x <- sample.int(6,size = 600,replace = T) #600次，出現1~6的數值
x
t <- table(x) #表格
t
names(t) #表格中的元素:[1] "1" "2" "3" "4" "5" "6"
as.numeric(t) #各元素的出現次數:[1]  94 101 106  97 105  97

# 繪製長條圖
d = as.data.frame(t)
d
ggplot(data.frame(d), aes(x=x, y=Freq)) + geom_bar(stat="identity")

#Use your own function
g_test(t, 100)#期望值=100
#"卡方值: 1.16 ,  df: 5 ,  p-value: 0.9487"

chisq.test(t)  #X-squared = 1.16, df = 5, p-value = 0.9487
#卡方值 = 1.16，p-value = 0.9487，p-value > 0.05 所以沒有足夠證據拒絕 H0，表示這顆骰子是公正的(符合期望值)

#假如我們想要知道特定的機率(分佈)，也可以在chisq.test函數裡面調整
#數字1出現的機率為 0.1，而數字2出現的機率為 0.2 , 而其他的機率為... 
chisq.test(t, p = c(0.1,0.2,0.3,0.2,0.1,0.1)) #機率加起來=1，不可放<=0的數
#X-squared = 113.67, df = 5, p-value < 2.2e-16
#卡方值 = 113.67，p-value < 2.2e-16，p-value < 0.05 所以有足夠證據拒絕 H0，表示這顆骰子不符合期望值(分布)

#----------------------------------------------------------------
#卡方獨立性檢定
#主要使用於抽樣兩組(次)與兩組(次)以上的樣本
#假設今天抽取學校600名大一到大四學生，看看他們對學校教學的滿意度(1-3)為何
#並且看看不同年級的學生與滿意度是否有相關
set.seed(111)
s = sample.int(4,size = 600,replace = T)
s #大一到大四
t_s = table(s)
d_s = as.data.frame(t_s)
d_s
ggplot(data.frame(d_s), aes(x=s, y=Freq)) + geom_bar(stat="identity")
#滿意程度
sa = sample.int(3,size = 600,replace = T)
sa
satisfaction = ifelse(sa == 1,"不滿意", ifelse(sa == 2,"普通","滿意"))
satisfaction
t_sa = table(satisfaction)
d_sa = as.data.frame(t_sa)
d_sa
ggplot(data.frame(d_sa), aes(x=satisfaction, y=Freq)) + geom_bar(stat="identity")

#建立列聯表
s_sa = table(factor(s), satisfaction)#大一大二的是數字，要換成類別資料，所以用factor()
s_sa

#H0 : 學生年級和滿意度彼此獨立(無關)
#H1 : 學生年級和滿意度彼此不獨立(有關)

chisq.test(s_sa)  #X-squared = 8.0466, df = 6, p-value = 0.2347
#卡方值 = 8.0466，p-value = 0.2347，p-value > 0.05 
#所以沒有足夠證據拒絕 H0，表示學生年級和教學滿意度是無關的(獨立的)

#----------------------------------------------------------------
#卡方同質性檢定
#主要使用於抽樣兩組(次)與兩組(次)以上的樣本
#假設我們想知道不同性別，眼睛的狀況是否有差異
#同樣，生200組樣本，分別是性別以及眼睛的狀況(近視、遠視和視力正常)
#性別
set.seed(22)
s1 = sample.int(2,size = 200,replace = T) #男生&女生
sex = ifelse(s1 == 1,"male","female")
sex
t_sex = table(sex)
d_sex = as.data.frame(t_sex)
d_sex
ggplot(data.frame(d_sex), aes(x=sex, y=Freq)) + geom_bar(stat="identity")
#眼睛的狀況
s2 = sample.int(3,size = 200,replace = T)
status = ifelse(s2 == 1,"近視", ifelse(sa == 2,"遠視","正常"))
status
t_status = table(status)
d_status = as.data.frame(t_status)
d_status
ggplot(data.frame(d_status), aes(x=status, y=Freq)) + geom_bar(stat="identity")

#建立列聯表
s_t = table(sex,status)
s_t

#H0 : 男女生的眼睛狀態沒有差異
#H1 : 男女生的眼睛狀態有差異

chisq.test(s_t) #X-squared = 0.66928, df = 2, p-value = 0.7156
#卡方值 = 0.66928，p-value = 0.7156，p-value > 0.05 
#所以沒有足夠證據拒絕 H0，表示不同性別的眼睛狀態是沒有差異的

#----------------------------------------------------------------
#用我們的資料集試試看!
#卡方適合度檢定
#看看資料集中性別的分布是否有差異(1:1)
#H0 : 男女分布相同
#H1 : 男女分布不相同
test <- read.csv("student-mat.csv")
#資料集來源:https://www.kaggle.com/datasets/uciml/student-alcohol-consumption
str(test)

ggplot(data.frame(test$sex), aes(test$sex)) + geom_bar()
table(test$sex)
chisq.test(table(test$sex))  #X-squared = 1.1165, df = 1, p-value = 0.2907
#卡方值 = 1.1165，p-value = 0.2907，p-value > 0.05 所以沒有足夠證據拒絕 H0，表示男女的分布是相同的

#看看資料集中男女的分布是不是(2:1)
#H0 : 男女分布相同(符合)
#H1 : 男女分布不相同(不符)
chisq.test(table(test$sex), p = c(1/3,2/3))   
#X-squared = 66.381, df = 1, p-value = 3.717e-16
#卡方值 = 66.381，p-value = 3.717e-16，p-value < 0.05 表示有足夠證據拒絕 H0，男女的分布不是2:1

#----------------------------------------------------------------
#練習題
#1.看看資料集中家庭教育支持的分布是否有差異(1:1)
#H0 : 家庭教育支持的分布相同
#H1 : 家庭教育支持的分布不相同
test <- read.csv("student-mat.csv")
#資料集來源:https://www.kaggle.com/datasets/uciml/student-alcohol-consumption
str(test)

ggplot(data.frame(test$famsup), aes(test$famsup)) + geom_bar()
table(test$famsup)
chisq.test(table(test$famsup))  #X-squared = 20.053, df = 1, p-value = 7.532e-06
#卡方值 = 20.053，p-value = 7.532e-06，p-value < 0.05 所以有足夠證據拒絕 H0，表示家庭教育支持的分布是不同的


#看看資料集中有無家庭教育支持的分布是不是符合比例(3:2)
#H0 : 有無家庭教育支持的相同(符合)
#H1 : 有無家庭教育支持的不相同(不符)
chisq.test(table(test$famsup), p = c(2/5,3/5))   
#X-squared = 0.26371, df = 1, p-value = 0.6076
#卡方值 = 0.26371，p-value = 0.6076，p-value > 0.05 表示沒有足夠證據拒絕 H0，有無家庭教育補助的分布是3:2





#----------------------------------------------------------------
#卡方獨立性檢定
#假如想知道母親的教育程度與孩子的最終成績(G3)是否有關係?
#H0 : 母親的教育程度與孩子的最終成績無關
#H1 : 母親的教育程度與孩子的最終成績有關
Q <- quantile(test$G3) #返回最小值、第一分位數、中位數、第三分位數、最大值
Q

test <- test %>% 
  mutate(grade_group = case_when(
    G3 <= 11 ~ "1",
    G3 > 11  ~ "2"
  ),
  # Convert to factor
  grade_group = factor(
    grade_group,
    level = c("2", "1")
  )
  )
test$grade_group
test$Medu = factor(test$Medu)
a = table(test$Medu,test$grade_group)
a
chisq.test(a) 
#X-squared = 17.463, df = 4, p-value = 0.001571
#卡方值 = 17.463，p-value = 0.001571，p-value < 0.05 
#所以有足夠證據拒絕 H0，表示母親的教育程度與孩子的最終成績有關

#當我們的資料是一個2*2的列聯表，且樣本很小、或列聯表中有小於5的值時可以使用(較精準
#fisher.test(...)

#----------------------------------------------------------------
#卡方同質性檢定
#假如想知道不同性別，對於"想接受更高教育的意願"是否有差異?
#H0 : 男女生想接受更高教育的意願沒有差異
#H1 : 男女生想接受更高教育的意願有差異
table(test$sex,test$higher)  
fisher.test(table(test$sex,test$higher))  #p-value = 0.004554
#p-value < 0.05，所以有足夠證據拒絕 H0，表示不同性別想接受更高教育的意願有差異

#----------------------------------------------------------------
#練習題
#2.資料集中性別和閱讀時間是否有關係?
#H0 : 性別和閱讀時間無關
#H1 : 性別和閱讀時間有關

test$sex
test$studytime = factor(test$studytime)
a = table(test$sex,test$studytime)
a
chisq.test(a) 
#X-squared = 50.634, df = 3, p-value = 5.854e-11
#卡方值 = 50.634，p-value = 5.854e-11，p-value < 0.05 
#所以有足夠證據拒絕 H0，表示性別和閱讀時間有關







#----------------------------------------------------------------
#考試
#1.請用卡方檢定檢驗資料集中"有無"上幼兒園是否符合3:1的比例?(結果須附上bot plot和列出table)
#H0 : "有無"上幼兒園的相同(符合)
#H1 : "有無"上幼兒園的不相同(不符合)
test <- read.csv("student-mat.csv")
#資料集來源:https://www.kaggle.com/datasets/uciml/student-alcohol-consumption
str(test)

ggplot(data.frame(test$nursery), aes(test$nursery)) + geom_bar()
table(test$nursery)
chisq.test(table(test$nursery), p = c(1/4,3/4))  
#X-squared = 4.254, df = 1, p-value = 0.03916
#卡方值 = 4.254，p-value = 0.03916，p-value < 0.05 
#   所以有足夠證據拒絕 H0，表示"有無"上幼兒園的分布不是3:1

#2.假如想知道父母同居狀態與家庭人數是否有關連?(結果須附上table)
#H0 : 父母同居狀態與家庭人數無關
#H1 : 父母同居狀態與家庭人數有關

test$famsize
test$Pstatus
a = table(test$Pstatus,test$famsize)
a
chisq.test(a) 
#X-squared = 7.7921, df = 1, p-value = 0.005248
#卡方值 =7.7921，p-value = 0.005248，p-value < 0.05 
#所以有足夠證據拒絕 H0，表示父母同居狀態與家庭人數有關