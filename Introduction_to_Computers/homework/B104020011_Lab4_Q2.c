#include <stdio.h>
unsigned long long int binary(int num){ //binary function:calculate binary equivalent
    while(num>0){
        if(num%2==0){
            return 0+binary(num/2)*10; //recursive到最後一層的num=0就會跳出while，binary()內的數值會成為餘數再一層層帶回去算出二進位制
        }
        else if(num%2==1){
            return 1+binary(num/2)*10;
        }
    }
}
int main(void){
    int num; //num=decimal number
    printf("Enter a decimal number: ");
    scanf("%d",&num);
    printf("The binary equivalent of %d is %llu",num,binary(num)); //呼叫binary function
}