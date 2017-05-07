#include <stdio.h>
#include <stdlib.h>

#include "db/api.h"

int search(FILE *in, Student *s, int class)
{
    uint32_t i = 0, c = 0;
    Student student;
    while(student_read_bin(&student, &c, in)) {
        i++;
        if(!strcmp(s->surname, student.surname) && !strcmp(s->initials, student.initials) && c == class) {
            printf("В списке %u === %s %s %u\n", i, student.surname, student.initials, c);
            rewind(in);
            return 1;
        }
        //if (!(i % 10000))
          //  printf("%d %s %s %d\n", i, student.surname, student.initials, c);
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

    Student student;
    uint32_t class = 0;
    //char s[STR_SIZE];
    while (scanf("%63s %2s %u", student.surname, student.initials, &class) == 3) {
        if (search(in, &student, class))
            printf("READY\n");
        else
            printf("Ooops...\n");
        rewind(in);
        if(!is_student_bin(in)) {
            fprintf(stderr, "Incorrect format.\n");
            exit(2);
        }
    }

    
        
    printf("\n");
    
    fclose(in);
    return 0;
}

