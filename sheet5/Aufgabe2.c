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

/*
    int Array[100];
    for(int i = 0; i < 100; i++){
        Array[i] = rand();
    }

*/


//Bubble-Sort-Algorithmus



int durchlauf = 0;

int g;
printf("Please choose 1 if you want absteigend otherwise 0: ");
scanf("%d", &g);

bool done = false;
switch (g)
{
     case 1:
     
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
        break;
     ;
     case 0:
        while(!done)
        {
            done = true;
            for (int i = 0; i < length-1; i++)
            {
                if (Array[i] > Array[i+1])
                {
                    done = false;
                    int temp = Array[i];
                    Array[i] = Array[i+1];
                    Array[i+1] = temp;
                }
            }
            durchlauf++;
        }
        break;
     ;
     default:
        printf("Please choose 1 or 0\n");
}





//Ausgabe des Ergebnisses im Terminal


printf("\nBubble Sort\n"); 
printf("End Array: ");    
    for (int k = 0; k < length; k++) {     
        printf("%d ", Array[k]);     
    }  
   
printf("\nNumber of durchlaeufe: %d", durchlauf);  

//Selection-Sort-Algorithmus


int z;
printf("\nPlease choose 1 for the Selection Sort algorithm if you want absteigend, otherwise 0: ");
scanf("%d", &g);


switch (z)
{
     case 1:
       for (int i = 0; i < length -1; i++)
                        {
                            int min_pos = i;
                            for (int j = i + 1; j < length ; j++)
                            {
                            if (Array[j] < Array[min_pos])
                            {
                                min_pos = j;
                            } 
                            }
                            if (min_pos != i)
                            {
                            int temp = Array[i];
                            Array[i] = Array[min_pos];
                            Array[min_pos] = temp;
                            }
                            durchlauf++;
                        }
     
        break;
     ;
     case 0:
     
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
              
            break;
     ;
     default:
        printf("Please choose 1 or 0\n");
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