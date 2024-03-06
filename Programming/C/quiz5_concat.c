//B104020011-危湘妤
/* Please write a C function concat(str1, str2, out) that concatenates two given strings, str1 
and str2, and then stores the result into the new variable out. */
#include <stdio.h>
void concat(char str1[], char str2[], char out[]){
    int i=0,j=0; //i=index of out, j=index of str1/str2
    while(str1[j]!='\0'){
        out[i]=str1[j];
        i++;
        j++;
    }
    j=0;
    while(str2[j]!='\0'){
        out[i]=str2[j];
        i++;
        j++;
    }
    printf("The string in the variable \"out\": %s\n",out);
}
int main(){
    char out[40];
    concat("hand", "some", out);
    concat("beauti", "ful", out);
    return 0;
}