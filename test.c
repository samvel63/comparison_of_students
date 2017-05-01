#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "io.h"
#include "db/api.h"

int main(void)
{
	Table table;
	Tuple tuple;

	char name[NAME_LENGTH];
	Gender gender;
	char s;
	int class;
	scanf("%s %c %d", name, &gender, &class);
	table_create(&table, "CAPACITY STUDENTS");
	add_student(&table, &tuple, &name[0], gender, class);

	print(&table);
}