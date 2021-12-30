//
//sortsalgorithmen
//
// Insertion sort in C

#include <stdio.h>


void insertion_Sort(int array[], int arraysize){
    //geht alle Elemente des arrays durch
   //element startet beim 2ten elment des arrays
    for (int i = 1; i<arraysize; i++ ){
        int element = array[i];
        int j = i-1; //index vom vergleichs element links vom "element"


        // alle linken  vergleichselemente vor "element" (arr [0- ...i-1])
        // mit vergleichselment> "element"
        // werden nach rechts verschoben;

        while (  array[j]> element  && j>= 0){
            array[j+1] = array[j]; // linkes element wird ein nach rechts verschoben
            --j; // j index zeigt auf ein element weiter links

        }
        array[j+1] = element;
        // wenn linke vergleichs_elmente > "element" ,
        // dann wird "element"  eins vor letzen vergleichs_elment gesetzt
        //Ansonsten bleibt "element" auf dem selbem index

    }

}



