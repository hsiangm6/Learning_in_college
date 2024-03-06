//print content of finalExam.dat 

#include <stdio.h>
// For store the score
typedef struct {
char name[50];
int chinese;
int english;
int math;
} Score;

void printScore(FILE *input_file){
    
    // write the tile
    printf("%-10s%-10s%-10s%-10s\n","Name","Chinese","English","Math");

    Score data;
    
    //read data and print
    while(!feof(input_file)){
        fread(&data, sizeof(data), 1,input_file);
        printf("%-10s%-10d%-10d%-10d\n",data.name,data.chinese,data.english,data.math);
    }
}

int main() {
    
    FILE *input_file;
    input_file = fopen("FinalExam.dat", "rb");

    // check if file exist
    if(input_file==NULL){
        printf("Cannot find file.");
    }
    else{
        printScore(input_file);
    }
    
    fclose(input_file);
    return 0;
}

