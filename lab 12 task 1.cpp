
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, total = 0, lowest, index;
    float average;

    printf("Enter number of book categories: ");
    scanf("%d", &n);

    int *stock = (int *)malloc(n * sizeof(int));

    if (stock == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter stock for category %d: ", i + 1);
        scanf("%d", &stock[i]);

        total += stock[i];
    }

    lowest = stock[0];
    index = 0;

    for (i = 1; i < n; i++) {
        if (stock[i] < lowest) {
            lowest = stock[i];
            index = i;
        }
    }

    average = (float)total / n;

    printf("\nTotal stock = %d", total);
    printf("\nAverage stock = %.2f", average);
    printf("\nLowest stock category index = %d", index);

    int choice, newStock;

    printf("\nEnter category number to update: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= n) {
        printf("Enter new stock: ");
        scanf("%d", &newStock);

        stock[choice - 1] = newStock;
    } else {
        printf("Invalid category!");
    }

    printf("\nUpdated stock values:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", stock[i]);
    }

    free(stock);

    return 0;
}

