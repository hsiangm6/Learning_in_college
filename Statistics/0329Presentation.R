test <- read.csv("C:/Users/hsian/Documents/GitHub/Learning_in_college/Statistics/R_statistics/StudentsPerformance.csv")
library(BSDA)
library(dplyr)
library(ggplot2) #ggplot2:https://hackmd.io/@mutolisp/rJAzWj4x4#19-%E5%A4%9A%E5%9C%96%E6%8E%92%E5%88%97facet
#父母教育程度的高低對於平均數學成績是否有差異。(ex:大學以上 vs 大學以下...)
#大學以上:some college, master's degree, bachelor's degree
#大學以下:some high school, high school, associate's degree
#H0:μB - μno_B = 0, H1:μB - μno_B != 0
B_grade <- test %>% select(everything()) %>% 
  filter(parental.level.of.education %in% c("some college", "master's degree", "bachelor's degree"))

no_B_grade <- test %>% select(everything())%>% 
  filter(parental.level.of.education %in% c("some high school", "high school", "associate's degree"))

B_math <- B_grade$math.score #所有父母教育程度大學以上的數學成績
no_B_math <- no_B_grade$math.score #所有父母教育程度大學以下的數學成績

var.test(B_math, no_B_math) #p-value = 0.2931(>0.05)，表示兩組變異數並無顯著差異
#兩組樣本的變異數相等

t.test(B_math, no_B_math,
       alternative = "two.sided",
       paired = FALSE, 
       var.equal = TRUE,
       conf.level = 0.95)

#t = 3.5933, df = 998, p-value = 0.0003424(<0.05)，
#拒絕H0，表示有足夠的證據證明父母教育程度的高低對於平均數學成績有顯著差異

#檢定父母教育程度的高低的數學成績高於60分的比例是否有差異
#H0:PBach - Pno_Bach = 0, H1:PBach - Pno_Bach != 0

B_math_pass <- length(B_math[B_math > 60]) #父母教育程度大學以上的數學成績高於60分
no_B_math_pass <- length(no_B_math[no_B_math > 60]) #父母教育程度大學以下的數學成績高於60分

B_math_num <- length(B_math) #所有父母教育程度大學以上的數學成績
no_B_math_num <- length(no_B_math)   #所有父母教育程度大學以下的數學成績
B_math_num
p <- c(B_math_pass, no_B_math_pass) #兩樣本的p
n <- c(B_math_num,no_B_math_num) #兩樣本的n

prop.test(p, n, alternative = "two.sided", 
          conf.level = 0.95)

#p-value = 0.001642(<0.05)，拒絕H0，
# 表示有足夠證據證明父母教育程度的高低對於數學成績高於60分的比例有顯著差異

#父母教育程度的數學成績分布
test %>%
  ggplot(aes(x = parental.level.of.education, y = math.score, color = parental.level.of.education)) + 
  geom_boxplot()+
  xlab("父母教育程度") + 
  ylab("數學成績")

#父母教育程度大學以上的數學成績分布
B_grade %>%
  ggplot(aes(x = 1:nrow(B_grade), y = math.score)) + 
  geom_boxplot()+
  ggtitle("父母大學以上的數學成績分布") +
  xlab("資料數") + 
  ylab("數學成績")

#父母教育程度大學以下的數學成績分布
no_B_grade %>%
  ggplot(aes(x = 1:nrow(no_B_grade), y = math.score)) + 
  geom_boxplot()+
  ggtitle("父母大學以下的數學成績") +
  xlab("資料數") + 
  ylab("數學成績")

#分為父母教育程度大學以上和以下的數學成績分布
#新增衍生變數mutate():https://bookdown.org/tonykuoyj/eloquentr/dplyr.html, https://bookdown.org/b08302310/R_learning_notes/dplyr.html
#判斷式in mutate(): https://stackoverflow.com/questions/22337394/dplyr-mutate-with-conditional-values
degree_group <- test %>% 
  mutate(degree_group=ifelse(parental.level.of.education=="some college" | parental.level.of.education=="master's degree" | parental.level.of.education=="bachelor's degree", ">=bachelor", "<bachelor"))
#大學以上:some college, master's degree, bachelor's degree
#大學以下:some high school, high school, associate's degree

#父母教育程度大學以上的數學成績分布
degree_group %>%
  ggplot(aes(x = degree_group, y = math.score, color = degree_group)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) +
  stat_summary( #mean number text
    fun.y = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  coord_cartesian(ylim=c(50,80))+ #zoom in
  xlab("父母教育程度") + 
  ylab("數學成績")

#Arrange the rows in a specific sequence:https://www.r-bloggers.com/2022/06/arrange-the-rows-in-a-specific-sequence-in-r/
#Reorder a variable: https://r-graph-gallery.com/267-reorder-a-variable-in-ggplot2.html
#zoom in: http://rstudio-pubs-static.s3.amazonaws.com/209392_437ec4da7fa2432d831320f3591e7491.html
#mean point: https://r-graph-gallery.com/269-ggplot2-boxplot-with-average-value.html
#font size: https://statisticsglobe.com/change-font-size-of-ggplot2-plot-in-r-axis-text-main-title-legend
test %>% 
  #在此mutate()，是為了按照我的指定排序呈現x軸上的分組
  mutate(arr_group=factor(parental.level.of.education, levels=c("some high school", "high school", "associate's degree", "some college", "bachelor's degree", "master's degree"))) %>%
  ggplot(aes(x = arr_group, y = math.score, color = arr_group)) + 
  geom_boxplot()+
  stat_summary(fun=mean, geom="point", shape=20, size=5) + #mean point
  stat_summary( #mean number text
    fun.y = mean, geom = "text", vjust = -1, size = 5,
    aes(label = round(..y.., digits = 2))
  )+
  theme(axis.text.x=element_text(size=15))+ #axis-x label size
  coord_cartesian(ylim=c(50,80))+ #zoom in
  xlab("父母教育程度") + 
  ylab("數學成績")
