#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include "db/api.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    char bin[20] = "01102420391232343456";
    fread(bin, sizeof(char), 20, in);

    Student student;
    int32_t difference[11];
    for (int i = 0; i < 11; ++i)
        difference[i] = 0;
    int class = 0;
    while(student_read_bin(&student, &class, in))
        difference[class - 1] += 1;
   /* for (int i = 0; i < 11; ++i) {
        printf("%u\n", difference[i]);
    }*/

    for (int i = 0; i < 11; ++i) {
        if (i + 1 != MAIN_CLASS && difference[i] != 0) {
            if (difference[i] > difference[9])
                fprintf(stdout, "\n%d-й класс больше 10-го на %d\n", i + 1, difference[i] - difference[9]);
            else if (difference[i] < difference[9])
                fprintf(stdout, "\n%d-й класс меньше 10-го на %d\n", i + 1, difference[9] - difference[i]);
            else
                fprintf(stdout, "\n%d-й и 10-й классы имеют одинаковое количество учеников - равное %d.\n", i + 1, difference[9]);
        }
    }

    fclose(in);
    return 0;
}