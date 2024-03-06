//B104020011-危湘妤 
#include <stdio.h>
void reverse(char str[]){
    if(*str!='\0'){
        reverse(str+1); // call the next word before the letters in front are printed
        printf("%c",*str);
    }
}
int main(){
    reverse("first");
    return 0;
}