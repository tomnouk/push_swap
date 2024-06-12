#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 200

void shuffle(int *array, int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main() {
    int numbers[SIZE];
    // Initialize the array with numbers from 1 to 100
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i + 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the array to randomize the order of elements
    shuffle(numbers, SIZE);

    // Print the first 100 numbers separated by commas
    for (int i = 0; i < SIZE; i++) {
        printf("%d", numbers[i]);
        if (i < SIZE - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
