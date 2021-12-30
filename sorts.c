#include <stdio.h>
#include "sorts.h"

void bubble_sort(short array[], unsigned int size) {
    for (int i = 0; i < (size -1); i++) {                   // look at each array element.
        for (int j = 0; j < (size - i - 1); j++) {          // compare array elements.
            if (array[j] > array[j + 1]) {                  // sort ascending. Change to < for descending sort.
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}