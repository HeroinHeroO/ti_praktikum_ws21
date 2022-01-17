//
// Created by Aelfric on 29.12.2021.
//

#ifndef TI_PRAKTIKUM_WS21_SORTS_H
#define TI_PRAKTIKUM_WS21_SORTS_H

//Bubblesort-functions
void bubble_sort(short array[], unsigned int size);

//Mergesort-functions
void merge(short array[], int first_index, int mid, int last_index);
void merge_Sort(short array[], int first_index, int last_index);

//Inertionsort-functions
void insertion_Sort(short array[], int arraysize);

//Quicksort-functions
void swap(short *i, short *j);
int partition(short array[], int first_element, int last_element);
void quickSort(short array[], int first_element, int last_element);

#endif //TI_PRAKTIKUM_WS21_SORTS_H
