/*輕鬆選課法
剛成為大一新鮮人的王小明要開始選課了，他想把課程全部排在三天內，其他時間去打工與參加社團。因此他先列出三天內可以選的課程清單，決定使用以下規則輕鬆選課：                                         

從第一天開始挑選，挑選完後，再挑選下一天的課程。
依照當天課程之下課節次排序，先挑選最早下課者（如有相同下課時間的課程，則選擇英文字母排序較前者， 例如：A為2-3節，B為1-3節，會選擇A）。
每日盡可能把課程排滿。
課程時間不可重疊。
同一天不會有重複的課程名稱，且相同課程在三天內只能挑選一次。
第一天選的課程是A、C (B的時間與A重疊、D的時間與C 重疊)
第二天選的課程是B、D(A選過了，E的時間與D 重疊)
第三天選的課程是F   (C選過了，E的時間與F 重疊)



輸入格式
未排序的課程清單

N：共有幾筆資料輸入，其中N 為整數，3≤N ≤36
d1  c1  s1  e1：天(1-3) 課程名稱(A-L) 課程開始節次(1-7) 課程結束節次(2-8)
d2  c2  s2  e2：天(1-3) 課程名稱(A-L) 課程開始節次(1-7) 課程結束節次(2-8)
...
dn  cn  sn  en：天(1-3) 課程名稱(A-L) 課程開始節次(1-7) 課程結束節次(2-8)


輸出格式

d1  c1  s1  e1
d2  c2  s2  e2
...
dn  cn  sn  en


需要完成及繳交的函式：
void SelectCourse(Course results[], int *rs, bool selected[], Course candidates[], int cs) 函式

results 選課結果。
rs 選課結果（ results ）數量。
selected 紀錄課程是否被選過，未選過則紀錄false，已選過則紀錄true。
candidates 每日可選課程。
cs 每日可選課程（ candidates ）數量
此函式計算並更新選課結果( results )，同時更新rs 及selected 。
void SelectCourse(Course results[], int *rs, bool selected[], Course candidates[], int cs){
          // 請完成並繳交本函式
}



範例測資1

輸入

11
2 D 5 7
3 C 2 3
1 C 5 6
2 E 7 8
1 B 2 4
2 A 5 6
3 E 5 7
1 D 6 8
1 A 1 2
3 F 5 6
2 B 1 4

輸出

1 A 1 2
1 C 5 6
2 B 1 4
2 D 5 7
3 F 5 6

範例測資2

輸入

10
1 A 1 3
1 B 3 6
1 C 5 7
2 A 2 4
2 B 5 7
2 E 3 5
3 B 6 8
3 D 3 5
3 C 4 6
3 F 5 7

輸出

1 A 1 3
1 C 5 7
2 E 3 5
3 D 3 5
3 B 6 8*/
/*
01　	#include<iostream>
02　	#include<algorithm>
03　	
04　	using namespace std;
05　	struct course { // 課程
06　	    int day;
07　	    char name;
08　	    int start;
09　	    int end;
10　	};
11　	typedef struct course Course;
12　	
13　	void SelectCourse(Course results[], int *rs, bool selected[], Course candidates[], int cs) {
14	        (作答區，雖然其他程式碼是C++，但作答區請打C)
15　	}
16　	
17　	int main() {
18　	    Course allcourse[36] = {0}, results[36] = {0}; // 所有課程、選課結果
19　	    int n = 0; // 所有課程數量
20　	    int rs = 0; // 紀錄選課數量（results）
21　	    bool selected[12] = {false}; // 紀錄已選過的課
22　	    
23　	    cin >> n;
24　	    for (int i=0; i<n; i+=1) { // 輸入課程
25　	        cin >> allcourse[i].day >> allcourse[i].name >> allcourse[i].start >> allcourse[i].end;
26　	    }
27　	    
28　	    for (int days = 1; days <= 3; days+=1) {
29　	         Course candidates[12] = {0};
30　	         int cs = 0; // 紀錄candidates有多少
31　	         for (int i = 0; i < n; i+=1) {
32　	             if (allcourse[i].day == days) {
33　	                 candidates[cs] = allcourse[i];
34　	                 cs += 1;
35　	             }
36　	         }
37　	
38　	         SelectCourse(results, &rs, selected, candidates, cs);
39　	    }
40　	
41　	    for(int i = 0; i < rs; ++i) {
42　	        cout << results[i].day << " " << results[i].name << " " << results[i].start << " " << results[i].end << endl;
43　	    }
44　	    return 0;
45　	}
46　	*/