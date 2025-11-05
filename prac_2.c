#include <stdio.h>
int main() {
    int arr[100], n, key;
    int start, end, mid;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);
    start = 0;
    end = n - 1;

    while (start <= end) {
        mid = (start + end) / 2;

        printf("\nCurrent list: ");
        for (int i = start; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nMiddle element: %d (Index %d)\n", arr[mid], mid);

        if (arr[mid] == key) {
            printf(" Element %d found at index %d\n", key, mid);
            found = 1;
            break;
        } 
        else if (key > arr[mid]) {
            printf(" Key %d is greater than %d, searching right half\n", key, arr[mid]);
            start = mid + 1;
        } 
        else {
            printf(" Key %d is smaller than %d, searching left half\n", key, arr[mid]);
            end = mid - 1;
        }
    }
    if (!found) {
        printf("\nElement not found.\nResult: NULL\n");
    }
    return 0;
}
