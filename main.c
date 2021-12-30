#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

short* fill_array_rnd(unsigned int arr_size) {
    short *array = (short *)malloc(sizeof(short ) * arr_size);
    if (array = NULL) {
        return -1;
    }

    for (int i = 0; i < arr_size; i++) {
        *(array +i) = rand() - (RAND_MAX / 2);
    }
    return array;
}

int main(){

    srand(time(NULL));
    short *array_eight = fill_array_rnd(8);
    short *array_sixteen = fill_array_rnd(16);
    short *array_sixtyfour = fill_array_rnd(64);

    bubble_sort(array_eight, 8);

    for (int i = 0; i < 64; i++) {
        if(i<8) {
            printf("eight: %d: %i\n", i, array_eight[i]);
        }
        if(i<16){
            printf("sixteen: %d: %i\n", i, array_sixteen[i]);
        }
        printf("sixtyfour: %d: %i\n", i, array_sixtyfour[i]);
    }
    free(array_eight);
    free(array_sixteen);
    free(array_sixtyfour);

    return 0;
}