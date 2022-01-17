#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "littlehelpers.h"

/*  1.2 LEISTUNGSVERGLEICH
        Schreiben Sie ein Programm, mit dem die Sortieralgorithmen in ihrem Laufzeitverhalten verglichen
        werden können. Führen Sie die Sortierfunktionen mit unterschiedlich großen Arrays und
        unterschiedlichen Daten aus. Um die Performanz beurteilen zu können, soll die jeweilige Laufzeit der
        Sortierung getrackt werden – für jede Größe der Arrays. Um eine Vergleichbarkeit sicher zu stellen,
        sollen in einem Durchlauf alle Algorithmen mit den gleichen Ausgangsdaten versorgt werden.
            • Arraygrößen: 8, 32, 128, 512, 2048, 8192, 327681
            • Datensätze:
                o aufsteigend
                o absteigend
                o zufällig
        Verwenden Sie dafür die clock() Funktion um die Laufzeit der jeweiligen Sortierung zu speichern..
        Geben Sie zusätzlich am Ende des Programms alle Laufzeiten von allen Sortierfunktionen für die
        jeweilige Arraygröße aus. Geben Sie diese Informationen tabellarisch aus um auf den ersten Blick
        eine Beurteilung hinsichtlich der Performanz treffen zu können. Wählen Sie dazu eine geeignete
        Maßeinheit.*/

int main() {

    int arraysize[] = {8, 32, 128, 512, 2048, 8192, 32768};
    clock_t start_t, end_t, total_t;

    FILE *fp;

    fp = fopen("leistungsvergleich.txt", "w+");


    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp,"Algorithmus:\t\tArray\t\t Zeit\n");


    //BUBBLESORT

    //random
    double vergleichprint[7];
    for (int i = 0; i < 7; i++) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_rnd(arraysize[i]);
        start_t = clock();
        bubble_sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: bubblesort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);

    }
    //aufsteigend
    for (int i = 0; i < 7; i++) {
        short *array_x = fill_array_asc(arraysize[i]);
        start_t = clock();
        bubble_sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: bubblesort\t\tArray: aufsteigend \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }
    //absteigend
    for (int i = 0; i < 7; i++) {
        short *array_x = fill_array_des(arraysize[i]);
        start_t = clock();
        bubble_sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: bubblesort\t\tArray: absteigend \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }

    //INSERTIONSORT

    //random
    for (int i = 0; i < 7; i++) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_rnd(arraysize[i]);
        start_t = clock();
        insertion_Sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: insertionsort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }
    //aufsteigend
    for (int i = 0; i < 7; i++) {
        short *array_x = fill_array_asc(arraysize[i]);
        start_t = clock();
        insertion_Sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: insertionsort\t\tArray: aufsteigend \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }
    //absteigend
    for (int i = 0; i < 7; i++) {
        short *array_x = fill_array_des(arraysize[i]);
        start_t = clock();
        insertion_Sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: insertionsort\t\tArray: absteigend \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }

    //MERGESORT

    //random
    for (int i = 0; i < 7; i++) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_rnd(arraysize[i]);
        start_t = clock();
        merge_Sort(array_x,0, arraysize[i] - 1) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: mergesort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }
    //aufsteigend
    for (int i = 0; i < 7; i++) {
        short *array_x = fill_array_asc(arraysize[i]);
        start_t = clock();
        merge_Sort(array_x,0, arraysize[i] - 1) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: mergesort\t\tArray: aufsteigend \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }
    //absteigend
    for (int i = 0; i < 7; i++) {
        short *array_x = fill_array_des(arraysize[i]);
        start_t = clock();
        merge_Sort(array_x,0, arraysize[i] - 1) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: mergesort\t\tArray: absteigend \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }

    //QUICKSORT

    //random
    for (int i = 0; i < 7; i++) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_rnd(arraysize[i]);
        start_t = clock();
        quickSort(array_x, 0, arraysize[i] - 1) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: quicksort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }

    //aufsteigend - crashes when sorting arraysize 32768!
    for (int i = 0; i < 6; i++) {
        short *array_x = fill_array_asc(arraysize[i]);
        start_t = clock();
        quickSort(array_x, 0, arraysize[i] - 1) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: quicksort\t\tArray: aufsteigend \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }

    //absteigend - crashes when sorting arraysize 32768!
    for (int i = 0; i < 6; i++) {
        short *array_x = fill_array_des(arraysize[i]);
        start_t = clock();
        quickSort(array_x, 0, arraysize[i] - 1); //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        vergleichprint[i] = total_t;
        fprintf(fp, "Algorithmus: quicksort\t\tArray: absteigend \t\t arraysize: %d \t\tZeit: %f\n", arraysize[i], vergleichprint[i]);
    }
    fclose(fp);
}