//B104020011 危湘妤
#include <stdio.h>
#include <string.h>
typedef struct list{
    char data;
    struct list *next;
}List;
List* add(char data){
    List* newnode;//=malloc(sizeof(List));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
List* stringToList(char s[], List* head){
    int i=0; //for-loop count
    head=add(s[0]);
    List* curr=head;
    for(i=1; i<=strlen(s); i++){
        curr->next=add(s[i]);
        curr=curr->next;
    }
    return head;
}

void printList(List *head){
    List* curr=head;
    while( curr!= NULL){
        printf("%c->", curr->next);
        curr=curr->next;
    }
}

int main(){
    List* head=NULL;
    printList(stringToList("abc test", head));
    return 0;
}