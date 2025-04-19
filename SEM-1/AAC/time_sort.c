//Write a program to sort the given list using Bubble, Selection sort, Insertion sort, and Heap sort & compare the time.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *arrCopy = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i];
    clock_t start = clock();
    bubbleSort(arrCopy, n);
    clock_t end = clock();
    printf("Bubble Sort Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(arrCopy);

    arrCopy = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i];
    start = clock();
    selectionSort(arrCopy, n);
    end = clock();
    printf("Selection Sort Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(arrCopy);

    arrCopy = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i];
    start = clock();
    insertionSort(arrCopy, n);
    end = clock();
    printf("Insertion Sort Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(arrCopy);

    arrCopy = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i];
    start = clock();
    heapSort(arrCopy, n);
    end = clock();
    printf("Heap Sort Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(arrCopy);

    free(arr);
    return 0;
}