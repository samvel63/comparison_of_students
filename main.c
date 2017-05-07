#include <stdio.h>
#include <stdlib.h>

#include "db/api.h"

int search(FILE *in, Student *s, int class)
{
    int i = 0, c = 0;
    Student student;
    while(student_read_bin(&student, &c, in)) {
        i++;
        if(!strcmp(s->surname, student.surname) && !strcmp(s->initials, student.initials) && c == class) {
            printf("В списке %d === %s %s %d\n", i, student.surname, student.initials, c);
            return 1;
        }
        if (!(i % 10000))
            printf("%d %s %s %d\n", i, student.surname, student.initials, c);
    }
    return 0;
}

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

    Student s;
    uint32_t class = 0;
    scanf("%63s %2s %u", s.surname, s.initials, &class);
    if (search(in, &s, class))
        printf("READY\n");
    else
        printf("Ooops...\n");
    
        
    printf("\n");
    
    fclose(in);
    return 0;
}

