//B104020011-危湘妤 
#include <stdio.h>
int primeNumer(int test){ //know whether test is prime number
    int j=1;
    for(j=1;j<=test/2;j++){
        if(test%j==0){
            return 0;
        }
    }
    
    return 1;
    

}
int main(){
    int num=0;
    printf("n:");
    scanf("%d",&num);
    size_t i=1;
    for(i=3;i<=num/2;i+2){
        if(primeNumer(i)==1){
            if(primeNumer(num-i)==1){
                printf("The max gap of the pairs of primes given n=%d is %d-%d=%d",num,num-i,i,num-i*2);
            }
        }
    }
    //printf("The max gap of the pairs of primes given n=%d is %d-%d=%d",num,large,small,sum);
    return 0;
}