#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void table_print(Table *table)
{
	printf("Number \t Surname \t Initials \t Class\n");
	for (int i = 0; i < table->num_students; ++i)
		printf("%d \t %s \t    %s \t\t %d\n", i + 1, table->students[i].surname, table->students[i].initials, table->students[i].group);
}

void add_student(Table *table, Student *student)
{
	table->students = (Student *)realloc(table->students, (table->num_students + 1) * sizeof(Student));

	strncpy(table->students[table->num_students].surname, student->surname, STR_SIZE);
	strncpy(table->students[table->num_students].initials, student->initials, STR_SIZE);
	table->students[table->num_students].group = student->group;

	table->num_students++;
}