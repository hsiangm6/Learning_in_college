#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

void printList(Node *head);
void freeList(Node *);
void insert_increase_list(Node **head, int val);

int main()
{
    Node *head = NULL;
    Node *temp;
    int data;
    int arr[] = {22, 20, 23, 3, 18, 6, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        int data = arr[i];
        insert_increase_list(&head, data);
    }

    printList(head);
    freeList(head);
    return 0;
}

void freeList(Node *head)
{
    Node *temp;
    for (temp = head; temp != NULL; temp = head)
    {
        head = head->next;
        free(temp);
    }
}

void printList(Node *head)
{
    Node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}

/*TO-DO*/
void insert_increase_list(Node **head, int val)
{
    Node *new_node=(Node*)malloc(sizeof(Node)); // allocate memory for new node
    new_node->data=val;
    new_node->next=NULL;
    if(*head ==NULL ||(*head)->data > val){
        new_node->next=*head;
        *head=new_node;
        return;
    }

    // If the list is empty or the new node is less than the head node, insert at the beginning
    Node *temp=*head;

    // Traverse the list to find the correct position to insert the new node
    while(temp->next!=NULL && temp->next->data<val){ 
        temp=temp->next;
    }
    
    //Insert the new node at the correct position
    new_node->next=temp->next;
    temp->next=new_node; 
}
