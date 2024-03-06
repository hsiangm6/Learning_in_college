#include <stdio.h>
void main(void){
    int row1=0, column1=0, row2=0, column2=0; //row1=A矩陣的row; column1=A矩陣的column; row2=B矩陣的row; column2=B矩陣的column;
    printf("Enter row and column for the first matrix A: "); //輸入A矩陣的row數、column數
    scanf("%d %d",&row1,&column1);
    printf("\nEnter row and column for the first matrix B: "); //輸入B矩陣的row數、column數
    scanf("%d %d",&row2,&column2);

    int A[5][5]={0}, B[5][5]={0}, matrix[5][5]={0}; //A=A矩陣; B=B矩陣; matrix=矩陣相乘的結果
    printf("\nEnter elements of the first matrix:\n"); //input A matrix
    for(int i=0; i<row1; i++){ 
        printf("Enter row %d:  ",i+1);
        for(int j=0; j<column1; j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nEnter elements of the second matrix:\n"); //input B matrix
    for(int i=0; i<row2; i++){
        printf("Enter row %d:  ",i+1);
        for(int j=0; j<column2; j++){
            scanf("%d",&B[i][j]);
        }
    }

    printf("The resultant matrix of A*B:\n"); //output matrix multiplication result
    for(int i=0; i<row1; i++){
        for(int j=0; j<column2; j++){
            for(int k=0; k<column1; k++){
                matrix[i][j]+=A[i][k]*B[k][j]; //calculate result within the matrix
            }
            printf("%2d ",matrix[i][j]); //print the matrix
        }
        printf("\n");
    }
}
