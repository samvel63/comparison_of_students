#ifndef _TABLE_H_
#define _TABLE_H_

#define STR_SIZE 64

typedef struct {
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    int  group;
} Student;


typedef struct {
	char name[STR_SIZE];
	Student *students;
	size_t num_students;
} Table;

void table_create(Table *table, const char *name);
void table_destroy(Table *table);
void add_student(Table *table, Student *student);
void table_print(Table *table);
void table_load_txt(Table *table, Student *s, FILE *in);
void table_load_bin(Table *table, Student *s, FILE *in);
void table_save(Table *table, FILE *out);
void table_delete(Table *table, int index);

#endif