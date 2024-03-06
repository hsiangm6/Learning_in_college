//B104020011-危湘妤 
#include <stdio.h>
int main(){
    char nowLongestChar,testchar; //nowLongestChar=the answer of the char, testchar=String temporarily stored in the test
    int nowMaxLength=1,count=0; //nowMaxLength=the answer of the continuous char length,
    size_t i=0; //i=the index of the now string
    char constr[30]; //constr=continuous string
    printf("Please enter your string: \n");
    scanf("%s",&constr);
    while(constr[i]!='\0'){ //run all string
        testchar=constr[i]; //know whhich char is counted now
        while(constr[i]!='\0'){ //counting now continuous char and length
            if(constr[i]==testchar){
                count++;
            }
            else{
                if(count>nowMaxLength){ //determinie the answer
                    nowMaxLength=count;
                    nowLongestChar=testchar;
                }
                count=0;
                break;
            }

            i++;
        }
    }
    printf("The longest identical character:\'%c\',the length is %d",nowLongestChar,nowMaxLength);
    return 0;
}