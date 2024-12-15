//Fractional Knapsack

#include <stdio.h>
#include <stdlib.h>

void sortItems(int values[], int weights[], float ratios[], int numItems) {
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = 0; j < numItems - i - 1; j++) {
            if (ratios[j] < ratios[j + 1]) {
                float tempRatio = ratios[j];
                ratios[j] = ratios[j + 1];
                ratios[j + 1] = tempRatio;

                int tempValue = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tempValue;

                int tempWeight = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = tempWeight;
            }
        }
    }
}

float fractionalKnapsack(int capacity, int values[], int weights[], int numItems) {
    float ratios[numItems];
    for (int i = 0; i < numItems; i++) {
        ratios[i] = (float)values[i] / weights[i];
    }

    sortItems(values, weights, ratios, numItems);

    float totalValue = 0.0;
    for (int i = 0; i < numItems; i++) {
        if (weights[i] <= capacity) {
            capacity -= weights[i];
            totalValue += values[i];
        } else {
            totalValue += values[i] * ((float)capacity / weights[i]);
            break;
        }
    }
    return totalValue;
}

int main() {
    int numItems, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    int values[numItems], weights[numItems];

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(capacity, values, weights, numItems);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}