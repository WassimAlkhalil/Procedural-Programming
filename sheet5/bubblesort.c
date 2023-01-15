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



//Bubble-Sort-Algorithmus



int durchlauf = 0;

bool done = false;
while(!done)
{
    done = true;
    for (int i = 0; i < length-1; i++)
    {
        if (Array[i] < Array[i+1])
        {
            done = false;
            int temp = Array[i];
            Array[i] = Array[i+1];
            Array[i+1] = temp;
        }
    }
    durchlauf++;
}

printf("\nBubble Sort\n"); 
printf("End Array: ");    
    for (int k = 0; k < length; k++) {     
        printf("%d ", Array[k]);     
    }  
   
printf("\nNumber of durchlaeufe: %d", durchlauf);  


//Ausgabe des Ergebnisses im Terminal

//Ende Hauptprogramm

    return 0;

}

