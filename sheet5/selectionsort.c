//Include Header
#include <stdio.h>
#include <stdbool.h>

//Beginn Hauptprogramm
int main (void) {
    /*
Einlesen des Array aus externer Datei:
Durch das Umleiten der Standardeingabe wird wie gewohnt scanf(...) verwendet. Mit dem Unterschied, 
dass Sie die Eingabe nicht mehr über die Tastatur tätigen, sondern diese automatisch von der Datei erfolgt.

Lesen Sie zunächst die Anzahl der Einträge des Array ein.
Lesen Sie als nächstes die einzelnen Einträge des Array ein. 
Verwenden Sie beim Ausführen der Datei den <-Operator.
Die Syntax im Terminal lautet:
program < datei
*/

int length;
printf("The array is being processed....\n");
scanf("%d", &length);
int Array[length];

for (int i = 0; i < length; i++)
{
    scanf("%d", &Array[i]);
}


//Selection-Sort-Algorithmus


int durchlauf = 0;


for (int i = 0; i < length -1; i++)
{
    int max_pos = i;
    for (int j = i + 1; j < length ; j++)
    {
       if (Array[j] > Array[max_pos])
       {
        max_pos = j;
       } 
    }
    if (max_pos != i)
    {
       int temp = Array[i];
       Array[i] = Array[max_pos];
       Array[max_pos] = temp;
    }
    durchlauf++;
}



//Ausgabe des Ergebnisses im Terminal

printf("\nSelection Sort\n"); 
printf("End Array: ");    
    //Loop through the array by incrementing value of i     
    for (int k = 0; k < length; k++) {     
        printf("%d ", Array[k]);     
    }  
  
printf("\nNumber of durchlaeufe: %d", durchlauf);  

//Ende Hauptprogramm
    return 0;
}

