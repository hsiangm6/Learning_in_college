#include <stdio.h>
void main(void){
    int r=0; //r=半徑
    int i=0, j=0;
    printf("r= ");
    scanf("%d",&r);
    for(i=-r; i<=r; i++){ //以(0,0)為圓中心，r*r的迴圈判斷每一格需填空格還是*
        for(j=-r; j<=r; j++){
            if((i*i+j*j)<=r*r){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}