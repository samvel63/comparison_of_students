#include <stdio.h>
#include <stdlib.h>

#include "api.h"

/* Student IO */
int student_read_txt(Student *s, FILE *in)
{
    fscanf(in, "%s", s->surname);
    fscanf(in, "%s", s->initials);

    return !feof(in);
}

int student_read_bin(Student *s, FILE *in)
{
    fread(s->surname,  sizeof(char), STR_SIZE, in);
    fread(s->initials, sizeof(char), STR_SIZE, in);

    return !feof(in);
}

void student_write_bin(Student *s, FILE *out)
{
    fwrite(s->surname,  sizeof(char), STR_SIZE, out);
    fwrite(s->initials, sizeof(char), STR_SIZE, out);
}

void student_print(Student *s)
{
    printf("Name: %s %s\n", s->surname, s->initials);

    printf("\n");
}

