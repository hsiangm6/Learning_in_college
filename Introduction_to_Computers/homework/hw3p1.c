#include <stdio.h>
int f(int n){ //計算題目要求的函式
    if(n==0){
        return 100; //當n回到0時，回傳值固定為100
    }
    else if(n%2==0){ //計算當n為偶數的f(n)並回傳
        return f(n-1)-n*n+n;
    }
    else if(n%2==1){ //計算當n為奇數的f(n)並回傳
        return f(n-1)+n*n-n;
    }
}
int main(void){
    int n; //n=輸入的數字
    printf("Enter an integer: "); //輸入n
    scanf("%d",&n);
    printf("f(%d) = %d\n",n,f(n)); //印出回傳值
    return 0;
}