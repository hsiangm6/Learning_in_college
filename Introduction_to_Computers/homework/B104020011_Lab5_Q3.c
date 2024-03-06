#include <stdio.h>

int key=0; //key=判斷num是否可以被表示成兩個平方相加的開關
void listSumOfTwoSqrt(int num){
    int high=1; //high=max size of square
    key=0; //重新判斷下一個num前，把key關上
    while(high*high<=num){ //計算小於num的最大平方根
        high++;
    }
    for(int i=1; i<high; i++){ 
        for(int j=i+1; j<high; j++){ //設j的初始值為i+1，就不會重複算到交換後的x,y
            if(i*i+j*j==num){ //如果兩個平方值相加為num，則輸出題目要求的算式和字串
                printf("x=%d, y=%d, %d^2+%d^2 = %d\n",i,j,i,j,num);                
                high=j; //利用high縮減迴圈圈數
                key=1; //把判斷的開關打開
                break; //找到兩個平方值，在同一個i的情況下，不會出現第二個j符合答案
            }
        }
    }
    if(key==0){
        printf("Not found.\n"); //迴圈結束後，判斷開關沒有打開，則輸出為「not found」
    }
}

void main(void){
    int num ; //num=輸入值
    do{ 
        printf("please enter a number: "); //輸入num
        scanf("%d",&num);
        listSumOfTwoSqrt(num); //呼叫listSumOfTwoSqrt
    }while(key == 1); //印出Not found時，程式結束
}
