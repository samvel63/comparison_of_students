#include <stdio.h>
#include <stdlib.h>

#include "class.h"
#include "db/api.h"


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
    int number_of_classes = 0;

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

    int cap_need_class = cap_class(&classes, number_of_classes, NEED_CLASS);
    print_comprison_of_classes(&classes, number_of_classes, cap_need_class);
    printf("\n");

    return 0;
}