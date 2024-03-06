#include<stdio.h>
int SeatChecked(int m, int n,int VIPSeats,int reserved[][2],int check[2]){
    int key=1;
    for(int i=0; i<VIPSeats; i++){
        if(check[0]==reserved[i][0] && check[1]==reserved[i][1]){
            key=0;
        }
        else if(check[0]==reserved[i][0]-1 && check[1]==reserved[i][1]){
            key=0;
        }
        else if(check[0]==reserved[i][0]+1 && check[1]==reserved[i][1]){
            key=0;
        }
        else if(check[0]==reserved[i][0] && check[1]==reserved[i][1]-1){
            key=0;
        }
        else if(check[0]==reserved[i][0] && check[1]==reserved[i][1]+1){
            key=0;
        }
    }
    return key;
    
}
void main(void){
    int m = 0, n = 0, VIPSeats = 1; 
	    //m = the number of row, n = the number of col, VIPSeats =the number of VIP.
	    scanf("%d %d %d ",&m,&n,&VIPSeats);
	
	    int reserved[VIPSeats][2]={0}; //VIPSeats是浮動的，不確定要記憶體要留多大位置，所以c的subscript不能為變數，但c++可以
	    //Contains coordinate of each VIP's seat.
	
	    for(int i= 0; i < VIPSeats; ++i){
            scanf("%d %d",&reserved[i][0],&reserved[i][1]);
	    }
	
	    int num = 0;
	    for(int i= 0; i < m; ++i){
	        for(int j= 0; j < n; ++j){
	            int check[2] = {i,j};
	            if(SeatChecked(m,n,VIPSeats,reserved,check) == 1){
	                ++num;
	            }
	        }
	    }
        printf("%d\n",num);
	
}