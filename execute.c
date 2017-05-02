#include <stdio.h>
#include <stdlib.h>

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

    Student student;
    Table table;
    table_create(&table, "CAPACITY STUDENTS");

    table_load_bin(&table, &student, in);
    print_comprison_of_classes(&table);


    table_destroy(&table);
    fclose(in);
    return 0;
}