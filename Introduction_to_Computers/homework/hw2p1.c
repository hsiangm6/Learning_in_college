#include <stdio.h>
int main(void){
    //declare variable
    //number:the current number input to the program 
    //Largest:the largest number found so far
    int number=0 ,Largest=-1; 
    while(number!=-1){
        printf("Enter a number,-1 to end: "); //enter the current number
        scanf("%d",&number);
        if(number>Largest){
            Largest=number;//if current number is larger than Largest，the current number is the largest number
        }
    }
    if(Largest<0){
        printf("\nNo number was entered.");
    }    
    else{
        printf("\nThe largest number is %d",Largest);
    }
    return 0;
}