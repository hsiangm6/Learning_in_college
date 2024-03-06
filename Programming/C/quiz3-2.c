//B104020011 危湘妤
/* Please write a C function dbinom() that implements binomial probability mass function to compute the probability of getting exactly k successes in n (success/failure) 
trials with the probability of success p  */
#include <stdio.h>
void combn(int n, int k){
    long long int sum=1;
    int i=0;
    if(k>(n-k)){
        k=n-k;
    }
    for(i=0;i<k;i++){
        sum=sum*(n-i)/(i+1);
    }
    printf("%lld",sum);
}
void main(void){
    combn(100,95);
}