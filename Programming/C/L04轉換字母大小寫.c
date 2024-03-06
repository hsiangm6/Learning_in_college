//B104020011-危湘妤
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20
void element_toUpper(char enter[],char tmp[]){ //convert to uppercase
    int i=0;
    for(i=0; i<strlen(enter); i++){
        tmp[i]=toupper(enter[i]);
    }
    printf("The string after uppercased is: %s",tmp);
}
void element_toLower(char enter[],char tmp[]){ //convert to lowercase
    int i=0;
    for(i=0; i<strlen(enter); i++){
        tmp[i]=tolower(enter[i]);
    }
    printf("The string after lowercased is: %s",tmp);
}
void element_reverse(char enter[],char tmp[]){ //String order is reversed
    int i=0;
    for(i=0; i<strlen(enter); i++){
        tmp[i]=enter[strlen(enter)-1-i];
    }
    printf("When we make your input string reversed: %s", tmp);
}
int main(){
    char enter[SIZE]; //enter=string entered from the begining
    char tmp[SIZE]; //tmp=string exported now
    printf("Enter enter string: ");
    fgets(enter,SIZE,stdin);
    printf("Your input is:%s\n",enter); //repeat your enter
    element_toUpper(enter,tmp); //convert to uppercase
    element_toLower(enter,tmp); //convert to lowercase
    element_reverse(enter,tmp); //String order is reversed
    return 0;
}