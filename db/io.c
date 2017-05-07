#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "api.h"

/* Student IO */
uint32_t student_read_txt(Student *s, uint32_t *class, FILE *in)
{
    fscanf(in, "%63s", s->surname);
    fscanf(in, "%2s", s->initials);
    fscanf(in, " %u ", class);
    return !feof(in);
}

uint32_t student_read_bin(Student *s, uint32_t *class, FILE *in)
{
    fread(s->surname,  sizeof(char), STR_SIZE, in);
    fread(s->initials, sizeof(char), STR_SIZE, in);
    fread(class, sizeof(uint32_t), 1, in);
    return !feof(in);
}

void student_write_bin(Student *s, uint32_t class, FILE *out)
{
    fwrite(s->surname,  sizeof(char), STR_SIZE, out);
    fwrite(s->initials, sizeof(char), STR_SIZE, out);
    fwrite(&class, sizeof(uint32_t), 1, out);
}

void student_print(Student *s, uint32_t class)
{
    printf("%s \t %s %u\n", s->surname, s->initials, class);

    printf("\n");
}

is_student_bin(FILE *in)
{
    char tmp[20];
    char bin[20] = "01102420391232343456";
    fread(tmp, sizeof(char), 20, in);
    for (int i = 0; i < 20; ++i) {
        if (bin[i] != tmp[i])
            return 0;
    }
    return 1;
}

