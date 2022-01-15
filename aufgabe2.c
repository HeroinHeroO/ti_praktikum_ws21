

/*2.1 SORTIEREN UND SUCHEN – SELBST IMPLEMENTIERT
Schreiben Sie ein Programm, das Sortieren und Suchen verbindet. Erweitern Sie dazu einen3 der von
Ihnen implementierten Suchalgorithmen in einer neuen Version so, dass jedes Element in dem Array
um einen String erweitert wird. Lösen Sie das über eine struct. Generieren Sie 400 Elemente dieser
Struktur und initialisieren Sie die Integer und String Variablen mit Zufallswerten. Die Strings können
dabei eine beliebige Länge haben.
Geben Sie dem Benutzer die Möglichkeit nach einem Element der Liste zu suchen (entweder nach
Schlüssel, also dem Integer oder nach dem String-Wert). Implementieren Sie die Suche nach dem
Element mit einer selbstgeschriebenen binären Suchfunktion. Zeigen Sie dem Benutzer abschließend
das Ergebnis der Suche (hit oder miss). Es soll möglich sein wiederholt zu suchen*/



#include<stdio.h>
#include<string.h>
#include <stdlib.h>


const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";

/// create a randomstring
char *randomString(int len) {
    char *rstr = malloc((len + 1) * sizeof(char));
    int i;
    for (i = 0; i < len; i++) {
        rstr[i] = alphabet[rand() % strlen(alphabet)];
    }
    rstr[len] = '\0';
    return rstr;
}

/// struct with including int and string
struct word_and_key {
    int key;
    char random_string[10];
};


/// bubblesort sorting strings from the struct array
void bubble_Strings(struct word_and_key arr[400], int n) {
    char temp[400];
    // Sorting strings using bubble sort
    for (int j = 0; j < n - 1; j++) {
        for (int i = j + 1; i < n; i++) {
            if (strcmp(arr[j].random_string, arr[i].random_string) > 0) {
                strcpy(temp, arr[j].random_string);
                strcpy(arr[j].random_string, arr[i].random_string);
                strcpy(arr[i].random_string, temp);
            }
        }
    }
}

/// bubblesort sorting  the integers from the struct array
void bubble_sort_int(struct word_and_key array[400], unsigned int size) {
    for (int i = 0; i < (size - 1); i++) {                   // look at each array element.
        for (int j = 0; j < (size - i - 1); j++) {          // compare array elements.
            if (array[j].key > array[j + 1].key) {         // sort ascending. Change to < for descending sort.
                int tmp = array[j].key;
                array[j].key = array[j + 1].key;
                array[j + 1].key = tmp;
            }
        }
    }
}

/// binary Searchfunction for integers
/// left = 0, right = n-1, s_elment_elment = the elment you want to searcch for
/// returns index of element
int binarySearch_int(struct word_and_key arr[], int left, int right, int s_element) {
    while (left <= right) {
        int m = left + (right - left) / 2; //m = middle element
        if (arr[m].key == s_element) {
            return m;
        }
        if (arr[m].key < s_element) {
            left = m + 1;
        } else {
            right = m - 1;
        }
    }
    return -1;// if not found
}

/// binary Searchfunction for strings
/// left = 0, right = n-1, s_elment_elment = the elment you want to search for
/// returns index of element
int binarySearch_str(struct word_and_key arr[], int left, int right, char *s_string) {
    while (left <= right) {
        int m = left + (right - left) / 2;
        if (strcmp(arr[m].random_string, s_string) == 0) {
            return m;
        }
        if (strcmp(arr[m].random_string, s_string) < 1) {
            left = m + 1;
        } else {
            right = m - 1;
        }
    }
    return -1;// if not found
}

int main(void) {
    int counter;
    struct word_and_key element_array[400];
    char c;

    ///makes a struct array with 400 elments: key->random num; str->random str
    for (counter = 0; counter < 400; counter++) {
        element_array[counter].key = rand() % 3000;//counter
        strcpy(element_array[counter].random_string, randomString(4));

    }

    do {
        ///search for a string:

        /// first: sort elements of the array after their string value
        printf("sort strings \n");
        bubble_Strings(element_array, 400);

        ///control if it worked
        printf("first 10 strings \n");
        for (counter = 0; counter < 10; counter++) {
            printf("\nkey:%d\t String:%s\t ",
                   element_array[counter].key, element_array[counter].random_string);
        }
        printf("next \n");

        ///ask for user input
        char *sear_string = malloc(sizeof(char) * 10);//get string
        printf("enter string you want to search for \n");
        scanf("%s", sear_string);


        ///binary search for the string
        int resultstr = binarySearch_str(element_array, 0, 400, sear_string);
        if (resultstr == -1) {
            printf("str Miss\n");
        } else {
            printf(" Hit \n result index [%d] ", resultstr);
        }
        free(sear_string);



        /// search for int/key:

        /// first: sort elements of the array after their int value
        printf("sort integers \n");
        bubble_sort_int(element_array, 400);
        int searched_int;

        ///print first 10 elements to control if it worked
        printf("first 10 elements \n");
        for (counter = 0; counter < 10; counter++) {

            printf("\nkey:%d\t String:%s\t ",
                   element_array[counter].key, element_array[counter].random_string);
        }

        ///ask for user input
        printf("Enter the number that should be searched \n");
        scanf("%d", &searched_int);

        /// binary search for the value
        //binary search return -1 if miss else it returns index
        int resultint = binarySearch_int(element_array, 0, 400, searched_int);
        if (resultint == -1) {
            printf("Miss\n");
        } else {
            printf(" Hit \n result index [%d] ", resultint);
        }


        /// ask if user wants to continue
        printf("Do you want to continue? press y \n");
        getchar();
        scanf("%c", &c);
    } while (c == 'y');

    return 0;
}

