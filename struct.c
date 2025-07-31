#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NUM_SUBJECTS 5
struct Student {
    int id;
    char name[50];
    int marks[NUM_SUBJECTS];
    float average;
};
void inputStudents(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);  

        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }

        // Calculate average immediately after input
        calculateAverage(&s[i]);
    }
}

// Function to calculate average
void calculateAverage(struct Student *s) {
    int sum = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        sum += s->marks[i];
    }
    s->average = sum / (float)NUM_SUBJECTS;
}

// Function to display the topper
void displayTopper(struct Student s[], int n) {
    int topperIndex = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].average > s[topperIndex].average) {
            topperIndex = i;
        }
    }

    printf("\nTopper Student Details:\n");
    printf("ID: %d\n", s[topperIndex].id);
    printf("Name: %s\n", s[topperIndex].name);
    printf("Marks: ");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("%d ", s[topperIndex].marks[j]);
    }
    printf("\nAverage: %.2f\n", s[topperIndex].average);
}

// Main function
int main() {
    struct Student students[MAX_STUDENTS];
    int n;

    printf("Enter number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &n);

    inputStudents(students, n);
    displayTopper(students, n);

    return 0;
}
