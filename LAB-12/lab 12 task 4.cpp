
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, total = 0;
    int highest, index;

    printf("Enter number of movie categories: ");
    scanf("%d", &n);

    int *rating = (int *)malloc(n * sizeof(int));

    if (rating == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter ratings for category %d: ", i + 1);
        scanf("%d", &rating[i]);

        total += rating[i];
    }

    highest = rating[0];
    index = 0;

    for (i = 1; i < n; i++) {
        if (rating[i] > highest) {
            highest = rating[i];
            index = i;
        }
    }

    printf("\nTotal ratings = %d", total);
    printf("\nAverage ratings = %.2f", (float)total / n);
    printf("\nHighest rating category index = %d", index);

    int choice, newRating;

    printf("\n\nEnter category number to update: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= n) {
        printf("Enter new rating count: ");
        scanf("%d", &newRating);

        rating[choice - 1] = newRating;
    } else {
        printf("Invalid category!");
    }

    printf("\nUpdated ratings:\n");

    total = 0;

    for (i = 0; i < n; i++) {
        printf("%d ", rating[i]);
        total += rating[i];
    }

    printf("\nUpdated total = %d", total);

    free(rating);

    return 0;
}

