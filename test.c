#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "io.h"
#include "db/api.h"

int main(void)
{
	Table table;
	table_create(&table, "HUY");
	Tuple tuple;
	add_student(&tuple, "MhitaryanSA", 'M', 10);
	//printf("%s == %c == %d\n", tuple.full_name, tuple.gender, tuple.class);
	tuple_insert(&table, &tuple);
	print(&table);
	printf("%s == %c == %d\n", table.tuples[0].full_name, table.tuples[0].gender, table.tuples[0].class);
}