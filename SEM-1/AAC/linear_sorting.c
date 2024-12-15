//Linear Sorting

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int maxVal) {
    int *count = (int *)calloc(maxVal + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

void radixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, n, 9);
    }
}

void bucketSort(float arr[], int n) {
    int bucketCount = 10;
    float **buckets = (float **)malloc(bucketCount * sizeof(float *));
    int *bucketSizes = (int *)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * bucketCount);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            countingSort(buckets[i], bucketSizes[i], 9);
        }
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements for Counting and Radix Sort: ");
    scanf("%d", &n);
    int *arr1 = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    countingSort(arr1, n, 9);
    printf("Sorted array using Counting Sort:\n");
    printArray(arr1, n);

    radixSort(arr1, n);
    printf("Sorted array using Radix Sort:\n");
    printArray(arr1, n);

    free(arr1);

    printf("Enter the number of elements for Bucket Sort: ");
    scanf("%d", &n);
    float *arr2 = (float *)malloc(n * sizeof(float));
    printf("Enter the elements (between 0 and 1):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr2[i]);
    }

    bucketSort(arr2, n);
    printf("Sorted array using Bucket Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr2[i]);
    }
    printf("\n");

    free(arr2);
    return 0;
}