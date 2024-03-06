/*
 Max Heap implementation in c
 */
#include<stdio.h>
#include<stdlib.h>
/*
 Array Implementation of MaxHeap data Structure
 */

int HEAP_SIZE = 20;

struct Heap{
    int *arr;
    int count;
    int capacity; //heap size
    int heap_type; // for min heap , 1 for max heap
};
typedef struct Heap Heap;

Heap *CreateHeap(int capacity,int heap_type);
void insert(Heap *h, int key);
void print(Heap *h);
void heapify_bottom_top(Heap *h,int index);
void heapify_top_bottom(Heap *h, int parent_node);
int PopMax(Heap *h);

int main(){
    int i;
    Heap *heap = CreateHeap(HEAP_SIZE, 1); 
    if( heap == NULL ){
        printf("__Memory Issue____\n");
        return -1;
    }
    
    for(i =9;i>0;i--)
        insert(heap, i);
    
    print(heap);
    
    for(i=9;i>0;i--){
        int temp = PopMax(heap);
        printf("Pop Max : %d\n", temp);
        print(heap);
    }
    return 0;
}

Heap *CreateHeap(int capacity,int heap_type){
    Heap *h = (Heap * ) malloc(sizeof(Heap)); //one is number of heap
    
    //check if memory allocation is fails
    if(h == NULL){
        printf("Memory Error!");
        return NULL;
    }
    h->heap_type = heap_type;
    h->count=0;
    h->capacity = capacity;
    h->arr = (int *) malloc(capacity*sizeof(int)); //size in bytes
    
    //check if allocation succeed
    if ( h->arr == NULL){
        printf("Memory Error!");
        return NULL;
    }
    return h;
}

void insert(Heap *h, int key){
    if( h->count < h->capacity){ //if 現在heap裡的node還未達到完整的heap
        h->arr[h->count] = key;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}
// 從上往下調整堆的性質，將新增的元素進行調整，以確保符合最大堆的性質
void heapify_bottom_top(Heap *h,int index){
    int temp;
    int parent_node = (index-1)/2;
    
    if(h->arr[parent_node] < h->arr[index]){ // 檢查父節點的值是否小於子節點的值。如果是，則交換父節點和子節點的值
        //swap and recursive call
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        // 將父節點的索引作為參數，以便對上層節點進行相同的操作，直到達到堆的頂部
        heapify_bottom_top(h,parent_node);
    }
}
// 從上往下調整堆的性質，確保堆的頂部節點擁有最大（或最小）值
// 如果子節點的值大於（或小於）父節點的值，則交換它們，然後遞迴調用 `heapify_top_bottom` 來繼續調整子節點
void heapify_top_bottom(Heap *h, int parent_node){ 
    // Finish your code here.
    int temp;
    int max_child, left_child, right_child;
    left_child = 2 * parent_node + 1;
    right_child = 2 * parent_node + 2;
    if (left_child < h->count && h->arr[left_child] > h->arr[parent_node]) //比較left_child的值是否大於parent_node的值
        max_child = left_child;
    else
        max_child = parent_node;

    if (right_child < h->count && h->arr[right_child] > h->arr[max_child]) //比較right_child的值是否大於parent_node的值
        max_child = right_child;

    if (max_child != parent_node) { //如果最大的node不是parent_node
        // Swap parent_node with the max_child
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[max_child];
        h->arr[max_child] = temp;

        heapify_top_bottom(h, max_child); //調整交換後的下面節點
    }
}

int PopMax(Heap *h){
    int pop;
    if(h->count==0){
        printf("\n__Heap is Empty__\n");
        return -1;
    }
    // replace first node by last and delete last
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h, 0);
    return pop;
}
void print(Heap *h){
    int i;
    printf("==============Print Heap===============\n");
    if(h->count){
        for(i=0;i< h->count-1;i++){
            printf("%d -> ",h->arr[i]);
        }
        printf("%d\n",h->arr[h->count-1]);
    }
    else
        printf("__Heap is Empty__\n");
}
