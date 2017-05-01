#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "table.h"

void table_create(Table *table, const char *name)
{
	strncpy(table->name, name, STR_SIZE);
	table->students = (Student *)malloc(0);
	table->num_students = 0;
}

void table_destroy(Table *table)
{
	free(table->students);
}

void table_load_txt(Table *table, Student *s, FILE *in)
{
    while (student_read_txt(s, in))
        add_student(table, s);
}

void table_load_bin(Table *table, Student *s, FILE *in)
{
    while (student_read_bin(s, in))
        add_student(table, s);
}

void table_save(Table *table, FILE *out)
{
    for (int i = 0; i < table->num_students; ++i)
        student_write_bin(&(table->students[i]), out);
}

void table_print(Table *table)
{
    printf("Number \t Surname \t Initials \t Class\n");
    for (int i = 0; i < table->num_students; ++i)
        printf("%d \t %s \t    %s \t\t %d\n", i + 1, table->students[i].surname, table->students[i].initials, table->students[i].group);
}

void table_delete(Table *table, int index)
{
    table->num_students--;
    for (int i = index - 1; i < table->num_students; ++i)
        memcpy(&table->students[i], &table->students[i + 1], sizeof(Student));
    table->students = (Student *)realloc(table->students, (table->num_students + 1) * sizeof(Student));
}

void add_student(Table *table, Student *student)
{
    table->students = (Student *)realloc(table->students, (table->num_students + 1) * sizeof(Student));

	strncpy(table->students[table->num_students].surname, student->surname, STR_SIZE);
	strncpy(table->students[table->num_students].initials, student->initials, STR_SIZE);
	table->students[table->num_students].group = student->group;

	table->num_students++;
}