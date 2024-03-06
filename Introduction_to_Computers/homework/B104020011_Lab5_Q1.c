#include <stdio.h>
#define SIZE 20
void transfer(char input[]){ //傳入輸入的字串
    for(int i=0;input[i]!='\0';i++){ //轉換輸入的字串中的每一個字元，直到輸入的字串結束
        if(input[i]>64 &&input[i]<91){ //字元為大寫，轉換為小寫
            input[i]+=32;
        }
        else if(input[i]>96 && input[i]<123){ //字元為小寫，轉換為大寫
            input[i]-=32;
        }
    }
    printf("Output: %s",input); //輸出轉換後的字串
}

void main(void){
    char input[SIZE]; //input=輸入的字串
    printf("Input: "); //輸入要轉換的字串
    scanf("%s",&input);
    transfer(input); //呼叫transfer函式
}
