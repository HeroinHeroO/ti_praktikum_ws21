#include <stdio.h>
#include "sorts.h"

// verbindet die Subarrays "L" und "M" miteinander.
void merge(int array[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = array[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = M[j];
        j++;
        k++;
    }
}
// das Array in Subarrays geteilt, sortiert und wieder miteinander verbunden.
void merge_Sort(int array[], int l, int r) {  // die Funktion "merg_Sort" benötigt das Array, eine null und die Array-größe minus 1 (falls kein Element enthalten ist oder das Array nur aus einem Element besteht)
    if (l < r) { // Überprüfung, ob die größe des Arrays größer als Null ist

        // die Array-größe wird geteilt
        int m = l + (r - l) / 2;

        merge_Sort(array, l, m);
        merge_Sort(array, m + 1, r);

        merge(array, l, m, r);
    }
}