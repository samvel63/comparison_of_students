#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db/api.h"

int main(int argc, char **argv)
{
	FILE *in = fopen(argv[1], "r");

    if (argc != 2) {
        printf("Usage:\n\t./delete DB_FILE\n");
        exit(0);
    }

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Student student;
    Table table;
    table_create(&table, "CAPACITY STUDENTS");

    table_load_bin(&table, &student, in);
    fclose(in);

    FILE *out = fopen(argv[1], "w");

    char s[7];
    int class = 0;
    while (1) {
    	scanf("%6s", s);
    	if (!strcmp(s, "delete") || !strcmp(s, "del")) {
    		scanf("%64s %2s %d", student.surname, student.initials, &class);
    		delete_student(&table, &student, class);
    	} else if (!strcmp(s, "add") || !strcmp(s, "a")) {
    		scanf("%64s %2s %d", student.surname, student.initials, &class);
    		add_student(&table, &student, class);
    	} else if (!strcmp(s, "print") || !strcmp(s, "p")) {
    		table_print(&table);
    	} else if (!strcmp(s, "save") || !strcmp(s, "s")) {
    		printf("\n\nDB save in %s\n\n", argv[1]);
    		table_save(&table, out);
    		table_destroy(&table);
    		break;
    	}
    }

    fclose(out);
    return 0;
}