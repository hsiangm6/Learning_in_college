//adjust original score to 10*pow(original_score, 0.5) and write to new file()
#include <stdio.h>
#include <math.h>
// For store the score
typedef struct {
char name[50];
int chinese;
int english;
int math;
} Score;

//print original score
void printScore(FILE *input_file){
    
    Score data;
    // write the tile
    printf("Original score :\n\n");
    printf("%-10s%-10s%-10s%-10s\n","Name","Chinese","English","Math");

    //read data and print
    while(fread(&data, sizeof(data), 1,input_file)){
        //fread(&data, sizeof(data), 1,input_file);
        printf("%-10s%-10d%-10d%-10d\n",data.name,data.chinese,data.english,data.math);
    }
}

//print adjusted score and write to the created new file
void adjustScore(FILE *input_file , FILE *input_file_adj){
    Score data;
    // write the tile
    printf("\nAdjusted score :\n\n");
    printf("%-10s%-10s%-10s%-10s\n","Name","Chinese","English","Math");

    //read input_file data and print
    while(fread(&data, sizeof(data), 1,input_file)){
        
        data.chinese=10*pow(data.chinese,0.5);
        data.english=10*pow(data.english,0.5);
        data.math=10*pow(data.math,0.5);
        fwrite(&data,sizeof(data),1,input_file_adj);
        printf("%-10s%-10d%-10d%-10d\n",data.name,data.chinese,data.english,data.math);
    }

    rewind(input_file_adj);//bring current location back to the beginning of the text

    //try whether new data is written to the FinalExam_adjusted.dat
    printf("\ntry the content in FinalExam_adjusted.dat :\n");
    //read input_file_adj data and print
    while(fread(&data, sizeof(data), 1,input_file_adj)){
        printf("%-10s%-10d%-10d%-10d\n",data.name,data.chinese,data.english,data.math);
    }
};

int main() {
    
    FILE *input_file;
    FILE *input_file_adj;
    input_file = fopen("FinalExam.dat", "rb");
    input_file_adj=fopen("FinalExam_adjusted.dat", "wb+");

    // check if file exist
    if(input_file==NULL){
        printf("Cannot find file.");
    }
    else{
        printScore(input_file);
        rewind(input_file);
        adjustScore(input_file, input_file_adj);
    }
    
    fclose(input_file);
    fclose(input_file_adj);
    return 0;
}

