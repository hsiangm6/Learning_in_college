#include <stdio.h>
int main(void){
    //宣告變數
    int height,minStar; //height=金字塔的高度, minStar=最小星星數
    printf("Please input the height of pyramid:"); //輸入金字塔的高度
    scanf("%d",&height);
    printf("Please input the min star:"); //輸入最小星星數
    scanf("%d",&minStar);
    
    //迴圈
    for(int i=0;i<height;i+=1){ //i為金字塔從上到下數來第(i+1)層
        for(int j=0;j<(height-i);j+=1){ //印出j個空格，*號前的空格數為height-i
            printf(" ");
        }
        
        for(int j=0;j<minStar;j+=1){ //(*)。印出每層的*，*的數量在第一層必須為minStar
            printf("*");   
        }
        minStar+=2; //因為for迴圈(*)的第一層*數必須為minStar，所以下一層的*數為minStar+2
        printf("\n"); //每印完一層的*就必須到下一行
    }
}
