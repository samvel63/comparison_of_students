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
    table_create(&table, "CAPACITY STUDENTS");
    Student student;

    while (student_read_bin(&student, in)) {
        add_student(&table, &student);
        //student_print(&student);
    }
    table_print(&table);
    fclose(in);

    return 0;
}

