#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "table.h"

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

void table_load_txt(Table *table, Student *s, FILE *in)
{
    int class = 0;
    while (student_read_txt(s, in)) {
        fscanf(in, "%d", &class);
        add_student(table, s, class);
    }
}

void table_load_bin(Table *table, Student *s, FILE *in)
{
    int class = 0;
    while (student_read_bin(s, in)) {
        fread(&class, sizeof(int), 1, in);
        add_student(table, s, class);        
    }
}

void table_save(Table *table, FILE *out)
{
    for (int i = 1; i <= MAX_CLASSES; ++i) {
        for (int j = 0; j < table->classes[i - 1].capacity; ++j) {
            student_write_bin(&(table->classes[i - 1].students[j]), out);
            fwrite(&i, sizeof(int), 1, out);
        }
    }
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
/*
void table_delete(Table *table, int index)
{
    table->num_students--;
    for (int i = index - 1; i < table->num_students; ++i)
        memcpy(&table->students[i], &table->students[i + 1], sizeof(Student));
    table->students = (Student *)realloc(table->students, (table->num_students + 1) * sizeof(Student));
}
*/
void add_student(Table *table, Student *s, int class)
{
    table->classes[class - 1].students = (Student *)realloc(table->classes[class - 1].students, (table->classes[class - 1].capacity + 1) * sizeof(Student));

    strncpy(table->classes[class - 1].students[table->classes[class - 1].capacity].surname, s->surname, STR_SIZE);
    strncpy(table->classes[class - 1].students[table->classes[class - 1].capacity].initials, s->initials, STR_SIZE);
    table->classes[class - 1].capacity++;
}