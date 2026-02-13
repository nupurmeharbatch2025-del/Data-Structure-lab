#include <stdio.h>

int main() {
    int n, key;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &key);
    
    int found = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("found at position %d\n", i);
            found = 1;
            break;
        }
    }
    
    if(found == 0) {
        printf("%d not found\n", key);
    }

    return 0;
}
