#include <stdio.h>

int main() {

    int arr[] = {2, 4, 6, 8, 10};
    int n = 5;

    int key = 8;   // Element to search

    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return 0;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("Element not found\n");

    return 0;
}
