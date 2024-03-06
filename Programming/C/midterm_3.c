//B104020011-危湘妤 A collection of (sum of consecutive numbers) specifying the sum
#include <stdio.h>
int main(){
    int etr=0; //etr=the number you input
    int i=0,j=0; //the number of loop
    int tmp_sum=0; //temporary summary
    int min=0,max=0; //min=minimum in the set, max=maximum in the set
    int ttl_set=0; //number of total set

    printf("Please enter a number: ");
    scanf("%d",&etr);

    for(i=1; i<=(etr/2); i++){
        min=i;
        tmp_sum=i;
        for(j=i+1;tmp_sum<etr;j++){
            tmp_sum+=j; 
        }
        if(tmp_sum==etr){
            max=j-1;
            printf("%d to %d\n",min,max);
            ttl_set++;
        }
    }

    printf("There are total %d set(s)\n",ttl_set);
    
    return 0;
}