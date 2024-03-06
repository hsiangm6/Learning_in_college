#include <stdio.h>
int way(int num){ //計算走一步或走兩步到達最高台階的方法數
    if(num<=2){ //當num=剩下台階數=2，其方法數剩2，當num=剩下台階數=1，其方法數=1
        return num;
    }
    else{
        return way(num-1)+way(num-2); //把走1階和走2階的方法數按照巢狀分布相加，最末位巢狀會回到num=1 or 2，再沿著巢狀加回去方法數
    }
}
int main(void){
    int stairs; //stairs=總台階數
    printf("How many stairs? ");
    scanf("%d",&stairs);
    printf("there are %d ways.",way(stairs));
}

