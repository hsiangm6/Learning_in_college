#include <stdio.h>
int main(){
    int a=0, b=0, a2=0, b2=0;
    printf("a= "); //enter a
    scanf("%d", &a);
    a2=a;
    printf("b= "); //enter b
    scanf("%d", &b);
    b2=b;
    while(a!=0 && b!=0){
        if(a>=b){ //when a becomes bigger than b, 
            a=a%b;
        }
        else{
            b=b%a;
        }
    }
    if(a!=0){
        printf("gcb(%d, %d)= %d",a2,b2,a);
    }else{
        printf("gcb(%d, %d)= %d",a2,b2,b);
    }
}