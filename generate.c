#include <stdio.h>
#include <stdlib.h>

#include "db/api.h"

uint32_t main(uint32_t argc, char **argv)
{
    if (argc != 4) {
        printf("Usage:\n\t./generate FILE_FROM FILE_TO\n");
        exit(0);
    }

    FILE *in  = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    FILE *count = fopen(argv[3], "w");

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Student student;

    char bin[20] = "01102420391232343456";
    fwrite(bin, sizeof(char), 20, out);
    fwrite(bin, sizeof(char), 20, count);

    uint32_t difference[MAX_CLASSES];
    for (int i = 0; i < MAX_CLASSES; ++i) {
        difference[i] = 0;
    }

    uint32_t class = 0;
    for (int i = 1; i <= MAX_CLASSES; ++i) {
        while(student_read_txt(&student, &class, in)) {
            if (class == i) {
                student_write_bin(&student, class, out);
                difference[class - 1]++;
            }
        }
        rewind(in);
    }

    capacity_classes_save(&difference[0], count);

    fclose(in);
    fclose(out);
    fclose(count);
    return 0;

}

