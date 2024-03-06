//B104020011-危湘妤
#include <stdio.h>
#include <string.h>
void freqTrans(char str[]){
    int i=0, j=0; //i=the index of the test group;  j=the index of the compare group
    int count=1, max_count=0; //count frequency
    char fre_tran[3]; //the last answer string
    char now_str1[3]; //the string of the test group
    char now_str2[3]; //the string of the compare group
    for(i=0; i<strlen(str)-2; i++){
        now_str1[0]=str[i]; 
        now_str1[1]=str[i+1];

        for(j=i+1; j<strlen(str)-1; j++){
            now_str2[0]=str[j]; 
            now_str2[1]=str[j+1];
            printf("str1:%c%c\n",now_str1[0],now_str1[1]);
            printf("str2:%c%c\n",now_str2[0],now_str2[1]);
            if(strcmp(now_str1,now_str2)==0){ //compare now_str1 and now_str2
                count++;
                printf("count:%d\n",count);
            }
        }
        if(count>max_count){ //check whether count is bigger than max_count 
            max_count=count;
            fre_tran[0]=now_str1[0];
            fre_tran[1]=now_str1[1];
        }
        count=1;
    }
    printf("%c -> %c, Frequency: %d.\n",fre_tran[0],fre_tran[1],max_count);
}

int main(){
    freqTrans("abbab");
    freqTrans("abbacacacc");
    return 0;
}
