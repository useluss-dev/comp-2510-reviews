#include <stddef.h>
#include <stdio.h>

void print_array_stats(const int arr[], size_t len) {
    if (len == 0) {
        printf("Array is empty; no minimum, maximum, or average.\n");
        return;
    }

    int highest = arr[0];
    int lowest = arr[0];
    long long sum = 0;

    for (size_t i = 0; i < len; i++) {
        if (arr[i] > highest)
            highest = arr[i];
        if (arr[i] < lowest)
            lowest = arr[i];

        sum += arr[i];
    }

    double average = (double)sum / len;

    printf("Highest: %d\n", highest);
    printf("Lowest:  %d\n", lowest);
    printf("Sum:     %lld\n", sum);
    printf("Average: %.2f\n", average);
}
