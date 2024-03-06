#include <stdio.h>
void compare(char string1[], char string2[]){ //傳入第一和第二串字串
    int count=0;
    for(int i=0;count<2;i++){ //迴圈持續到其中一字串結束
        if(string1[i]=='\0' || string2[i]=='\0'){
            count++;
        }
        if(string1[i] != string2[i]){ //如果有兩字串有一字元不同，判定為不同的兩字串
            printf("they are different string.\n");
            return;
        }  
    }
    printf("they are same string\n");
    return;
}

void main(void){
    char string1[10], string2[10]; //string1=輸入的第一串字串，string2=輸入的第二串字串
    int i=0;
    while(i<2 ){ //持續迴圈2次
        i++;
        printf("enter a string1: ");
        scanf("%s",&string1);
        printf("enter a string2: ");
        scanf("%s",&string2);
        compare(string1, string2); //呼叫compare函式
    }
}
