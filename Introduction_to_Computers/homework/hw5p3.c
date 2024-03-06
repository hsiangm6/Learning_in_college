/*數人數遊戲
有 N 個同學圍成一圈玩遊戲，事先說好輪流抽M張撲克牌(M<N)。

第一位同學抽一張撲克牌，依據撲克牌上的顏色與點數，決定數人數的方向(黑色代表逆時針而紅色代表順時針方向)與數量。

下圖為N =10位同學抽M=3張撲克牌的例子，第一位同學抽中紅心K (A=1、J=11、Q=12、K =13)，代表從第一個同學順時針方向數起，第13個人會被淘汰；接著，第一個淘汰者往順時針方向的下一位同學再抽牌，第二張抽中梅花A
，代表從這位同學開始逆時針方向數起，也就是自己會是被淘汰者；接著往逆時針方向的下一位同學再抽第三張牌(即最後一輪)，最後一張牌抽中黑桃6，代表從這位同學開始逆時針方向數起第6人(即7號同學)是勝利者。

依此類推，如此反覆抽牌決定每次數人數的方向與數量，到第M 張也就是最後一張牌抽出後，被數到的人就是此次遊戲的勝利者。
主程式將持續呼叫WhoOut()函式，以淘汰學生直至最後一輪找到獲勝學生為止。

輸入格式 

N ：開始學生人數，其中N 為整數，2≤N ≤100
M：抽撲克牌次數，其中M 為整數，M<N
f1c1：第一次抽取撲克牌的顏色（B代表黑色、R代表紅色）與點數(1-13)
f2c2：第二次抽取撲克牌的顏色與點數 
...
f McM：第M次抽取撲克牌的顏色與點數 


輸出格式 

s1：第一位被淘汰的學生編號 
...
sM-1：第M-1位被淘汰的學生編號
sM：獲勝者編號 


需要完成及繳交的函式：
int WhoOut(int students[], int N, char color, int point) 函式

students 學生狀態，students[i]=1，代表此學生已淘汰。
N 學生人數。
color 撲克牌顏色，傳入字元紅色(R)或黑色(B)。紅色代表順時針、黑色代表逆時針。
point 撲克牌點數(1-13)。
此函式計算並回傳該輪被淘汰或獲勝學生的編號。
int WhoOut(int students[], int N, char color, int point) {
          // 請完成並繳交本函式
}



範例測資1

輸入

5
3
R13
R10
B2

輸出

3
5
4

範例測資2

輸入

6
4
R1
R2
B1
B2

輸出

1
3
4
6*/

/*
01　	#include <iostream>
02　	using namespace std;
03　	
04　	int start_id = 0; // 紀錄每一回合從哪個學生開始
05　	
06　	int WhoOut(int students[], int N, char color, int point) {
07	        (作答區，雖然其他程式碼是C++，但作答區請打C)
08　	}
09　	
10　	int main() {
11　	    int N = 0; // 學生人數
12　	    int M = 0; // 抽撲克牌次數
13　	    int students[100] = {}; // 紀錄學生狀態
14　	    int outList[100] = {}; // 紀錄每次淘汰的學生
15　	    
16　	    cin >> N >> M;
17　	
18　	    if (M > N) {
19　	        printf("error occur");
20　	    }
21　	    else {
22　	        char color; // 顏色
23　	        int point = 0; // 點數
24　	        for (int i=0; i<M; i++) {
25　	            cin >> color >> point;
26　	            outList[i] = WhoOut(students, N, color, point);
27　	            students[outList[i]-1] = 1; // 紀錄此學生已被淘汰/獲勝
28　	        }
29　	        for (int i=0; i<M; i++) {
30　	            printf("%d\n", outList[i]);
31　	        }
32　	    }
33　	    return 0;
34　	}
35　	*/
#include <stdio.h>

int start_id = 0; // 紀錄每一回合從哪個學生開始

