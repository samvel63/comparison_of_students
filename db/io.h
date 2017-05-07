#ifndef _IO_H_
#define _IO_H_

#include "class.h"

/* Student IO */
uint32_t student_read_txt(Student *s, uint32_t *class, FILE *in);
uint32_t student_read_bin(Student *s, uint32_t *class, FILE *in);
void student_write_bin(Student *s, uint32_t class, FILE *out);
void student_print(Student *s, uint32_t class);
is_student_bin(FILE *in);

#endif
