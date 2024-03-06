#include<stdio.h>
int RemoveDuplicates(int data[], int length){ //length:每筆房屋的客戶數
    int count=0;
    for(int i=0; i<length; i++){
        for(int j=i+1; j<length; j++){
            if(data[i]==data[j]){
                data[j]=0;
                //printf("j:%d\n",j);
            }
        }
        if(data[i]!=0){
            count++;
        }
    }
    return count;
}
void main(void){
    int m, n, data[20];	//m:房屋資料數量,data[]:客戶清單
    scanf("%d ",&m) ;
    for (int i=0 ; i<m ; ++i)
    {
        scanf("%d ",&n) ; //n:第i筆房屋的客戶數
        for (int j=0 ; j<n ; ++j)
        {
            scanf("%d",&data[j]) ;
        }
        printf("count %d : %d\n",i+1,RemoveDuplicates(data, n));
    }
}
