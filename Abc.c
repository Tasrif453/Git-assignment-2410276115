#include <stdio.h>

int main() {
    int n, s, i, j;
    int a[10][10], t[10], big = 0, k;
    char name[10][20];

    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter number of subjects: ");
    scanf("%d", &s);

    for (i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%s", name[i]);
        for (j = 0; j < s; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        t[i] = 0;
        for (j = 0; j < s; j++) {
            t[i] = t[i] + a[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        if (t[i] > big) {
            big = t[i];
            k = i;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%s %d\n", name[i], t[i]);
    }

    printf("Topper: %s\n", name[k]);
}
