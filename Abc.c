#include <stdio.h>

#define MAX_STUDENTS 10
#define MAX_SUBJECTS 10
#define MAX_NAME_LEN 20

int calculate_total(int marks[], int subjectCount) {
    int total = 0;
    for (int j = 0; j < subjectCount; j++) {
        total += marks[j];
    }
    return total;
}

int find_topper(int totals[], int studentCount) {
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

    printf("Enter number of students: ");
    scanf("%d", &studentCount);
    printf("Enter number of subjects: ");
    scanf("%d", &subjectCount);

    for (int i = 0; i < studentCount; i++) {
        printf("Enter name: ");
        scanf("%s", studentNames[i]);
        for (int j = 0; j < subjectCount; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    for (int i = 0; i < studentCount; i++) {
        totals[i] = calculate_total(marks[i], subjectCount);
    }

    int topperIndex = find_topper(totals, studentCount);

    for (int i = 0; i < studentCount; i++) {
        printf("%s %d\n", studentNames[i], totals[i]);
    }

    printf("Topper: %s\n", studentNames[topperIndex]);
}
