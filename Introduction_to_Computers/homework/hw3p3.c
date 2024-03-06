#include <stdio.h>
float power(float base,int expo){ //次方運算函式
    if(expo==0)
    return 1;
    else
    return base*power(base,expo-1); //輸出值不斷乘base，直到expo=0，回傳次方後結果
}
int main(void){
    float base; //base=base
    int expo; //expo=exponent
    printf("Enter two numbers: "); //輸入base、expo
    scanf("%f %d",&base,&expo);
    printf("power(%.2f, %d)= %.2f",base,expo,power(base,expo)); //輸出次方後結果
    return 0;