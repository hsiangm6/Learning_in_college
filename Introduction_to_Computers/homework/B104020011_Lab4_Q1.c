#include <stdio.h>
int multiply(int a,int b){ //控制a+a+a...+了(b-1)次
    if(b>1){ 
    	b--;
        a+=multiply(a,b); //呼叫multiply，加a到目前的總數
    }
    return a;
}

int main(void){
    int a,b; //a=multiplicand，b=multiplier
    printf("Enter two positive integers:");
    scanf("%d %d",&a,&b);
    while(a!=EOF&&b!=EOF){ //if a=b=-1，break the loop
        printf("The result is %d\n",multiply(a,b));
        printf("Enter two positive integers:");
        scanf("%d %d",&a,&b);
    }
    return 0;
}