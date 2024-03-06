#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){
	int i;
	for(i = 0; i < size; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");	
}

void merge(int arr[], int l, int m, int r){
    // Create L ← A[l..m] and M ← A[m+1..r]
	int n1 = m - l + 1; //左子樹的number of node
	int n2 = r - m; //右子樹的number of node
	int* L=(int*)malloc(n1 * sizeof(int));
	int* R=(int*)malloc(n2 * sizeof(int));
	for(int i=0; i<n1; i++){  //初始化左子數
		L[i]=arr[l+i];
	}
	for(int j=0; j<n2; j++){  //初始化右子數
		R[j]=arr[m+1+j];
	}

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0; //index of L
	j = 0; //index of R
	k = l; //index of arr[]

	while(i<n1 && j<n2){
		if(L[i]<=R[j]){  //找左子樹和右子樹中哪一個最小，先加進arr
			arr[k]=L[i];
			i++;
		}else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	// When we run out of elements in either L or M,
  	// pick up the remaining elements and put in A[l..r]
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}

	free(L);
	free(R);

}
 
// l is for left index and r is right index of the sub-array of arr to be sorted
// divides the array
void mergeSort(int arr[], int l, int r){ //0, 4, 9
    if(l < r){
        int m = l + (r - l) / 2;
        // Sortfirst and second halves
    	mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r); //arr, 0, 4, 9
    }
}

// https://www.programiz.com/dsa/merge-sort
int main(void){
    int arr[] = {8,4,12,2,6,10,14,1,3,5}; //0~9
    int n = sizeof(arr) / sizeof(arr[0]); //10
    
	printf("Input array: \n");
	printArray(arr, n);
	printf("\n");
	
	mergeSort(arr, 0, n-1); //arr, 0, 9
	
	printf("Array after Merge Sort: \n");
	printArray(arr, n);
	
	return 0;
}
