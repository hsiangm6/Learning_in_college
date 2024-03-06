//B104020011-危湘妤
//count the number of the word
#include <stdio.h>
int wordCount(char *string){
    int i=0;
    int count=0; //count = the number of the words
    for(i=0; string[i]!='\0';i++){
        if((string[i]>='A'&& string[i]<='Z') || (string[i]>='a'&& string[i]<='z')){
            //if string[i+1] is not the English alphabet, we know the end of a word
            if((string[i+1]<'A'|| string[i+1]>'Z') && (string[i+1]<'a'|| string[i+1]>'z')){
                count++;
            }
            else{
                continue;
            }
        }
    }
    return count;
}
int main(){
    char str[ ] = "There are 6 words in this string.";
    printf("Total %d words.\n", wordCount(str));
    return 0;
}