#include <stdio.h>
#include "sorts.h"

// sortiert und vereint die Subarrays miteinander.
void merge(int array[], int first_index, int mid, int last_index) { // die Funktion "merg" benötigt das Array, die erste Indexstelle den Mittelwert und die letzte Indexstelle

    //die zwei Startindexstellen der Arrays
    int n1 = mid - first_index + 1;
    int n2 = last_index - mid;

    // Deklarierung der Subarrays
    int sub_array1[n1], sub_array2[n2];

    //Initialisierung der Subarrays
    for (int i = 0; i < n1; i++)
        sub_array1[i] = array[first_index + i];
    for (int j = 0; j < n2; j++)
        sub_array2[j] = array[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = first_index;

    //Sortierung nach aufsteigender Größe
    while (i < n1 && j < n2) {
        if (sub_array1[i] <= sub_array2[j]) {
            array[k] = sub_array1[i];
            i++;
        } else {
            array[k] = sub_array2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = sub_array1[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = sub_array2[j];
        j++;
        k++;
    }
}
// das Array wird in Subarrays geteilt, sortiert und wieder miteinander verbunden.
void merge_Sort(int array[], int first_index, int last_index) {  // die Funktion "merg_Sort" benötigt das Array, die erste und letzte Indexstelle

    // Überprüfung, ob nur eine Indexstelle existiert.
    if (first_index < last_index) {

        // die Array-größe wird geteilt
        int mid = first_index +(last_index - first_index) / 2;

        // die Funktion "merge_Sort" wird seperat auf beide Teile ausgeführt
        merge_Sort(array, first_index, mid);
        merge_Sort(array, mid + 1, last_index);

        //führt die Funktion merge aus
        merge(array, first_index, mid, last_index);
    }
}