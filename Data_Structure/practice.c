#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int);
int dequeue();

void display();

typedef struct Node{
    int num;
    struct Node *link;
}Node;

// typedef struct Node Node;
typedef Node *LinkedNode;


int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    display();

    dequeue();

    display();

    return 0;
}

void enqueue(int value){
    if(rear==MAX-1){
        printf("\nQueue is full");
    }else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=value;
        printf("\n Inserted -> %d", value);
    }
}

int dequeue(){
    if(front==-1 || front>rear){
        printf("\nQueue is empty");
    }else{
        printf("\nDelete : %d", queue[front]);
        front+=1;
    }
}

void display(){

}