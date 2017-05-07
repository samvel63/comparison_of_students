#include <stdio.h>
#include <stdlib.h>

#include "db/api.h"

int main(int argc, char **argv)
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
    char bin[20] = "01102420391232343456";
    fread(bin, sizeof(char), 20, in);

    Student student;
    int class = 0;
    while(student_read_bin(&student, &class, in)) {
        student_print(&student, class);
    }
    //table_load_bin(&table, &student, in);
        
    
    //printf("\n\t\t%s\n", table.name);
    //table_print(&table);
    printf("\n");
    
    fclose(in);
    //table_destroy(&table);
    return 0;
}

