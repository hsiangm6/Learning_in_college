#include <stdio.h>
int main(void){
    
    //declare variable
    int shape,length,width; 

    printf("��ܷQ�n�L�X���Ϊ��A1������ΡA2���T����:"); 
    scanf("%d", &shape);
    printf("��ܪ���Ϊ��e�M�T���Ϊ���(�e�Τ�����n��):"); //(�e ��)
    scanf("%d %d",&width,&length);
    
    //determine which shape was output
    switch(shape){
        case 1: //output rectangle
            for(int i=0;i<length;i++){ //decide length
                for(int j=0;j<width;j++){ //decide width
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 2: //output triangle
            for(int i=0;i<length;i++){   //i represents the layer of the stars
	            for(int j=0;j<=(length-i);j++){
	                printf(" "); //print the spaces
	            }
	            for(int j=0;j<(2*i+1);j++){
	                printf("*"); //print the stars
	            }
	        printf("\n"); //to the next layer
	        }
            break;
    }
    return 0;
}