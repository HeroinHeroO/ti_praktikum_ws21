#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "littlehelpers.h"



int main(){

    // 1.1 BASISIMPLEMENTIERUNG

    srand(time(NULL));
    short *array_eight = fill_array_rnd(8);
    short *array_sixteen = fill_array_rnd(16);
    short *array_sixtyfour = fill_array_rnd(64);

    //BUBBLESORT
    /*printf("BUBBLESORT:\n");
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
    free(array_sixtyfour); */

    //1.2 LEISTUNGSVERGLEICH


    int arraysize[] ={8, 32, 128, 512, 2048, 8192, 32768};
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
    for (int i = 0; i < 7; ++i) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_rnd(arraysize[i]);
        //print_array(array_x, arraysize[i]); //check if same data is created
        //printf("\nARRAY END\n");
        start_t = clock();
        bubble_sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: bubblesort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }
    //aufsteigend
    for (int i = 0; i < 7; ++i) {
        short *array_x = fill_array_asc(arraysize[i]);
        start_t = clock();

        bubble_sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();

        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: bubblesort\t\tArray: aufsteigend \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }
    //absteigend
    for (int i = 0; i < 7; ++i) {
        short *array_x = fill_array_des(arraysize[i]);
        start_t = clock();
        bubble_sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: bubblesort\t\tArray: absteigend \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }

    //INSERTIONSORT
    for (int i = 0; i < 7; ++i) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_rnd(arraysize[i]);
        //print_array(array_x, arraysize[i]); //check if same data is created
        //printf("\nARRAY END\n");
        start_t = clock();
        insertion_Sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: insertionsort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }
    //aufsteigend
    for (int i = 0; i < 7; ++i) {
        short *array_x = fill_array_asc(arraysize[i]);
        start_t = clock();

        insertion_Sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();

        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: insertionsort\t\tArray: aufsteigend \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }
    //absteigend
    for (int i = 0; i < 7; ++i) {
        short *array_x = fill_array_des(arraysize[i]);
        start_t = clock();
        insertion_Sort(array_x, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: insertionsort\t\tArray: absteigend \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }

    //MERGESORT
    for (int i = 0; i < 7; ++i) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_rnd(arraysize[i]);
        //print_array(array_x, arraysize[i]); //check if same data is created
        //printf("\nARRAY END\n");
        start_t = clock();
        merge_Sort(array_x,0, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: mergesort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }
    //aufsteigend
    for (int i = 0; i < 7; ++i) {
        short *array_x = fill_array_asc(arraysize[i]);
        start_t = clock();

        merge_Sort(array_x,0, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();

        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus:mergesort\t\tArray: aufsteigend \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }
    //absteigend
    for (int i = 0; i < 7; ++i) {
        short *array_x = fill_array_des(arraysize[i]);
        start_t = clock();
        merge_Sort(array_x,0, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: mergesort\t\tArray: absteigend \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }

   //QUICKSORT
    for (int i = 0; i < 7; ++i) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_rnd(arraysize[i]);
        //print_array(array_x, arraysize[i]); //check if same data is created
        //printf("\nARRAY END\n");
        start_t = clock();
        quickSort(array_x, 0, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: quicksort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }
    /*//aufsteigend
    for (int i = 0; i < 7; ++i) {
        short *array_x = fill_array_asc(arraysize[i]);
        start_t = clock();

        quickSort(array_x, 0, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();

        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus:quicksort\t\tArray: aufsteigend \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);
    }
   //absteigend
    for (int i = 0; i < 7; ++i) {
        srand(10); //set seed to 10 to recreate fill data
        short *array_x = fill_array_des(arraysize[i]);
        //print_array(array_x, arraysize[i]); //check if same data is created
        //printf("\nARRAY END\n");
        start_t = clock();
        quickSort(array_x, 0, arraysize[i]) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // number of seconds the function used  CLOCKS_PER_SEC -> Dividing a count of clock ticks by this expression yields the number of seconds
        fprintf(fp, "Algorithmus: quicksort\t\tArray: random \t\t arraysize: %d \t\tZeit: %f\n"
                ,arraysize[i],total_t);} */
    //other algorithmen
    fclose(fp);

    //1.3
    /*Schreiben Sie ein Programm, das zeigt, dass einmalige Codedurchläufe nur beschränkt für Zeitvergleiche aussagekräftig2 sind.
     * Führen Sie den Bubblesort mit dem gleichen zufälligen Set an Daten mit einer Arraygröße von 2000 zwanzigmal aus und vergleichen Sie die Laufzeiten.
Geben Sie am Ende des Programms alle Laufzeiten sowie minimum, maximum und durchschnittliche Laufzeiten aus.*/
    double runtime[20];
    for (int i = 0; i <= 20 ; ++i) {
        srand(10);
        short *array_x = fill_array_rnd(2000);
        //print_array(array_x, arraysize[i]); //check if same data is created
        //printf("\nARRAY END\n");
        start_t = clock();
        bubble_sort(array_x, 2000) ; //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double)(end_t - start_t);
        runtime[i] = total_t;

    }
    for (int i = 0; i < 20; i++) {
        printf("[%f] ", runtime[i]);
    }
    
}