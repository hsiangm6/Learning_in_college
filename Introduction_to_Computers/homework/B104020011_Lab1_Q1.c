#include <stdio.h>
int main(void){
    //declare variable
    int x,y,z,min,max;   //min=minimum, max=maximum

     //input three integers
    printf("Please enter three numbers:");
    scanf("%d %d %d",&x,&y,&z);

    //make integer x be the mininum and the maximum
    min=x;
    max=x;

    //compare integer y and integer z with the maximum and the minimum 
    if(y<min){
        min=y;   //be sure that whether y is the minimum in the x,y,and z
    }
    if(y>max){
        max=y;   //be sure that whether y is the maximum in the x,y,and z
    }
    if(z<min){                          
        min=z;   //be sure that whether z is the minimum in the x,y,and z
    }
    if(z>max){
        max=z;   //be sure that whether z is the maximum in the x,y,and z
    }
    
    //output the maximum and the minimum in the x,y,and z
    printf("the max number is %d\n",max);
    printf("the min number is %d\n",min);
    return 0;
}