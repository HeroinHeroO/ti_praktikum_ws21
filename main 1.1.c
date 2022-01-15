#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "littlehelpers.h"

/*  1.1 BASISIMPLEMENTIERUNG
        Schreiben Sie ein Programm indem sie die folgenden vier Algorithmen die ein Array aufsteigend
        sortieren sollen implementieren:
            a) Mergesort
            b) Quicksort
            c) Bubblesort
            d) Insertionsort
        Das Array soll mit Zufallswerten initialisiert werden, wobei die Zahlen zwischen -32.768 und 32.767
        liegen sollen. Die Initialisierung soll in einer eigenen Funktion gemacht werden. Verwenden Sie dafür
        Pointer in einer geeigneten Art und Weise. Führen Sie die Sortierfunktionen mit drei unterschiedlich
        großen Arrays aus (8, 16, und 64 Elemente). Implementieren Sie eine Funktion, die überprüft ob das
        Ergebnis tatsächlich sortiert ist. Geben Sie im Fehlerfall eine entsprechende Meldung aus.
        Als Ergebnis sind die unsortierten und sortieren Arrays in der Konsole auszugeben. Stellen Sie dabei
        sicher, dass in jeder Zeile nur maximal 15 Zahlen ausgedruckt werden um die Leserlichkeit zu
        erhöhen.*/
/*
int main() {

    srand(time(NULL));
    short *array_eight = fill_array_rnd(8);
    short *array_sixteen = fill_array_rnd(16);
    short *array_sixtyfour = fill_array_rnd(64);

    //BUBBLESORT
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

    //MERGESORT
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

    //INSERTIONSORT
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

    //QUICKSORT
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
}*/