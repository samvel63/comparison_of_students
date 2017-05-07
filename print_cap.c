#include <stdio.h>
#include <stdlib.h>

#include "db/api.h"

uint32_t main(uint32_t argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    if (argc != 2) {
        printf("Usage:\n\t./print DB_FILE\n");
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

    for (uint32_t i = 0; i < MAX_CLASSES; ++i) {
        printf("В %u-ом классе %u человек\n\n", i + 1, difference[i]);
    }
    
    fclose(in);
    return 0;
}

