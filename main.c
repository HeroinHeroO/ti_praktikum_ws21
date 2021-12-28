#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array_rnd(short array[], unsigned int arr_size) {
    srand(time(NULL));

    for (int i = 0; i < arr_size; i++) {
        array[i] = rand() - (RAND_MAX / 2);
    }
}

int main(){
    short array_eight[8], array_sixteen[16], array_sixtyfour[64];

    fill_array_rnd(array_eight, 8);
    fill_array_rnd(array_sixteen, 16);
    fill_array_rnd(array_sixtyfour, 64);


    return 0;
}