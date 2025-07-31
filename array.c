#include <stdio.h>
int main() {
    int numbers[100], n, i;
    int max, min;
    printf("Enter number of elements (up to 100): ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    max = min = numbers[0];
    for (i = 1; i < n; i++) {
        if (numbers[i] > max)
            max = numbers[i];
        if (numbers[i] < min)
            min = numbers[i];
    }
    printf("Maximum value = %d\n", max);
    printf("Minimum value = %d\n", min);

    return 0;  
}
