#include <stdio.h>
int main(void){

    //declare variable
    int x,y,z,sum=0,average,product,smallest,largest;

    //enter three different integers
    printf("Enter three different integers:"); 
    scanf("%d %d %d",&x,&y,&z); 

    //calculate sum,average,product
    sum+=(x+y+z);
    average=sum/3;
    product=x*y*z;
    
    //make integer x be the mininum and the maximum
    smallest=x;
    largest=x;
    
    //compare integer y and integer z with the maximum and the minimum
    if(y<smallest){
        smallest=y; //be sure that whether y is the minimum in the x,y,and z
    }
    if(y>largest){
        largest=y; //be sure that whether y is the maximum in the x,y,and z
    }
    if(z<smallest){
        smallest=z; //be sure that whether z is the minimum in the x,y,and z
    }
    if(z>largest){
        largest=z; //be sure that whether z is the maximum in the x,y,and z
    }

    //output sum,average,product,smallest,largest
    printf("Sum is %d\n",sum);
    printf("Average is %d\n",average);
    printf("Product is %d\n",product);
    printf("Smallest is %d\n",smallest);
    printf("Largest is %d\n",largest);
    printf("Hello World\n");
    return 0;
}
