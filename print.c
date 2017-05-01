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

    Table table;
    Student student;
    table_create(&table, "CAPACITY STUDENTS");

    table_load_bin(&table, &student, in);
    table_print(&table);
    
    fclose(in);
    return 0;
}

