test <- read.csv("StudentsPerformance.csv")
#install.packages("BSDA")
library(BSDA)
library(dplyr)

#母體平均數檢定(比較兩組樣本的平均值是否有差異)
#一、母體變異數已知：(1.大樣本  2.小樣本) -> z test
#1.大樣本
#調查A校和B校高三學生的平均成績是否有差異(以5%顯著水準進行檢定)
#假設母體標準差皆為5
#H0:μA - μB = 0 , H1:μA - μB != 0

set.seed(123)                                    #設計隨機編號
large_sample1 <- sample(0:100,300,replace = TRUE)  #大樣本(A校)
large_sample2 <- sample(0:100,250,replace = TRUE)  #大樣本(B校)
z.test(x = large_sample1, 
       y = large_sample2, 
       alternative = "two.sided", 
       sigma.x = 5, 
       sigma.y = 5, 
       conf.level = 0.95)

#z = -1.8544, p-value = 0.06368，無法拒絕H0，表示沒有足夠的證據證明兩校的高三學生成績有顯著差異

#2.小樣本
#調查小三學生的平均體重是否小於國三學生的平均體重(以5%顯著水準進行檢定)
#假設母體標準差皆為3
#H0: μ小 - μ中 >= 0，H1: μ小 - μ中 < 0

small_sample1 <- c(41, 35, 33, 36, 40, 46, 31, 37, 34, 30, 38)  #小樣本(小三)
small_sample2 <- c(52, 48, 62, 55, 64, 57, 56, 55, 60, 59, 72)  #小樣本(國三)

#小樣本進行檢定前，需先確認樣本本身是來自"常態分配的資料"

#H0: 資料為常態，H1:資料不為常態
#shapiro.test() -> 常態檢定
#p-value < 0.05，則拒絕H0，表示資料不為常態
#反之，若 > 0.05，則不拒絕H0，表示資料為常態

shapiro.test(small_sample1) #p-value = 0.8922(>0.05) -> 資料為常態
shapiro.test(small_sample2) #p-value = 0.8274(>0.05) -> 資料為常態

z.test(x = small_sample1, 
       y = small_sample2, 
       alternative = "less", 
       sigma.x = 3, 
       sigma.y = 3, 
       conf.level = 0.95)

#z = -16.985, p-value < 2.2e-16，拒絕H0，表示有足夠的證據證明小三學生的平均體重小於國三學生的平均體重

#----------------------------------------------------------------
#二、母體變異數未知 -> t test
#首先使用F檢定來確認兩組樣本的變異數是否相同
#H0: 變異數相同，H1:變異數不相同

#var.test(x,y):F檢定
# p-value > 0.05，不拒絕H0，表示兩組變異數並無顯著差異
# p-value < 0.05，拒絕H0，表示兩組變異數具顯著差異

#1.獨立樣本檢定 (大樣本)
#調查A校和B校高三學生的平均成績是否相同(母體標準差未知，以5%顯著水準進行檢定)
#H0:μA - μB = 0, H1:μA - μB != 0

var.test(large_sample1, large_sample2) #p-value = 0.4231(>0.05)，表示兩組變異數並無顯著差異
#兩組樣本的變異數相等

t.test(large_sample1, large_sample2,
       alternative = "two.sided",
       paired = FALSE, 
       var.equal = TRUE,
       conf.level = 0.95)

#t = -0.32535, df = 548, p-value = 0.745(>0.05)，
#無法拒絕H0，表示沒有足夠的證據證明兩校的高三學生成績有顯著差異

#2.獨立樣本檢定 (小樣本)
#調查小三學生的平均體重是否小於國三學生的平均體重(母體標準差未知，以5%顯著水準進行檢定)
#H0: μ小 >= μ中 = 0, H1:μ小 - μ中 < 0

var.test(small_sample1, small_sample2) #p-value = 0.3333(>0.05)，表示兩組變異數並無顯著差異
#兩組樣本的變異數相等

t.test(small_sample1, small_sample2,
       alternative = "less",
       paired = FALSE, 
       var.equal = TRUE,
       conf.level = 0.95)

#t = -9.0762, df = 20, p-value = 7.865e-09(<0.05)
#拒絕H0，表示有足夠的證據證明小三學生的平均體重小於國三學生的平均體重

