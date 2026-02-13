#include <stdio.h>

int main() {

    int arr[] = {5, 2, 9, 1, 3};
    int n = 5;
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++) {
        min = i;   // assume current index is minimum

        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;   // update minimum index
            }
        }

       
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
