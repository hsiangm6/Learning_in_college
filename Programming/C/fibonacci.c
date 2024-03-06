#include <stdio.h>
void main(void){
    int fn1=0,fn2=1,fn=1;
    int i;
    printf("Please enter your Fibonacci number: "); //輸入費式數列的長度
    scanf("%d",&fn);
    printf("F1 = %d\n",1);
    for(i=2;i<=fn;i++){
        int t = fn1+fn2; //設立fn1+fn2的暫存器
        fn1=fn2;
        fn2=t;
        printf("F%d = %d\n",i,t);
    }
}
