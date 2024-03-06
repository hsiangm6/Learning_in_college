#include <stdio.h>
#include <math.h>
#define SIZE 99 // 陣列大小

void printArray(int array[]);

int main(void)
{
	// 宣告一個99個元素的整數陣列，數值範圍介於1~9之間
	int values[SIZE] = {6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
						7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
						6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
						7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
						6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
						7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
						5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
						7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
						7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
						4, 5, 6, 1, 6, 5, 7, 8, 7};
	printf("[values]\n");
	printArray(values);
	printf("\n***** Statistical Results *****\n");

	/*TO-DO*/
	float sum=0, mean=0, vir=0, std=0, div, median=0;
	int max=values[0], min=values[0], mode_index=0, mode=0;
	int arr[10]={0};
	for(int i=0; i<SIZE; i++){
		sum+=values[i];
		if(max<values[i]){
			max=values[i];
		}
		if(min>values[i]){
			min=values[i];
		}
		for(int j=1; j<10; j++){
			if(j == values[i]){
				arr[j]++;
				break;
			}
		}
	}
	mean=sum/99;
	//std
	for(int i=0; i<SIZE; i++){
		div=values[i]-mean;
		vir+=pow(div, 2);
	}
	std=sqrt(vir/SIZE);

	//median
	int med_index=0;
	if(SIZE%2==1){
		med_index=(SIZE/2)+1;
		for(int i=1; i<10; i++){
			med_index-=arr[i];
			if(med_index<=0){
				median=i;
				break;
			}
		}
	}
	//mode
	for(int i=1; i<10; i++){
		if(arr[i]>mode_index){
			mode_index=arr[i];
			mode=i;
		}
	}
	
	
	printf("sum: %f, mean: %f, std: %f, max: %d, min:%d, median: %f , mode: %d\n", sum, mean, std, max, min, median, mode);
	return 0;
}

// 將陣列內容在螢幕顯示出來
void printArray(int array[])
{
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
