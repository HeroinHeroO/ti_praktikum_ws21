#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array_rnd(short *array, unsigned int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        *(array +i) = rand() - (RAND_MAX / 2);
    }
}

int main(){
    short array_eight[8] = {}, array_sixteen[16] = {}, array_sixtyfour[64] = {};
    short *array_8p = array_eight;
    short *array_16p = array_sixteen;
    short *array_64p = array_sixtyfour;

    srand(time(NULL));
    fill_array_rnd(array_8p, 8);
    fill_array_rnd(array_16p, 16);
    fill_array_rnd(array_64p, 64);

    for (int i = 0; i < 46; i++) {
        if(i<8) {
            printf("eight: %d: %i\n", i, array_eight[i]);
        }
        if(i<16){
            printf("sixteen: %d: %i\n", i, array_sixteen[i]);
        }
        printf("sixtyfour: %d: %i\n", i, array_sixtyfour[i]);
    }


    return 0;
}