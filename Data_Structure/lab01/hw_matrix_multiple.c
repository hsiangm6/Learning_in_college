#include <stdio.h>
#define ROW 4
#define COL 3

int main(void)
{
	int i, j, k, sum;
	int m1[ROW][2] = {{1, 2}, //4*2
					  {3, 4},
					  {5, 6},
					  {7, 8}};
	int m2[2][COL] = {{1, 2, 3}, //2*3
					  {4, 5, 6}};
	int m3[ROW][COL]={0}; //4*3

	/*TO-DO*/
	/*You are given two input matrices, m1 and m2.
	Please implement matrix multiplication.*/
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			m3[i][j]=m1[i][0]*m2[0][j]+m1[i][1]*m2[1][j];
			printf("%4d", m3[i][j]);
		}
		printf("\n");
	}

	return 0;
}