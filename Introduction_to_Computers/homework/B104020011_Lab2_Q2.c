#include <stdio.h>
int main(void){
	
    //delare variable
    int i,j;

	for(i=0;i<10;i++){   //i represents the layer of the stars
	    for(j=0;j<=(10-i);j++){
	        printf(" "); //print the spaces
	    }
	    for(j=0;j<(2*i+1);j++){
	        printf("*"); //print the stars
	    }
	    printf("\n"); //to the next layer
	}
    for(i=9;i>=0;i--){ //print inverted triangle stars
	    for(j=0;j<=(10-i);j++){
	        printf(" ");
	    }
	    for(j=0;j<(2*i+1);j++){
	        printf("*");
	    }
	    printf("\n");
	}
	return 0;
}
