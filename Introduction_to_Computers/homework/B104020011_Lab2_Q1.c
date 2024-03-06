#include <stdio.h>
int main(void){
    //declare variable
    int num,rev,remain; //num=number, rev=reverse, remain=現在num的最後一位
    printf("Enter a number:"); //輸入number
    scanf("%d",&num);
    
    while(num!=0){
    	remain=num%10; //取出現在num的最後一位
    	rev+=remain; //把remain移到reverse
    	num/=10; //把num的最後一位去掉
    	if(num>0){ //當num還有數字，把reverse的數乗10
			rev*=10;
		}
	}
	printf("The number with its reverse:%d",rev); //印出reverse後的數
    return 0;
}