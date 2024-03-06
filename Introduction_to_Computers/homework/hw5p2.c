/*發票兌獎
頭獎 20萬 8位數字相同
二獎 4萬 末7位數字相同
三獎 1萬 末6位數字相同
四獎 4千 末5位數字相同
五獎 1千 末4位數字相同
六獎 2百 末3位數字相同

一張發票若同時符合2個獎項，則獎金以最高獎金為主，例如發票號碼同時符合五獎及六獎，則以五獎判定。
對獎主程式將呼叫WinPrize()函式以計算並回傳一張發票的中獎金額，據以統計全部發票的中獎總金額。

輸入格式

W：頭獎號碼，其中W為8碼字串
N：發票總數，其中N為整數， 1≤N≤20
P1: 第一張發票
...
PN: 第N 張發票

輸出格式

M: 中獎總金額


需要完成及繳交的函式：
int WinPrize (char W[], char P[]) 函式

W 頭獎發票號碼，其長度始終為8，內容為0到9
P 發票號碼，其長度始終為8，內容為0到9
此函式計算並回傳發票中獎金額。
int WinPrize (char W[], char P[]) {
          // 請完成並繳交本函式
}



範例測資1

輸入

13859285
3
38592769
42893285
32398733

輸出

200

範例測資2

輸入

39384729
4
93859284
38494729
39472859
39485739

輸出

1000
*/
/*
01　	#include <iostream>
02　	using namespace std;
03　	
04　	int WinPrize (char W[], char P[]) {
05	        (作答區，雖然其他程式碼是C++，但作答區請打C)
06　	}
07　	
08　	
09　	int main() {
10　	    char W[9] = {}; // 頭獎號碼
11　	    char P[9] = {}; // 發票號碼
12　	    int N = 0; // 發票總數
13　	    int M = 0; // 中獎總金額
14　	
15　	    cin >> W;
16　	    cin >> N;
17　	    for (int i=0; i<N; i++) {
18　	        cin >> P;
19　	        M += WinPrize(W, P);
20　	    }
21　	
22　	    cout << M << endl;
23　	    return 0;
24　	}
25　	*/

#include<stdio.h>
int WinPrize(char W[], char P[]){ //檢測一張發票的中獎金額
    int count=0, i=7;
    while(P[i]==W[i]){ //從末位開始往前計算有多少相同的發票號碼，遇到不相同的號碼，迴圈就直接停止
        count++;
        i--;
    }
    switch(count){
        case 8:
            return 200000;
        case 7:
            return 40000;
        case 6:
            return 10000;
        case 5:
            return 4000;
        case 4:
            return 1000;
        case 3:
            return 200;
        default:
            return 0;
    }
}
void main(void){
    char W[9]; //頭獎號碼
    char P[9]; //發票號碼
    int N=0; //發票總數
    int M=0; //發票總金額
    scanf("%s",&W);
    scanf("%d",&N);
    for(int i=0;i<N;i++){ //每張發票中獎金額加總
        scanf("%s",&P);
        M+=WinPrize(W, P);
    }
    printf("%d", M);
}
