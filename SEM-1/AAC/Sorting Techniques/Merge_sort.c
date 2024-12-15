//MERGE SORT
#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int b[100]; 
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    
    while (j <= high) {
        b[k] = a[j];
        j++;
        k++;
    }
    
    for (int s = low; s <= high; s++) {
        a[s] = b[s];
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n, i;
    printf("**Merge Sort**");
    printf("\nSorting by using mergeSort.");
    
    printf("\nEnter total number of elements:\n");
    scanf("%d", &n);
    
    int a[n];
    
    printf("Enter Elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int low = 0;
    int high = n - 1;
    
    mergeSort(a, low, high);
    
    printf("\nSorted elements using merge sort:");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    
    return 0;
}