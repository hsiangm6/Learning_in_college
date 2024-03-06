#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100
//use array to produce stack
int stack[MAXSTACK];
int top=-1;
int isEmpty();
void push(int);
int pop();

//use list to produce stack
struct Node{
    int num; //堆疊資料的宣告
    struct Node *next; //堆疊中用來指向下一個節點
};
typedef struct Node Stack_Node; //宣告struct
typedef Stack_Node *Linked_Stack; //將Stack_Node轉換為指標型態
Linked_Stack link_top=NULL; 
int linkIsEmpty();
void linkPush(int);
int linkPop();

int main()
{
    int value;
    int i=0;
    int choose=0;
    printf("Please choose the way of array or list!(1=array, 2=list)\n");
    scanf("%d", &choose);

    if(choose==1){
        printf("請依序輸入3筆資料: \n");
        for(i=0; i<3; i++){
            scanf("%d", &value);
            push(value);
        }
        printf("==============\n");
        while(!isEmpty()){
            printf("堆疊彈出的順序為: %d\n", pop());
        }
        pop();
    }
    else if(choose==2){
        printf("請依序輸入3筆資料: \n");
        for(i=0; i<3; i++){
            scanf("%d", &value);
            linkPush(value);
        }
        printf("==============\n");
        while(!linkIsEmpty()){
            printf("堆疊彈出的順序為: %d\n", linkPop());
        }
        linkPop();
    }
    else{
        printf("It's error");
    }
    
    return 0;
}

/*use array to stack*/
//save pointed value into stack
void push(int value){
    if(top>=MAXSTACK){
        printf("The stack is full.\n");
    }
    else{
        top++;
        stack[top]=value;
    }
}

int isEmpty(){
    if(top==-1){
        return 1; //True
    }else{
        return 0; //False
    }
}

//take value from stack
int pop(){
    int data=0;
    if(isEmpty()){
        printf("The stack is empty.\n");
    }else{
        data=stack[top];
        top--;
        return data;
    }
}

/*use linked list to stack*/
void linkPush(int value){
    Linked_Stack new_add_node; //新加入節點的指標
    
    //配置新結點的記憶體
    new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));
    new_add_node->num=value;
    new_add_node->next=link_top; //將新Node指向stack的top
    printf("%d and %x\n", new_add_node->num, new_add_node->next);
    link_top=new_add_node; //new node 成為stack 的top
}
int linkIsEmpty(){
    if(link_top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//take data from stack
int linkPop(){
    Linked_Stack ptr; //指向堆疊頂端的指標
    int temp;
    if(linkIsEmpty()){
        printf("堆疊為空\n");
        return -1;
    }
    else{
        ptr=link_top; //指向堆疊的頂端
        temp=ptr->num; //取出堆疊資料
        printf("%d\n", link_top->num);
        printf("%x\n", link_top->next);
        link_top=link_top->next;//將堆疊頂端的指標指向下一個節點
        free(ptr); //將節點占用的記憶體釋放
        return temp;
    }
}