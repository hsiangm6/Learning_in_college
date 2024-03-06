//B104020011-危湘妤-comparing prefix sum and suffix sum
#include <stdio.h>
int countPairs(int a[], int length){
    int prefix[10]={0};
    int suffix[10]={0};
    int count=0; //count= the number of pairs
    int i=0, j=0;
    for(i=0; i<length; i++){ //i=the place of prefix/suffix array
        for(j=0; j<=i; j++){ //j=the place of 'a' array
            prefix[i]+=a[j];
            suffix[i]+=a[length-1-j];
        }
    }
    for(i=0; i<length; i++){
        for(j=0; j<length; j++){
            if(prefix[i]==suffix[j]){
                count++;
            }
        }
    }
    return count;
}
int main(void){
    // test data 1
    int a[7] = {1, 2, 4, 5, 3, 9, 3};
    int length1 = sizeof(a) / sizeof(a[0]); // array length
    int result1 = countPairs(a, length1); // call frontback function
    printf("Test 1 have %d pair(s)\n", result1); // output result

    // test data 2
    int b[7] = {3, 6, 2, 1, 4, 5, 2};
    int length2 = sizeof(b) / sizeof(b[0]);
    int result2 = countPairs(b, length2);
    printf("Test 2 have %d pair(s)\n", result2);

    // test data 3
    int c[6] = {3, 5, 1, 4, 1, 10};
    int length3 = sizeof(c) / sizeof(c[0]);
    int result3 = countPairs(c, length3);
    printf("Test 3 have %d pair(s)\n", result3);

    // test data 4
    int d[6] = {1, 1, 1, 1, 1, 1};
    int length4 = sizeof(d) / sizeof(d[0]);
    int result4 = countPairs(d, length4);
    printf("Test 4 have %d pair(s) \n", result4);
    return (0);
}
