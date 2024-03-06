//B104020011_危湘妤
//Please write an C program that converts a decimal number into base ( 2 to 8 )
#include <stdio.h>
void main(void){
    int base=0,enter=0, output=0, counter=1;
    printf("Input base number : ");
    scanf("%d",&base);
    if(base<2 || base>8){
        printf("Error, base must be between 2 and 8. Enter correct base number again");
    }
    else{
        printf("Input number : ");
        scanf("%d",&enter);
        if(enter<0){
        printf("Error, the number must > 0. Please enter number again");
        }
        else{
            while(enter/base!=0){
                output+=enter%base*counter;
                enter/=base;
                counter*=10;
            }
            output+=enter*counter;
            printf("Output : %d",output);
        }
    }
    
}
