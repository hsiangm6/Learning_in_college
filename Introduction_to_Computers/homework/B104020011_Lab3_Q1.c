#include <stdio.h>
//計算冪的function
float expo(float base,float index){ //expo=exponentiation
    if(index>0){ //計算指數大於0的冪
        return(base*expo(base,index-1)); //呼叫expo，讓base再乘以base，直到index不再>0
    }
    else if(index<0){ //計算指數小於0的冪
        return((1/base)*expo(base,index+1)); //呼叫expo，讓1/base再乘以1/base，直到index不再<0
    }
    else{
        return 1; //回傳指數=0的計算結果
    }
}

int main(void){
    float base,index; //base=底數，index=指數
    while(base!=-1||index!=-1){
        printf("enter a base and exp(-1 to stop):"); //輸入底數和指數
        scanf("%f %f",&base,&index);
        if(base==-1&&index==-1){ //如果指數和底數都是-1，則迴圈結束
            break;
        }
        printf("The exponential is: %.2f\n",expo(base,index)); //取到小數第二位的結果。呼叫expo function
    }
    return 0;
}