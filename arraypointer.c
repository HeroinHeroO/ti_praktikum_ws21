//
// Created by Dell on 29.12.2021.
//

/*
 * Was gemacht werden soll:
Das Array soll mit Zufallswerten initialisiert werden, wobei die Zahlen zwischen  -32.768 und 32.767
liegen sollen. Die Initialisierung soll in einer eigenen Funktion gemacht werden. Verwenden Sie dafür
        Pointer in einer geeigneten Art und Weise. Führen Sie die Sortierfunktionen mit drei unterschiedlich
        großen Arrays aus (8, 16, und 64 Elemente). Implementieren Sie eine Funktion, die überprüft ob das
        Ergebnis tatsächlich sortiert ist. Geben Sie im Fehlerfall eine entsprechende Meldung aus.
Als Ergebnis sind die unsortierten und sortieren Arrays in der Konsole auszugeben. Stellen Sie dabei
        sicher, dass in jeder Zeile nur maximal 15 Zahlen ausgedruckt werden um die Leserlichkeit zu
        erhöhen.

Was der Code macht:
initialisiert  Array [größe kann angeben werden ] mit Zufallswerten von -32.768 bis 32.767



*******************************************************************************/

#include <stdio.h>
#include <time.h>

int make_random_array(int arraysize)
{
    int *testarray= (int*) malloc(arraysize * sizeof(int));

    //initialisiert rand ; time(NULL)return the number of seconds since about midnight 1970-01-0
    srand(time(NULL));
    int min= -32768;
    int max = 32767;

    for (int i =0; i<=arraysize;i++) {
        //rand: pseudorandom number -> range -3276 (min) - 32767(max) ;
        testarray[i] = (rand()%(max-min+1))+min;

    }
    // nur zum Testzwecken:
    for (int i =0; i<=arraysize;i++) {
        printf("zahl %d : %d \n", i, testarray[i]);
    }

    return testarray;
}

int main(){
    int arraysize;
    printf("Wie viele Elemente soll das Array haben? :");
    scanf("%d" , &arraysize);
    make_random_array(arraysize);
    return 0;
}
