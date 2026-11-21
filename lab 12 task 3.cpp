
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int containsDigit(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (isdigit((unsigned char)str[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, i;
    char **username;

    printf("Enter number of usernames: ");
    scanf("%d", &n);
    getchar();

    username = (char **)malloc(n * sizeof(char *));

    if (username == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        char temp[100];

        printf("Enter username %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);

        temp[strcspn(temp, "\n")] = '\0';

        username[i] = (char *)malloc(strlen(temp) + 1);

        if (username[i] == NULL) {
            printf("Memory allocation failed!");
            return 1;
        }

        strcpy(username[i], temp);
    }

    printf("\nValid usernames:\n");

    for (i = 0; i < n; i++) {
        if (!containsDigit(username[i])) {
            printf("%s\n", username[i]);
        }
    }

    for (i = 0; i < n; i++) {
        free(username[i]);
    }

    free(username);

    return 0;
}

