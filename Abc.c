#include <stdio.h>

#define MAX_STUDENTS 10
#define MAX_SUBJECTS 10
#define MAX_NAME_LEN 20

/* Function to calculate total marks of one student */
int calculate_total(int marks[], int subjectCount) {
    int total = 0;
    for (int j = 0; j < subjectCount; j++) {
        total += marks[j];
    }
    return total;
}

/* Function to find topper index */
int find_topper(int totals[], int studentCount) {
    if (studentCount <= 0) return -1;
    int maxIndex = 0;
    for (int i = 1; i < studentCount; i++) {
        if (totals[i] > totals[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int studentCount, subjectCount;
    int marks[MAX_STUDENTS][MAX_SUBJECTS], totals[MAX_STUDENTS];
    char studentNames[MAX_STUDENTS][MAX_NAME_LEN];

    printf("Enter number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &studentCount);
    if (studentCount <= 0 || studentCount > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &subjectCount);
    if (subjectCount <= 0 || subjectCount > MAX_SUBJECTS) {
        printf("Invalid number of subjects.\n");
        return 1;
    }

    /* Take input */
    for (int i = 0; i < studentCount; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", studentNames[i]);
        printf("Enter marks for %d subjects:\n", subjectCount);
        for (int j = 0; j < subjectCount; j++) {
            scanf("%d", &marks[i][j]);
            if (marks[i][j] < 0) {
                printf("Invalid mark! Defaulting to 0.\n");
                marks[i][j] = 0;
            }
        }
    }

    /* Calculate totals */
    for (int i = 0; i < studentCount; i++) {
        totals[i] = calculate_total(marks[i], subjectCount);
    }

    /* Find topper */
    int topperIndex = find_topper(totals, studentCount);

    printf("\n--- Student Results ---\n");
    printf("%-15s | Total\n", "Name");
    printf("-----------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-15s | %d\n", studentNames[i], totals[i]);
    }

    if (topperIndex != -1) {
        printf("\nTopper: %s with total %d\n", studentNames[topperIndex], totals[topperIndex]);
    } else {
        printf("\nNo topper found.\n");
    }

    return 0;
}
