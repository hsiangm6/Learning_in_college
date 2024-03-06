#include <stdio.h>

void main(void){
    int arr1[5],arr2[5],intSec[5]={0}; //arr1=第一串輸入的數字，arr2=第二串輸入的數字，intSec=兩串數字有相同元素的陣列
    printf("Enter 5 number for 1st array:\n"); //輸入第一串數字
    for(int i=0; i<5; i++){
        scanf("\n%d",&arr1[i]);
    }
    printf("Enter 5 number for 2st array:\n"); //輸入第二串數字
    for(int i=0; i<5; i++){
        scanf("\n%d",&arr2[i]);
        for(int j=0; j<5; j++){ //每輸入一個第二串數字，都與第一串的每個數字對照是否相同
            if(arr1[j]==arr2[i]){
                intSec[j]=arr1[j]; //有相同數字就丟到intSec裡
            }
        }
    }
    printf("Intersection is { ");
    for(int i=0; i<5; i++){ //印出第一、二串數字中的相同數字
        if(intSec[i]!=0){
            printf("%d ", intSec[i]);
        }
    }
    printf("}");
}
 