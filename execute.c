#include <stdio.h>
#include <stdlib.h>

#include "db/api.h"

uint32_t main(uint32_t argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    if (argc != 2) {
        printf("Usage:\n\t./print_cap DB_FILE\n");
        exit(0);
    }

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    if(!is_student_bin(in)) {
        fprintf(stderr, "Incorrect format.\n");
        exit(2);
    }

    uint32_t difference[MAX_CLASSES];
    capacity_classes_load(&difference[0], in);

    for (uint32_t i = 0; i < 11; ++i) {
        if (i + 1 != MAIN_CLASS && difference[i] != 0) {
            if (difference[i] > difference[9])
                fprintf(stdout, "\n%u-й класс больше 10-го на %u\n", i + 1, difference[i] - difference[9]);
            else if (difference[i] < difference[9])
                fprintf(stdout, "\n%u-й класс меньше 10-го на %u\n", i + 1, difference[9] - difference[i]);
            else
                fprintf(stdout, "\n%u-й и 10-й классы имеют одинаковое количество учеников - равное %u.\n", i + 1, difference[9]);
        }
    }
    
    fclose(in);
    return 0;
}

