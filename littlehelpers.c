#include "littlehelpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to initialize array pointer
short* fill_array_rnd(unsigned int arr_size) {
    short *array = (short *)malloc(sizeof(short ) * arr_size);
    if (array == NULL) {                                                          //abort if no memory is free
        printf("BAD MEMORY");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < arr_size; i++) {
        *(array +i) = rand() - (RAND_MAX / 2);                                    //subtract RAND_MAX/2 to get negative values
    }
    return array;                                                                 //returns memory address
}

//function to initialize array pointer for descending order
short* fill_array_des(unsigned int arr_size) {
    short *array = (short *)malloc(sizeof(short ) * arr_size);
    if (array == NULL) {                                                          //abort if no memory is free
        printf("BAD MEMORY");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < arr_size; i++) {
        *(array + i) = arr_size - i - 1;
    }
    return array;                                                                 //returns memory address
}

//function to initialize array pointer for ascending order
short* fill_array_asc(unsigned int arr_size) {
    short *array = (short *)malloc(sizeof(short ) * arr_size);
    if (array == NULL) {                                                          //abort if no memory is free
        printf("BAD MEMORY");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < arr_size; i++) {
        *(array +i) = i;
    }
    return array;                                                                 //returns memory address
}

//function to print array
void print_array(short array[], unsigned int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d] ", array[i]);
        if ((i + 1) % 15 == 0) {                                                  //for newline after 15 output numbers
            printf("\n");
        }else if (i == (size - 1)) {                                              //newline after last output
            printf("\n");
        }
    }
}

//function to confirm sorting
void check_sort(short array[], unsigned int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] > array[i + 1] && i != (size - 1)) {                         //checks for ascending sort. For descending change to '<'
            printf("Sorting array with size of %d FAILED!\n", size);
            break;
        } else if (i == size - 1) {
            printf("Successfully sorted array with size of %d\n", size);
        }
    }
}