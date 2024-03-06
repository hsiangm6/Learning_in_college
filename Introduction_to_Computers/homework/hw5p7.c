#include<stdio.h>
int match(int balls[6], int winballs[7]){
    int count=0,key=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(balls[i]==winballs[j]){
                count++;
            }
        }
        if(balls[i]==winballs[6]){
            key=1;
        }
    }
    if(count==6){
        return 1;
    }
    else if(count==5&&key==1){
        return 2;
    }
    else if(count==5){
        return 3;
    }
    else if(count==4&&key==1){
        return 4;
    }
    else if(count==4){
        return 5;
    }
    else if(count==3&&key==1){
        return 6;
    }
    else if(count==3){
        return 7;
    }
    else if(count==2&&key==1){
        return 8;
    }
    else{
        return 0;
    }
}
void main(void){
    int n = 0, balls[6] = {0}, winballs[7] = {0}, prizes[8] = {0};
	for(int i = 0; i < 6; ++i)
    {
        scanf("%d ",&balls[i]); //客戶投注6個號碼
        //We just view input string as 6 numbers.
	}
	
    scanf("%d ",&n); //對獎號碼期數
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 7; ++j)
        {
            scanf("%d",&winballs[j]); //第n期開獎的六個中獎號碼與特別號
            //We just view input string as 7 numbers.
        }
        int temp = match(balls,winballs);
        if(temp)  //temp != 0
        {
            ++prizes[temp - 1];
        }
    }

    for(int i = 0; i < 8; ++i){
        printf("%d ",prizes[i]); //頭獎到普獎依序八種獎項累計的中獎次數
        if(i != 7){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }  
}