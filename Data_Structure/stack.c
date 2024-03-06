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
    int num; //���|��ƪ��ŧi
    struct Node *next; //���|���Ψӫ��V�U�@�Ӹ`�I
};
typedef struct Node Stack_Node; //�ŧistruct
typedef Stack_Node *Linked_Stack; //�NStack_Node�ഫ�����Ы��A
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
        printf("�Ш̧ǿ�J3�����: \n");
        for(i=0; i<3; i++){
            scanf("%d", &value);
            push(value);
        }
        printf("==============\n");
        while(!isEmpty()){
            printf("���|�u�X�����Ǭ�: %d\n", pop());
        }
        pop();
    }
    else if(choose==2){
        printf("�Ш̧ǿ�J3�����: \n");
        for(i=0; i<3; i++){
            scanf("%d", &value);
            linkPush(value);
        }
        printf("==============\n");
        while(!linkIsEmpty()){
            printf("���|�u�X�����Ǭ�: %d\n", linkPop());
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
    Linked_Stack new_add_node; //�s�[�J�`�I������
    
    //�t�m�s���I���O����
    new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));
    new_add_node->num=value;
    new_add_node->next=link_top; //�N�sNode���Vstack��top
    printf("%d and %x\n", new_add_node->num, new_add_node->next);
    link_top=new_add_node; //new node ����stack ��top
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
    Linked_Stack ptr; //���V���|���ݪ�����
    int temp;
    if(linkIsEmpty()){
        printf("���|����\n");
        return -1;
    }
    else{
        ptr=link_top; //���V���|������
        temp=ptr->num; //���X���|���
        printf("%d\n", link_top->num);
        printf("%x\n", link_top->next);
        link_top=link_top->next;//�N���|���ݪ����Ы��V�U�@�Ӹ`�I
        free(ptr); //�N�`�I�e�Ϊ��O��������
        return temp;
    }
}