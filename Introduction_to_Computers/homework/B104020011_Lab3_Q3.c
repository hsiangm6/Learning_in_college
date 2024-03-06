#include <stdio.h>
void judge(int num){
    int sum=0,rem; //rem=remainder，sum=因數相加
    for(int i=1;i<num;i++){ //輸入值的因數從1~(輸入值-1)篩選
        rem%=i;
        if(rem==0){ //如果輸入值/(2~輸入值-1)的餘數為0，則除數為輸入值的因數，加進sum
            sum+=i;
        }
        rem=num;//讓餘數變回輸入值，重新判斷新的餘數
    }
    if(sum==num){ //判斷輸入值是否為perfect number
        printf("%d is a perfect number.\n",num);
    }
    else{
        printf("%d is not a perfect number.\n",num);
    }
}
int main(void){
    int num;
    while(num!=-1){ //迴圈停止於輸入-1時
        printf("enter a (-1 to stop): "); //輸入需判斷的數值
        scanf("%d",&num);
        if(num==-1){ //如果輸入值為-1，則不用judge計算後判斷
            break;
        }
        judge(num); //呼叫judge function
    }
}
