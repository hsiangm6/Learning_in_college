#include <stdio.h>
//製作判斷輸入值是否為質數的function
void judge(int num){
    for(int i=2;i<=num-1;i++){ //使輸入值為質數的條件中，沒有1和輸入值
        num%=i;
        if(num==0){ //如果輸入值/(2~輸入值-1)的餘數曾為0，則必不為質數
            printf("此數不是質數\n");
            break;
        }
    }
    if(num!=0){ //如果輸入值/(2~輸入值-1)的餘數不曾為0，則必為質數
        printf("此數是質數\n");
    }
}
int main(void){
    int num; //num=輸入的數值
    while(num!=-1){ //如果輸入值為-1，則迴圈停止
        printf("Please enter a number: "); //輸入需判斷的數值
        scanf("%d",&num);
        if(num==-1){ //如果輸入值為-1，則不用judge計算後判斷
            break;
        }
        judge(num); //呼叫judge function
    }
}