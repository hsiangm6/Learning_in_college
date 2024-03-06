//B104020011-危湘妤
#include <stdio.h>

//self-referential structure
typedef struct list{
    char data;
    struct list *nextPtr;
}List;

void printRevList(List *head){
    
}

int main(){
    List a_lst={'a',NULL}, b_lst={'b',NULL}, c_lst={'c',NULL};
    a_lst.nextPtr=&b_lst;
    //printf("%c", *a_lst.nextPtr);
    b_lst.nextPtr=&c_lst;
    //printRevList();
    
    return 0;
}
