#include <stdio.h>
int main(void){
    
    //declare variable
	float score;   

    while(score!=-1){   //(#)
		printf("Please enter the score:");   //enter the score
		scanf("%f",&score);

		if(score==-1){   //if the entered score is -1,the loop should be broken
			break;
		}
		while(score>100|score<0){   //exclude score that is not in the correct range
		    printf("Please re-enter your score:");   //re-enter the score
		    scanf("%f",&score);
		}
		printf("your score:%.2f\n",score);   //output the entered score
		if(score>=60){   //determine whether the score is passed
			printf("pass!\n");
		}
		else{
			printf("failed!\n");
		}
	}
}