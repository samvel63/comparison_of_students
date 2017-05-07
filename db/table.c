#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "api.h"

void table_create(Table *table, const char *name)
{
	strncpy(table->name, name, STR_SIZE);
	table->classes = (Class *)malloc(MAX_CLASSES * sizeof(Class));
    for (int i = 0; i < MAX_CLASSES; ++i) {
        table->classes[i].students = (Student *)malloc(0);
        table->classes[i].capacity = 0;
    }
}

void table_destroy(Table *table)
{
    for (int i = 0; i < MAX_CLASSES; ++i)
            free(table->classes[i].students);
	free(table->classes);
}

void table_load_txt(Table *table, Student *student, FILE *in)
{
    int class = 0;
    while (student_read_txt(student, in)) {
        fscanf(in, "%d", &class);
        add_student(table, student, class);
    }
}

int table_load_bin(Table *table, Student *student, FILE *in)
{
    char true[20] = "01102420391232343456";
    char bin[20];
    fread(bin, sizeof(char), 20, in);
    for (int i = 0; i < 20; ++i) {
        if (bin[i] != true[i])
            return -1;
    }
    int class = 0;
    while (student_read_bin(student, in)) {
        fread(&class, sizeof(int), 1, in);
        add_student(table, student, class);        
    }
    return 0;
}

void table_save(Table *table, FILE *out)
{
    char bin[20] = "01102420391232343456";
    fwrite(bin, sizeof(char), 20, out);
    for (int i = 1; i <= MAX_CLASSES; ++i) {
        for (int j = 0; j < table->classes[i - 1].capacity; ++j) {
            student_write_bin(&(table->classes[i - 1].students[j]), out);
            fwrite(&i, sizeof(int), 1, out);
        }
    }
}

void add_student(Table *table, Student *student, int class)
{
    table->classes[class - 1].students = (Student *)realloc(table->classes[class - 1].students, (table->classes[class - 1].capacity + 1) * sizeof(Student));

    strncpy(table->classes[class - 1].students[table->classes[class - 1].capacity].surname, student->surname, STR_SIZE);
    strncpy(table->classes[class - 1].students[table->classes[class - 1].capacity].initials, student->initials, STR_SIZE);
    table->classes[class - 1].capacity++;
}

int delete_student(Table *table, Student *student, int class)
{
    for (int i = 0; i < table->classes[class - 1].capacity; ++i) {
        if (!strcmp(table->classes[class - 1].students[i].surname, student->surname) && !strcmp(table->classes[class - 1].students[i].initials, student->initials)) {
            for (int j = i; j < table->classes[class - 1].capacity - 1; ++j)
                memcpy(&table->classes[class - 1].students[j], &table->classes[class - 1].students[j + 1], sizeof(Student));
            table->classes[class - 1].capacity--;
            table->classes[class - 1].students = (Student *)realloc(table->classes[class - 1].students, (table->classes[class - 1].capacity + 1) * sizeof(Student));
            return DELETE_SUCCESS;
        }
    }
    return DELETE_ERROR;
}

void table_print(Table *table)
{
    printf("Number \t Surname \t Initials \t Class\n");
    int num = 1;
    for (int i = 0; i < MAX_CLASSES; ++i) {
        for (int j = 0; j < table->classes[i].capacity; ++j) {
            printf("%d \t %s \t    %s \t\t %d\n", num, table->classes[i].students[j].surname, table->classes[i].students[j].initials, i + 1);
            ++num;
        }
    }
}

void print_comprison_of_classes(Table *table)
{
    for (int i = 0; i < MAX_CLASSES; ++i) {
        if (i + 1 != MAIN_CLASS && table->classes[i].capacity != 0) {
            if (table->classes[i].capacity > table->classes[MAIN_CLASS - 1].capacity)
                fprintf(stdout, "\n%d-й класс больше 10-го на %d\n", i + 1, table->classes[i].capacity - table->classes[MAIN_CLASS - 1].capacity);
            else if (table->classes[i].capacity < table->classes[MAIN_CLASS - 1].capacity)
                fprintf(stdout, "\n%d-й класс меньше 10-го на %d\n", i + 1, table->classes[MAIN_CLASS - 1].capacity - table->classes[i].capacity);
            else
                fprintf(stdout, "\n%d-й и 10-й классы имеют одинаковое количество учеников - равное %d.\n", i + 1, table->classes[MAIN_CLASS - 1].capacity);
        }
    }
}