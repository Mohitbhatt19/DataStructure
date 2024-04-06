#include <stdio.h>

void findIndices(int arr[], int n, int target) {
    int found = 0;
    printf("Indices of %d in the array: ", target);
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int arr[100], n, target;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    findIndices(arr, n, target);

    return 0;
}
