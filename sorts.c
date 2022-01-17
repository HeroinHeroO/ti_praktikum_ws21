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


// sortiert und vereint die Subarrays miteinander.
void merge(short array[], int first_index, int mid, int last_index) { // die Funktion "merg" benötigt das Array, die erste Indexstelle den Mittelwert und die letzte Indexstelle

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
void merge_Sort(short array[], int first_index, int last_index) {  // die Funktion "merg_Sort" benötigt das Array, die erste und letzte Indexstelle

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

// Insertion sort in C
void insertion_Sort(short array[], int arraysize) {
    //geht alle Elemente des arrays durch
    //element startet beim 2ten elment des arrays
    for (int i = 1; i<arraysize; i++ ){
        int element = array[i];
        int j = i-1; //index vom vergleichs element links vom "element"


        // alle linken  vergleichselemente vor "element" (arr [0- ...i-1])
        // mit vergleichselment> "element"
        // werden nach rechts verschoben;

        while (array[j] > element  && j >= 0) {
            array[j + 1] = array[j]; // linkes element wird ein nach rechts verschoben
            j--; // j index zeigt auf ein element weiter links

        }
        array[j + 1] = element;
        // wenn linke vergleichs_elmente > "element" ,
        // dann wird "element"  eins vor letzen vergleichs_elment gesetzt
        //Ansonsten bleibt "element" auf dem selbem index

    }

}

//quicksort
/* Das letzte element des Arrays wird als Pivot festgelegt. Danach werden alle Elemente [0-n-1] angesehen und: wenn eine Element kleiner als das
Pivot (am Ende des Arrays) ist, wird es auf Platz i (0++) des Arrays getauscht (das darauffolgende, kleinere wird auf platz 1 getauscht, usw.).
Nachdem alle Elemente gecheckt wurden, wird das Pivot mit dem ersten Element, das nicht getauscht wurde (i+1 -> also größer ist als Pivot) getauscht.
Das neue Pivot element wird mit i+1 returned.
In der rekursivion Funktion quickSort wird dann die Partition Funktion noch einmal für links (alle Elemente kleiner des neuen Pivot) des neuen(!) Pivot durchgeführt, danach rechts davon.
*/

// funktion um zwei elemente zu tauschen
void swap(short *i, short *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}


//Funktion nimmt array und erstes element und letztes element
int partition(short array[], int first_element, int last_element) {
    // das element an der letzten stelle wird als Pivot-Element festgelegt
    int pivotelement = array[last_element];

    int i = (first_element - 1); //  temporärer pivot index-> da soll kleineres element hin
    //bzw. zum schluss das pivot element hin
    for (int j = first_element; j < last_element; j++)  {//loop  durch alle elemente
        if (array[j] < pivotelement) { // Wenn current Element <= pivotelement
            i++; // temporärer pivot index  +1
            swap(&array[i], &array[j]); // tausche current element arr[j]
            // mit arr[i] welches größer als pivotelment ist
        }
    }

    // tauscht das pivot element arr[last_elment], m mit dem ersten Element, das nicht getauscht wurde
    // also dem element welches größer als pivot ist arr[i+1]
    swap(&array[i + 1], &array[last_element]);

    // return the partition point -> stelle/index des einsortierten pivot elements
    return (i + 1);
}


void quickSort(short array[], int first_element, int last_element) {
    if (first_element < last_element) { //kontrolliert ob letztes element wirklich kleiner als erstes element ist
        // return the partition point -> index des einsortierten pivot elements
        int pivot = partition(array, first_element, last_element);
//recursive funktion: macht partition für alle elemente links vom pivot element
        quickSort(array, first_element, pivot - 1);


//recursive funktion: macht partition für alle elemente rechts vom pivot element
        quickSort(array, pivot + 1, last_element);
    }
}
