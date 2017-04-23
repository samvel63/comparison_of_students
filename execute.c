#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "io.h"

#define MAX_SIZE 11
#define NEED_CLASS 10

typedef struct {
    int group;
    int capacity;
} Class;

int in_classes(Class *classes, int cap, int group)
{
    for (int i = 0; i < cap; ++i) {
        if (classes[i].group == group)
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Student student;
    Class classes[MAX_SIZE];
    int number_of_classes = 1;

    student_read_bin(&student, in);
    classes[0].group = student.group;
    classes[0].capacity = 1;

    while (student_read_bin(&student, in)) {
        if(in_classes(&classes, number_of_classes, student.group)) {
            for (int i = 0; i < number_of_classes; ++i) {
                if (classes[i].group == student.group) {
                    classes[i].capacity += 1;
                    break;
                }
            }
        } else {
            classes[number_of_classes].group = student.group;
            classes[number_of_classes].capacity = 1;
            number_of_classes++;
        }
    }
    printf("%d %d\n", classes[0].group, classes[0].capacity);
    printf("%d %d\n", classes[1].group, classes[1].capacity);
    printf("%d %d\n", classes[2].group, classes[2].capacity);
    return 0;
}