/*B104020011-危湘妤 
判斷字串是否回文(A string is a palindrome if the reverse of the string 
is equal to the original string (e.g. level))*/
#include <string.h>
#include <stdio.h>
void isPalindrome(char etr[]){
    char rev[30]; //rev= the reverse of string
    int i=0, j=strlen(etr); //i=the index of etr, j=string length of etr
    int k=0; //k=the index of the two string being comparing

    //copy reversed etr to rev
    while(etr[i]!='\0'){
        rev[j-1-i]=etr[i];
        i++;
    }
    printf("Reversed \'%s\' is \'%s\'.\n",etr,rev);

    while(etr[k]!='\0'){
        //comparing etr and rev 
        if(etr[k]!=rev[k]){
            printf("\'%s\' is not a palindrome.\n\n",etr);
            break;
        }
        k++;
        if(etr[k]=='\0'){
            printf("\'%s\' is a palindrome.\n\n",etr);
        }
    }
    memset(rev, 0, j); //clear rev array
}
int main(){
    isPalindrome("level");
    isPalindrome("program");
    isPalindrome("anna");
    isPalindrome("try");

    return 0;
}