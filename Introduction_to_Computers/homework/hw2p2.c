#include <stdio.h>
int main(void){
    //declare variable
    int row,num=1;//row=the quantity of all layers。num=the codename of items
    printf("Enter the number of rows: "); 
    scanf("%d",&row); //enter the quantity of all layers
    printf("\nThe Floyd's triangle: \n");
    for(int i=0;i<row;i++){ //i=layer
        for(int j=0;j<=i;j++){ //j=the number of item on the layer
        printf("%d ",num);
        num++;
        }
        printf("\n");
    }
    return 0;
}