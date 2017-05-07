#ifndef _IO_H_
#define _IO_H_

#include "class.h"

/* Student IO */
int student_read_txt(Student *s, int *class, FILE *in);
int student_read_bin(Student *s, int *class, FILE *in);
void student_write_bin(Student *s, int class, FILE *out);
void student_print(Student *s, int class);
is_student_bin(FILE *in);

#endif