int WhoOut(int students[], int N, char color, int point) {

    int count=0;
    int last_id=start_id;//last_id:這一輪的淘汰者或勝利者

    if(color=='R'||color=='r'){ //R是順時針
        last_id+=(point-1); //+間隔數而不是+抽到的數值，因為start_id是計算順位的第一位
        if(last_id<(N-1)){ //計算後的位置在總人數內，計算這一段經過多少應被跳過的順位，並且不用轉換超出總人數的順位。N要注意以陣列的位置符去思考
            for(int i=start_id; i<=last_id;i++){
                if(students[i]==1){
                    count++;
                }
            }
        }
        while(last_id>(N-1)){//計算後的位置在總人數外，計算這一段經過多少應被跳過的順位，並且要轉換超出總人數的順位。N要注意以陣列的位置符去思考
            last_id-=N;
            for(int i=start_id; i<N;i++) {//計算從這一輪的開始順位到最大順位，經過多少應被跳過的順位
                if(students[i]==1){
                count++;
                }
            }
            if(last_id>(N-1)){ //如果轉換後還是超出順位，就必須再轉換一次超出總人數的順位，並且計算從0順位到這一輪開始的順位，經過多少應被跳過的順位
                for(int i=0; i<=start_id;i++){
                    if(students[i]==1){
                        count++;
                    }
                }
            }
            else{ //如果轉換後沒有超出順位，計算從0順位到這一輪結束的順位，經過多少應被跳過的順位
                for(int i=0; i<=last_id;i++){
                    if(students[i]==1){
                        count++;
                    }
                }
            }
            
        }
        if(count!=0){ //如果count不=0，讓count成為recursive的point，重新交給WhoOut加總及判斷，直到count=0。如果不用recursive，而是直接last_id+count，可能在這過程中又遇到需跳過的順位卻並沒有再加上去
            start_id=last_id+1;
            while(students[start_id]==1){ //為了防止下一輪的開始順位其實是前幾輪已經被淘汰的順位
                start_id++;
            }
            return WhoOut(students, N, color, count);
        }
        else{//如果沒有了應該跳過的順位，輸出現在的last_id
            start_id=last_id+1;
            while(students[start_id]==1){ //為了防止下一輪的開始順位其實是前幾輪已經被淘汰的順位
                start_id++;
            }
            return last_id+1; //last_id是依照陣列的順位，所以輸出時必須加1，變成從1開始的一般順位
        }
    }

    else if(color=='B'||color=='b'){
        last_id=last_id-point+1;
        if(last_id>=0){
            for(int i=start_id; i>=last_id;i--){ //計算從這一輪的開始順位到最小順位，經過多少應被跳過的順位
                if(students[i]==1){
                    count++;
                }
            }
        }
        while(last_id<0){
            last_id+=N; //低於0的順位轉換為陣列的順位
            for(int i=start_id; i>=0; i--){ //計算從這一輪的開始順位到最小順位，經過多少應被跳過的順位
                if(students[i]==1){
                    count++;
                }
            }
            if(last_id<0){ //如果轉換後順位還是小於0，就必須再轉換一次小於0的順位，並且計算從這一輪開始的順位到0順位，經過多少應被跳過的順位
                for(int i=start_id; i<N;i++){
                    if(students[i]==1){
                        count++;
                    }
                }
            }
            else{ //如果轉換後沒有小於0順位，計算從0順位到這一輪結束的順位，經過多少應被跳過的順位
                for(int i=last_id; i<N;i++){
                    if(students[i]==1){
                        count++;
                    }
                }
            }

        }
        if(count!=0){
            start_id=last_id-1;
            while(students[start_id]==1){
                start_id--;
            }
            return WhoOut(students, N, color, count);
        }
        else{
            start_id=last_id-1;
            while(students[start_id]==1){
                start_id--;
            }
            return last_id+1; //last_id是依照陣列的順位，所以輸出時必須加1，變成從1開始的一般順位
        }
    }
}

int main() {
    int N = 0; // 學生人數
    int M = 0; // 抽撲克牌次數
    int students[100] = {0}; // 紀錄學生狀態
    int outList[100] = {0}; // 紀錄每次淘汰的學生
    
    scanf("%d\n %d",&N,&M);
    if (M > N) {
        printf("error occur");
    }
    else {
        char color; // 顏色
        int point = 0; // 點數
        for (int i=0; i<M; i++) {
            scanf(" %c%d",&color, &point);
            outList[i] = WhoOut(students, N, color, point);
            students[outList[i]-1] = 1; // 紀錄此學生已被淘汰/獲勝
        }
        for (int i=0; i<M; i++) {
	        printf("%d\n", outList[i]);
	    }
    }
    return 0;
}
