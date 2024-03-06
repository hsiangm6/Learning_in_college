#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20 //陣列大小
#define	MAX 100 //亂數範圍
#define SWAP(x,y) {int t; t = x; x = y; y = t;}


void genRandomIntArry(int arr[], int sizem, int max);
void printArray(int arr[], int size);
int partition(int[], int, int); 
void quickSort(int[], int, int);

int main(void){
	
    int arr[SIZE] = {0};
    genRandomIntArry(arr, SIZE, MAX);
    

	printf("before sorting\n");
	printArray(arr, SIZE);
	
	// implement the sorting algorithm
	//sorting(arr);
	quickSort(arr, 0, SIZE-1);
	
	
	printf("after sorting\n");
	printArray(arr, SIZE);
	
	return 0;
}


void genRandomIntArry(int arr[], int size, int max){
	int i; //陣列索引
	srand((unsigned)time(NULL)); //產生亂數種子

	//賦予值給陣列
	for(i =0; i< size; i++)
	{
		arr[i] = rand() % max + 1; //指定0~MAX範圍的亂數
	}	
}

void printArray(int arr[], int size){
	int i;
	for (i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");	
}


int partition(int number[], int left, int right) { 
    // Finish your code here.
	// select the leftmost element as pivot
	int pivot=number[left];
	int i=left+1;
	int j=right;
	while(1){
		while(i<=j && number[i]<=pivot){  //find left element that is bigger than pivot
			i++;
		}
		while(j>=i && number[j]>=pivot){ //find right element that is smaller than pivot
			j--;
		}
		if(i>=j){ 
			break;
		}
		SWAP(number[i], number[j]);
	}
	SWAP(number[j], number[left]);
	return j;
}


void quickSort(int number[], int left, int right) { 
    // Finish your code here.
	if(left<right){
		int pivot=partition(number, left, right); //the index of pivot before swap
		quickSort(number, left, pivot-1);
		quickSort(number, pivot+1, right);
	}
	// return;
} 