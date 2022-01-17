#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "littlehelpers.h"

/*  1.3 VERGLEICHBARKEIT
        Schreiben Sie ein Programm, das zeigt, dass einmalige Codedurchläufe nur beschränkt für
        Zeitvergleiche aussagekräftig2 sind. Führen Sie den Bubblesort mit dem gleichen zufälligen Set an
        Daten mit einer Arraygröße von 2000 zwanzigmal aus und vergleichen Sie die Laufzeiten.
        Geben Sie am Ende des Programms alle Laufzeiten sowie minimum, maximum und durchschnittliche
        Laufzeiten aus */
/*
int main() {
    clock_t start_t, end_t, total_t;
    double runtime[20];

    for (int i = 0; i <= 20; i++) {
        srand(10);
        short *array_x = fill_array_rnd(2000);
        //print_array(array_x, arraysize[i]); //check if same data is created
        //printf("\nARRAY END\n");
        start_t = clock();
        bubble_sort(array_x, 2000); //arraysize[i] = {8,...}
        end_t = clock();
        free(array_x);
        total_t = (double) (end_t - start_t);
        runtime[i] = total_t;

    }
    for (int i = 0; i < 20; i++) {
        printf("[%f] ", runtime[i]);
    }
    bubble_sort_double(runtime, 20);
    double avg = 0;
    double *avgP = &avg;
    for (int i = 0; i < 20; i++) {
        *avgP += runtime[i];
        if (i == 19) {
            *avgP = avg / 20;
        }
    }
    printf("\nShortest: %f\nLongest: %f\nAverage: %f\n", runtime[0], runtime[19], avg);
}*/