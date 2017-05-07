#include <stdio.h>
#include <stdlib.h>

#include "db/api.h"

uint32_t main(uint32_t argc, char **argv)
{
    if (argc != 3) {
        printf("Usage:\n\tvalgrind --leak-check=full ./generate FILE_FROM FILE_TO\n");
        exit(0);
    }

    FILE *in  = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Student student;

    char bin[20] = "01102420391232343456";
    fwrite(bin, sizeof(char), 20, out);

    uint32_t class = 0;
    while(student_read_txt(&student, &class, in))
        student_write_bin(&student, class, out);
    fclose(in);
    fclose(out);

    return 0;

}

