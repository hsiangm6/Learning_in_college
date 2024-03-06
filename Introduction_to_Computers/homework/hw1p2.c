#include <stdio.h>
int main(void){
    
    //declare variable
    int number; //number=entered number
    int sum=0; //sum=sum of digit

    //enter number
    printf("Enter a number: "); 
    scanf("%d",&number);

    //calculate the sum of digits of the number
    while(number>0){
        sum+=number%10; //sum adds the last digit of the number
        number/=10; //delete the last digit of the number
    }
    
    //output  sum
    printf("Sum of digits: %d",sum);
    return 0;
}