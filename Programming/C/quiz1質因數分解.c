//B104020011 危湘妤
//Please write an C program that shows prime factor decomposition. 
#include <stdio.h>
void main(void){
    int a=0, exp=0; //a=輸入的整數，exp=質因數的指數
    int i=0; //i=迴圈的圈數
    printf("Input: ");
    scanf("%d",&a);
    printf("Output: ");
    for(i=2; i<=a; i++){
        exp=0;
            while(a%i==0){ //如果i是a的因數，則a=a/i
                exp++;
                a/=i;
            }
            if(a==1){ //如果a已經是1，則字串後不用再加"*"
            printf("%d^%d\n",i,exp);
            }
            else if(exp>0){
                printf("%d^%d*",i,exp);
            }
    }
}

