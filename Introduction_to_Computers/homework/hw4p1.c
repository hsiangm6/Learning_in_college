#include <stdio.h>

int calculate(char word[]){ //calculate:鑑定輸入的字串是否為triangle number
    int sum=0,i=0; //sum=字串每一字元順序位的加總
    while(word[i]!='\0'){
        sum+=word[i]-96; //字元從ascii碼轉換為字母順序並相加每個字元的順序位
        i++;
    }
    for(int i=1;i<24;i++){
        if(sum==(i*(i+1)/2)){ //如果sum=triangle number，回傳1給主含式，否則回傳0
            return 1;
        }
    }
    return 0;
}

void main(void){
    char word[10]; //word=輸入的字串
    printf("Enter a word: "); //輸入字串
    scanf("%s",&word);
    if(calculate(word)==1){ //回傳值為1，則字串是triangle number
        printf("%s is a triangle word",word);
    }
    else{ //回傳值為0，則字串不是triangle number
        printf("%s is not a triangle word",word);
    }
}

