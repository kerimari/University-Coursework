#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[16];
    float gpa;
} Student;

// Swaps two Student structures using pointers
void swap(Student *st1, Student *st2) {
    Student temp = *st1;
    *st1 = *st2;
    *st2 = temp;
}

// Returns a pointer to the student with the highest GPA
Student* ptr_of_maximum(Student *class, int numStudents) {
    Student *max_ptr = &class[0];
    for (int i = 1; i < numStudents; i++) {
        if (class[i].gpa > max_ptr->gpa) {
            max_ptr = &class[i];
        }
    }
    return max_ptr;
}

// Sorts students in decreasing order based on GPA
void sort_students(Student *class, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (class[i].gpa < class[j].gpa) {
                swap(&class[i], &class[j]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array of structures
    Student *class = (Student *)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("\nEnter ID, Name, and GPA for student %d: ", i + 1);
        scanf("%d %s %f", &class[i].id, class[i].name, &class[i].gpa);
    }

    // Task 3: Find and print the top student
    Student *top_student = ptr_of_maximum(class, n);
    printf("\nTop Student: ID: %d, Name: %s, GPA: %.2f\n", 
            top_student->id, top_student->name, top_student->gpa);

    // Task 4: Sort and print all records
    sort_students(class, n);
    printf("\n--- Students Sorted by GPA (Decreasing) ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %-5d Name: %-10s GPA: %.2f\n", 
                class[i].id, class[i].name, class[i].gpa);
    }

    // Deallocate dynamic memory
    free(class);
    return 0;
}
