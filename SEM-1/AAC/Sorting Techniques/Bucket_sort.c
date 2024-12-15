//Bucket Sort
#include <stdio.h>

#define BUCKET_COUNT 10
#define max 1000

void insertionSort(float arr[], int n) {
    int i;
    float key;
    int j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float buckets[BUCKET_COUNT][max];
    int bucketSizes[BUCKET_COUNT] = {0};

    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * BUCKET_COUNT);
        if (bucketIndex >= BUCKET_COUNT) bucketIndex = BUCKET_COUNT - 1;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("\nBucket Sort.");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    

    float arr[max];
    
    printf("\nEnter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}