#3.成對樣本t檢定:同一樣本檢定
#(小樣本)
#假設今天要檢查一個學生參加課外活動前/後的課業學習成績是否有差異，分數資料如下：
#參加活動前： 90, 87, 98, 98, 96
#參加活動後： 89, 86, 87, 86, 84
c1 <- c(90, 87, 98, 98, 96)
c2 <- c(89, 86, 87, 86, 84)
#H0:μ前 - μ後 = 0, H1:μ前 - μ後 != 0

shapiro.test(c1) #p-value = 0.1863(>0.05) -> 資料為常態
shapiro.test(c2) #p-value = 0.8258(>0.05) -> 資料為常態

var.test(c1, c2) #p-value = 0.07423(>0.05)，表示兩組變異數並無顯著差異

t.test(c1, c2,
       alternative = "two.sided",
       paired = TRUE, 
       var.equal = TRUE,
       conf.level = 0.95)

#t = 2.8253, df = 4, p-value = 0.04757(<0.05)，
#拒絕H0，表示有足夠的證據證明學生參加課外活動前/後的課業學習成績有顯著差異

#(大樣本)
#以下為35名學生前後測的分數，我們想知道學生前後測的成績是否有差異，分數資料如下：
#前測成績： 61, 81, 69, 66, 95, 70, 82, 50, 61, 65, 64, 54, 97, 75, 
#56, 80, 50, 69, 98, 52, 92, 61, 72, 63, 97, 62, 54, 64, 62, 69, 55, 77, 63, 88, 92

#後測成績： 81, 73, 87, 96, 96, 98, 70, 82, 95, 74, 77, 71, 70, 74, 
#76, 70, 78, 80, 86, 80, 81, 80, 97, 83, 82, 79, 99, 94, 99, 77, 78, 56, 91, 57, 80
c3 <- c(61, 81, 69, 66, 95, 70, 82, 50, 61, 65, 64, 54, 97, 75, 
        56, 80, 50, 69, 98, 52, 92, 61, 72, 63, 97, 62, 54, 64, 62, 53, 55, 70, 63, 88, 76)
c4 <- c(81, 73, 87, 96, 96, 98, 70, 82, 95, 74, 77, 71, 70, 74, 
        76, 70, 78, 80, 86, 80, 81, 80, 97, 83, 82, 79, 99, 94, 99, 77, 78, 56, 91, 87, 80)
#H0:μ前 - μ後 = 0, H1:μ前 - μ後 != 0

var.test(c3, c4) #p-value = 0.04553(<0.05)，表示兩組變異數有顯著差異

t.test(c3, c4,
       alternative = "two.sided",
       paired = TRUE, 
       var.equal = FALSE,
       conf.level = 0.95)

#t = -4.223, df = 34, p-value = 0.0001701，拒絕H0，表示有足夠的證據證明學生前後測的成績有顯著差異

#----------------------------------------------------------------
#練習題
#1.假設我們的資料集為"樣本資料"，透過檢定得知男生的數學成績是否真的比女生高?
#H0:μ女 - μ男 >= 0，H1: μ女 - μ男 < 0
f_math <- test$math.score[test$gender =="female"]
m_math <- test$math.score[test$gender =="male"]
var.test(m_math, f_math)
#p-value = 0.09016(>0.05)，表示兩組變異數並無顯著差異

t.test(m_math, f_math,
       alternative = "greater",
       paired = FALSE, 
       var.equal = TRUE,
       conf.level = 0.95)
#t = 5.3832, df = 998, p-value = 4.56e-08，拒絕H0，表示有足夠的證據證明男生的數學成績比女生高





#2.同上，那受到午餐補助的同學閱讀成績是否比沒有受到午餐補助的同學低?
#H0:μ補助 - μ一般 >= 0，H1: μ補助 - μ一般 < 0

var.test(test$reading[test$lunch=='free/reduced'], test$reading[test$lunch=='standard'])
#p-value = 0.1087(>0.05)，表示兩組變異數並無顯著差異

