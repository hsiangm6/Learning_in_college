#include <stdio.h>
int getStep(int n){ //步數運算
    if(n==1){ //當傳入值=1，停止算步數
        return 0;
    }
    else if(n%2==0){ //當傳入值為偶數，使步數+1，再把傳入值帶進下一階段的函式
        return getStep(n/2)+1;
    }
    else if(n%2==1){ //當傳入值為奇數，使步數+1，再把傳入值帶進下一階段的函式
        return getStep(3*n+1)+1;
    }
}
int main(void){
    int n; //n=輸入的數字
    printf("Enter an integer: ");
    scanf("%d",&n);
    printf("Number of steps: %d",getStep(n)); //印出步數
    return 0;
}