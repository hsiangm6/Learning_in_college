#include <stdio.h>
#include <string.h>

#define FILE_COUNT 2

// For store the car data
typedef struct {
    char brand[20];
    char type[20];
    float mpg;
    int cyl;
    float disp;
    int hp;
} Car;

int main(int argc, char** argv) {
    Car test_car;

    FILE *input_file, *output_file;

    char path[FILE_COUNT][30] = {
        "C://mtcars1.txt", "C://mtcars2.txt"};  // The path of the input file
    int car_count = 0;                          // Number of car which mpg > 20

    output_file = fopen("C://Users//user//Desktop//mtcars.txt",
                        "w");  // The output file path

    // write the tile
    printf("%s",
           "brand               type                mpg    cyl disp   hp\n");

    fprintf(output_file, "%s",
            "brand               type                mpg    cyl disp   hp\n");

    // Read file in order
    for (int i = 0; i < FILE_COUNT; i++)
        // check if file exist
        if ((input_file = fopen(path[i], "r")) == NULL)
            printf("Cannot open file\n");
        else {
            fscanf(input_file, "%20s%20s%f%d%f%d", test_car.brand,
                   test_car.type, &test_car.mpg, &test_car.cyl, &test_car.disp,
                   &test_car.hp);

            // do until end of the file
            while (!feof(input_file)) {
                // check if the current line mpg is > 20
                if (test_car.mpg > 20) {
                    printf("%-20s%-20s%-7.1f%-4d%-7.1f%-8d\n", test_car.brand,
                           test_car.type, test_car.mpg, test_car.cyl,
                           test_car.disp, test_car.hp);

                    fprintf(output_file, "%-20s%-20s%-7.1f%-4d%-7.1f%-8d\n",
                            test_car.brand, test_car.type, test_car.mpg,
                            test_car.cyl, test_car.disp, test_car.hp);

                    car_count++;
}

                fscanf(input_file, "%20s%20s%f%d%f%d", test_car.brand,
                       test_car.type, &test_car.mpg, &test_car.cyl,
                       &test_car.disp, &test_car.hp);
            }

            fclose(input_file);
        }

    // Output the counts
    printf("There are %d car(s) whose mpg > 20.\n", car_count);
    fprintf(output_file, "There are %d car(s) whose mpg > 20.\n", car_count);

    fclose(output_file);
}

