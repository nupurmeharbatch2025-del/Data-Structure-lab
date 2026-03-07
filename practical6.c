//merge sort
#include <stdio.h>

int main()
{
    int arr[100] = {38, 27, 43, 3, 9, 82, 10};
    int temp[100];
    int n = 7;

    int size, left, mid, right, i, j, k;

    for (size = 1; size < n; size = size * 2)
    {
        for (left = 0; left < n - size; left = left + 2 * size)
        {
            mid = left + size - 1;

            if (left + 2 * size - 1 < n - 1)
                right = left + 2 * size - 1;
            else
                right = n - 1;

            i = left;
            j = mid + 1;
            k = left;

            while (i <= mid && j <= right)
            {
                if (arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else
                    temp[k++] = arr[j++];
            }

            while (i <= mid)
                temp[k++] = arr[i++];

            while (j <= right)
                temp[k++] = arr[j++];

            for (i = left; i <= right; i++)
                arr[i] = temp[i];
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
