#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

//function to initialize array pointer
short* fill_array_rnd(unsigned int arr_size) {
    short *array = (short *)malloc(sizeof(short ) * arr_size);
    if (array == NULL) {                                                          //abort if no memory is free
        printf("BAD MEMORY");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < arr_size; i++) {
        *(array +i) = rand() - (RAND_MAX / 2);                                    //subtract RAND_MAX/2 te get negative values
    }
    return array;                                                                 //returns memory address
}

//function to print array
void print_array(short array[], unsigned  size) {
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

int main(){

    srand(time(NULL));
    short *array_eight = fill_array_rnd(8);
    short *array_sixteen = fill_array_rnd(16);
    short *array_sixtyfour = fill_array_rnd(64);

    printf("BUBBLESORT:\n");
    printf("Unsorted array with size of 8:\n");
    print_array(array_eight, 8);
    printf("Unsorted array with size of 16:\n");
    print_array(array_sixteen, 16);
    printf("Unsorted array with size of 64:\n");
    print_array(array_sixtyfour, 64);

    bubble_sort(array_eight, 8);
    bubble_sort(array_sixteen, 16);
    bubble_sort(array_sixtyfour, 64);

    printf("Array with size of 8 after BUBBLESORT:\n");
    print_array(array_eight, 8);
    printf("Array with size of 16 after BUBBLESORT:\n");
    print_array(array_sixteen, 16);
    printf("Array with size of 64 after BUBBLESORT:\n");
    print_array(array_sixtyfour, 64);

    check_sort(array_eight, 8);
    check_sort(array_sixteen, 16);
    check_sort(array_sixtyfour, 64);

    free(array_eight);
    free(array_sixteen);
    free(array_sixtyfour);

    array_eight = fill_array_rnd(8);
    array_sixteen = fill_array_rnd(16);
    array_sixtyfour = fill_array_rnd(64);

    printf("\n\n\nMERGESORT:\n");
    printf("Unsorted array with size of 8:\n");
    print_array(array_eight, 8);
    printf("Unsorted array with size of 16:\n");
    print_array(array_sixteen, 16);
    printf("Unsorted array with size of 64:\n");
    print_array(array_sixtyfour, 64);

    merge_Sort(array_eight, 0, 8);
    merge_Sort(array_sixteen, 0, 16);
    merge_Sort(array_sixtyfour, 0, 64);

    printf("Array with size of 8 after MERGESORT:\n");
    print_array(array_eight, 8);
    printf("Array with size of 16 after MERGESORT:\n");
    print_array(array_sixteen, 16);
    printf("Array with size of 64 after MERGESORT:\n");
    print_array(array_sixtyfour, 64);

    check_sort(array_eight, 8);
    check_sort(array_sixteen, 16);
    check_sort(array_sixtyfour, 64);

    free(array_eight);
    free(array_sixteen);
    free(array_sixtyfour);

    array_eight = fill_array_rnd(8);
    array_sixteen = fill_array_rnd(16);
    array_sixtyfour = fill_array_rnd(64);

    printf("\n\n\nINSERTIONSORT:\n");
    printf("Unsorted array with size of 8:\n");
    print_array(array_eight, 8);
    printf("Unsorted array with size of 16:\n");
    print_array(array_sixteen, 16);
    printf("Unsorted array with size of 64:\n");
    print_array(array_sixtyfour, 64);

    insertion_Sort(array_eight, 8);
    insertion_Sort(array_sixteen, 16);
    insertion_Sort(array_sixtyfour, 64);

    printf("Array with size of 8 after INSERTIONSORT:\n");
    print_array(array_eight, 8);
    printf("Array with size of 16 after INSERTIONSORT:\n");
    print_array(array_sixteen, 16);
    printf("Array with size of 64 after INSERTIONSORT:\n");
    print_array(array_sixtyfour, 64);

    check_sort(array_eight, 8);
    check_sort(array_sixteen, 16);
    check_sort(array_sixtyfour, 64);

    free(array_eight);
    free(array_sixteen);
    free(array_sixtyfour);

    array_eight = fill_array_rnd(8);
    array_sixteen = fill_array_rnd(16);
    array_sixtyfour = fill_array_rnd(64);

    printf("\n\n\nQUICKSORT:\n");
    printf("Unsorted array with size of 8:\n");
    print_array(array_eight, 8);
    printf("Unsorted array with size of 16:\n");
    print_array(array_sixteen, 16);
    printf("Unsorted array with size of 64:\n");
    print_array(array_sixtyfour, 64);

    quickSort(array_eight, 0, 8);
    quickSort(array_sixteen, 0, 16);
    quickSort(array_sixtyfour, 0, 64);

    printf("Array with size of 8 after QUICKSORT:\n");
    print_array(array_eight, 8);
    printf("Array with size of 16 after QUICKSORT:\n");
    print_array(array_sixteen, 16);
    printf("Array with size of 64 after QUICKSORT:\n");
    print_array(array_sixtyfour, 64);

    check_sort(array_eight, 8);
    check_sort(array_sixteen, 16);
    check_sort(array_sixtyfour, 64);

    free(array_eight);
    free(array_sixteen);
    free(array_sixtyfour);

    return 0;
}