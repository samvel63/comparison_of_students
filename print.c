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

    Student student;
    uint32_t class = 0;
    while(student_read_bin(&student, &class, in)) {
        student_print(&student, class);
    }
    printf("\n");
    
    fclose(in);
    return 0;
}

