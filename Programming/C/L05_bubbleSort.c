//B104020011-危湘妤
#include <stdio.h>
void swap(int *a, int *b){ //swap elements
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void bubble_sort(int arr[],int arrSize){ //comparing
    int i=0,j=0,k=0;
    
    for(i=0;i<arrSize;i++){ //ouput the origin array
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(i=0; i<arrSize-1; i++){
        for(j=i+1; j<arrSize; j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
        for(k=0;k<arrSize;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
    }
}
int main(){
    int arrSize=0; //the size of array
    int arr[20];
    int i=0;

    printf("Enter the size of array: ");
    scanf("%d",&arrSize);

    for(i=0; i<arrSize; i++){
        printf("array[%d] = ", i);
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,arrSize);
    return 0;
}