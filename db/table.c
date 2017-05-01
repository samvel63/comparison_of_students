#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

void table_create(Table *table, const char *name)
{
	strncpy(table->name, name, NAME_LENGTH);
	table->tuples = (Tuple *)malloc(0);
	table->num_tuples = 0;
}

void table_destroy(Table *table)
{
	free(table->tuples);
}

void tuple_insert(Table *table, Tuple *tuple)
{
	table->tuples = (Tuple *)realloc(table->tuples, (table->num_tuples + 1) * sizeof(Tuple));
	table->tuples[table->num_tuples].gender = tuple->gender;
	table->tuples[table->num_tuples].class = tuple->class;
	strncpy(table->tuples[table->num_tuples].full_name, tuple->full_name, NAME_LENGTH);
	table->num_tuples++;
}

void add_student(Table *table, Tuple *tuple, const char *full_name, const Gender gender, const int class)
{
	strncpy(tuple->full_name, full_name, NAME_LENGTH);
	tuple->gender = gender;
	tuple->class = class;
	tuple_insert(table, tuple);
}

void print(Table *table)
{
	for (int i = 0; i < table->num_tuples; ++i)
		printf("%d == %s == %c == %d\n", i + 1, table->tuples[i].full_name, table->tuples[i].gender, table->tuples[i].class);
}