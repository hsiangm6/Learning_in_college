//B104020011-危湘妤
//"%s %s%-13.1f%-4d%-6.1f%-5d",brand,type,&mpg,&cyl,&disp,&hp
#include <stdio.h>

int main(){
    char brand[20];
    char type[20];
    float mpg=0;
    int cyl=0;
    float disp=0;
    int hp=0;
    int mpg_count=0;

    FILE *car_list1;
    FILE *car_list2;
    FILE *output;

    car_list1=fopen("mtcars/mtcars1.txt","w+");
    car_list2=fopen("mtcars/mtcars2.txt","w+");
    output=fopen("mtcars/mtcars.txt","w+");
    while(!feof(car_list1)){
        fscanf(car_list1,"%s%s",brand,type);
        // if(mpg>=20.0){
        //     mpg_count++;
        // }
        printf("%s %s",brand,type);
        //fprintf(output,"%20s%20s%5.1f%5d%6.1f%4d");
    }
    fclose(car_list1);
    fclose(car_list2);
    fclose(output);
    return 0;
}
