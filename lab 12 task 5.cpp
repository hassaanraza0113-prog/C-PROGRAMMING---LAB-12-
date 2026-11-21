
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getCategory(char ch) {
    if (isupper((unsigned char)ch))
        return 1;

    else if (islower((unsigned char)ch))
        return 2;

    else if (isdigit((unsigned char)ch))
        return 3;

    else
        return 4;
}

int main() {
    int n, i, j;
    int matches, highest = -1, best = 0;

    char pattern[200];
    char **password;
    float similarity;

    printf("Enter password pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    pattern[strcspn(pattern, "\n")] = '\0';

    int length = strlen(pattern);

    printf("Enter number of participants: ");
    scanf("%d", &n);
    getchar();

    password = (char **)malloc(n * sizeof(char *));

    if (password == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        char temp[200];

        printf("Enter password attempt %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);

        temp[strcspn(temp, "\n")] = '\0';

        password[i] = (char *)malloc(strlen(temp) + 1);

        if (password[i] == NULL) {
            printf("Memory allocation failed!");
            return 1;
        }

        strcpy(password[i], temp);
    }

    printf("\nPassword Similarity Results:\n");

    for (i = 0; i < n; i++) {
        matches = 0;

        for (j = 0; j < length && password[i][j] != '\0'; j++) {
            if (getCategory(password[i][j]) ==
                getCategory(pattern[j])) {
                matches++;
            }
        }

        similarity = (float)matches / length * 100;

        printf("\nPassword: %s", password[i]);
        printf("\nSimilarity: %.2f%%\n", similarity);

        if (similarity > highest) {
            highest = similarity;
            best = i;
        }
    }

    printf("\nHighest similarity password: %s",
           password[best]);

    printf("\nHighest similarity: %d%%", highest);

    for (i = 0; i < n; i++) {
        free(password[i]);
    }

    free(password);

    return 0;
}

