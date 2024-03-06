#include <stdio.h>
#define MAX_ERXTICES 8
#define FALSE 0
#define TRUE 1
#define INT_MAX 9999999

void shortestpath(int v, int cost[][MAX_ERXTICES], int distance[], int n, short int found[]);
int choose(int distance[], int n, short int found[]);

void main(){
	// Adjacency Matrix                0        1        2        3        4        5        6        7
	int cost[][MAX_ERXTICES] = {{      0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},	// 0
								{    300,       0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},	// 1
								{    600,     100,       0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},	// 2
								{INT_MAX, INT_MAX,     120,       0, INT_MAX, INT_MAX, INT_MAX, INT_MAX},	// 3
								{INT_MAX, INT_MAX, INT_MAX,    1500,       0,     150, INT_MAX, INT_MAX},	// 4
								{INT_MAX, INT_MAX, INT_MAX,     900, INT_MAX,       0,     700,    1400},	// 5
								{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,       0,     100},	// 6
								{    170, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,       0}};	// 7
								
	int n = MAX_ERXTICES;			// Number of nodes.
	int v = 4;						// Starting vertex.
	int distance[MAX_ERXTICES];		// record the shortest distance.
	short int found[MAX_ERXTICES];	// record the node visited.
					
	shortestpath(v, cost, distance, n, found);
}

void shortestpath(int v, int cost[][MAX_ERXTICES], int distance[], int n, short int found[]){
	int i, u, w;
	int path[MAX_ERXTICES];
	for(i = 0; i < n; i++){
		found[i] = FALSE;
		distance[i] = cost[v][i];
		path[i]=v;
	}
	found[v] = TRUE;
	distance[v] = 0;
	/*-------------------------------------------------
	Hint: Declare the array of shortest path.
	Hint: Using For-loop to set the array.
	Finish your code below.
	---------------------------------------------------*/
	 //
	
	int node;
	
	for(i = 0; i < n - 2; i++){
		u = choose(distance, n, found);
		found[u] = TRUE;
		for(w = 0; w < n; w++){
			if (distance[u] + cost[u][w] < distance[w]){
				distance[w] = distance[u] + cost[u][w];
				/*-----------------------------------------
				Hint: Record the shortest path.
				Finish your code below.
				-------------------------------------------*/
				path[w]=u; //將index w的前一個node是u紀錄在path[]
			}
		}
	}	
	printf("Vertex %d to all shortest distances: ", v);
	for(i = 0; i < MAX_ERXTICES; i++)
		printf("%d ", distance[i]);
	printf("\n");
	/*-------------------------------------------------
	Hint: Using For-loop to print the path.
	Finish your code below.
	---------------------------------------------------*/
	for (i=0; i<MAX_ERXTICES;i++){ 
		node=i;
		while(TRUE){
			printf("%d <- ", node);
			node=path[node];
			if(node==v){
				printf("%d %d", node, distance[i]);
				break;
			}
			
		}
		printf("\n");
	}
	
}

int choose(int distance[], int n, short int found[]){
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i = 0; i < n; i++){
		if (distance[i] < min && !found[i]){
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}
