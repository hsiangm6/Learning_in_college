//Find the specified string in the string
#include <stdio.h>
int indexOf(char string[], char substr[]){
    size_t i=0, j=0; //i=the index of string[] now, j=the index of substr[] now
    int tmpAnswerIndex=-1; //tmpAnswerIndex=temporary answer of index
    while(string[i]!='\0'){
        if(string[i]==substr[j]){ 
            i++;
            j++;
            tmpAnswerIndex=i;
            while(substr[j]!='\0'){
                if(string[i]!=substr[j]){
                    tmpAnswerIndex=-1;
                    j=0;
                    break;
                }
                i++;
                j++;
                if(substr[j]=='\0'){
                    return tmpAnswerIndex;
                }
            }
        }
        i++;
    }
    return tmpAnswerIndex;
}
int main(){
    printf("%d\n",indexOf("Hello. It is me.", "is"));
    printf("%d\n",indexOf("Hello. It is me again.", "ME"));
    return 0;
}