#include <stdio.h>
#include <stdlib.h>

#include "db/api.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage:\n\t./generate FILE\n");
        exit(0);
    }

    FILE *in  = fopen(argv[1], "r");
    FILE *out = fopen("db.bin", "w");

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Table table;
    Student student;

    table_create(&table, "CAPACITY STUDENTS");
    table_load_txt(&table, &student, in);
    
    table_save(&table, out);

    table_destroy(&table);    
    fclose(in);
    fclose(out);

    return 0;

}

