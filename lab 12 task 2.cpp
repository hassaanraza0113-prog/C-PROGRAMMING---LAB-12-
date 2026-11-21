
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, total = 0;
    int longest = 0;

    char **feedback;

    printf("Enter number of feedback entries: ");
    scanf("%d", &n);
    getchar();

    feedback = (char **)malloc(n * sizeof(char *));

    if (feedback == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        char temp[500];

        printf("Enter feedback %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);

        temp[strcspn(temp, "\n")] = '\0';

        feedback[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));

        if (feedback[i] == NULL) {
            printf("Memory allocation failed!");
            return 1;
        }

        strcpy(feedback[i], temp);

        total += strlen(feedback[i]);

        if (strlen(feedback[i]) > longest) {
            longest = strlen(feedback[i]);
        }
    }

    printf("\nAll feedback entries:\n");

    for (i = 0; i < n; i++) {
        printf("%s\n", feedback[i]);
    }

    printf("\nTotal characters = %d", total);

    printf("\nLongest feedback = ");

    for (i = 0; i < n; i++) {
        if (strlen(feedback[i]) == longest) {
            printf("%s", feedback[i]);
            break;
        }
    }

    for (i = 0; i < n; i++) {
        free(feedback[i]);
    }

    free(feedback);

    return 0;
}

