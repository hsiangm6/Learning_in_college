//B104020011 危湘妤
#include <stdio.h>
#include <math.h>
long long int combn(int n, int k){
    long long int sum=1;
    int i=0;
    if(k>(n-k)){
        k=n-k;
    }
    for(i=0;i<k;i++){
        sum=sum*(n-i)/(i+1);
    }
    return sum;
}
double dbinom(int k, int n, double p){
    return combn(n,k)*pow(p,k)*pow(1-p,n-k);
}
void main(void){
    printf("%f",dbinom(5,10,0.3));
}