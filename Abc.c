#include <stdio.h>

int main() {
    int studentCount, subjectCount;
    int marks[10][10], total[10], highestTotal = 0, topperIndex;
    char studentNames[10][20];

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
        total[i] = 0;
        for (int j = 0; j < subjectCount; j++) {
            total[i] += marks[i][j];
        }
    }

    for (int i = 0; i < studentCount; i++) {
        if (total[i] > highestTotal) {
            highestTotal = total[i];
            topperIndex = i;
        }
    }

    for (int i = 0; i < studentCount; i++) {
        printf("%s %d\n", studentNames[i], total[i]);
    }

    printf("Topper: %s\n", studentNames[topperIndex]);
}