t.test(test$reading[test$lunch=='free/reduced'], test$reading[test$lunch=='standard'],
       alternative = "less",
       paired = FALSE, 
       var.equal = TRUE,
       conf.level = 0.95)
#t = -7.4511, df = 998, p-value = 1.001e-13，拒絕H0，表示有足夠的證據證明受到午餐的同學閱讀成績比沒有受到午餐的同學閱讀成績低




#----------------------------------------------------------------
#三、雙樣本比例檢定(兩個獨立樣本群體的比例是否有其差異)
#若我們想透過檢定男女性的閱讀成績高於60分的比例是否有差異
#H0:P男 - P女 = 0, H1:P男 - P女 != 0

female_data <- test %>% select(everything())  %>% filter(gender == 'female') #女生資料
male_data <- test %>% select(everything())  %>% filter(gender == 'male') #男生資料

p1 <- length(female_data$reading.score[female_data$reading.score > 60]) #女生閱讀成績大於60
p2 <- length(male_data$reading.score[male_data$reading.score > 60]) #男生閱讀成績大於60

n1 <- length(female_data$reading.score) #所有女生閱讀成績
n2 <- length(male_data$reading.score)   #所有男生閱讀成績

p <- c(p1, p2) #兩樣本的p
n <- c(n1,n2) #兩樣本的n

prop.test(p, n, alternative = "two.sided", 
          conf.level = 0.95)

#p-value = 4.687e-10(<0.05)，拒絕H0，表示有足夠證據證明男女性的閱讀成績高於60分的比例有顯著差異

#----------------------------------------------------------------
#練習題
#假設我們的資料集為"樣本資料"，我們想透過檢定得知"group A & group B"的數學成績低於60分的比例是否有差異
#H0:PA - PB = 0, H1:PA - PB != 0

group_A <- test %>% select(everything())  %>% filter(race.ethnicity == 'group A') 
group_B <- test %>% select(everything())  %>% filter(race.ethnicity == 'group B') 

pA <- length(group_A$math.score[group_A$math.score < 60]) #女生閱讀成績大於60
pB <- length(group_B$math.score[group_B$math.score < 60]) #男生閱讀成績大於60

nA <- length(group_A$math.score) #所有女生閱讀成績
nB <- length(group_B$math.score)   #所有男生閱讀成績

P <- c(pA, pB) #兩樣本的p
N <- c(nA,nB) #兩樣本的n

prop.test(P, N, alternative = "two.sided", 
          conf.level = 0.95)

#p-value = 0.1536(>0.05)，不拒絕H0，表示沒有足夠證據證明"group A & group B"的數學成績低於60分的比例有顯著差異



#Test 1
#H0:μgA - μgC = 0, H1:μgA - μgC != 0
gA_data <- test$math.score[test$race.ethnicity == 'group A'] 
gC_data <- test$math.score[test$race.ethnicity == 'group C'] 

var.test(gA_data, gC_data) #p-value = 0.8182(>0.05)，表示兩組變異數並無顯著差異
#兩組樣本的變異數相等

t.test(gA_data, gC_data,
       alternative = "two.sided",
       paired = FALSE, 
       var.equal = TRUE,
       conf.level = 0.95)

#t = -1.5997, df = 406, p-value = 0.1104(>0.05)，
#無法拒絕H0，表示沒有足夠的證據證明"group A & group C"的同學平均數學成績有顯著差異

#Test 2
#H0:PA補助 - P一般 = 0, H1:P補助 - P一般 != 0

free_launch <- test %>% select(everything())  %>% filter(lunch=='free/reduced') 
standard_launch <- test %>% select(everything())  %>% filter(lunch=='standard') 

pF <- length(free_launch$reading.score[free_launch$reading.score > 70]) 
pS <- length(standard_launch$reading.score[standard_launch$reading.score > 70]) 

nF <- length(free_launch$reading.score) 
nS <- length(standard_launch$reading.score)   

Pf <- c(pF, pS) #兩樣本的p
Ns <- c(nF,nS) #兩樣本的n

prop.test(Pf, Ns, alternative = "two.sided", 
          conf.level = 0.95)

#p-value = 4.456e-08(<0.05)，拒絕H0，表示有足夠的證據證明"有無午餐補助"的同學閱讀成績高於70分的比例有差異


