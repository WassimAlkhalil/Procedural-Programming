#include <stdio.h>
#include <string.h>

int main (void){

    //Eckdaten einlesen

    int Anzahl;
    printf("The file is being processed....\n");
    scanf("%d", &Anzahl);


    //Variablen definieren

    char data[Anzahl] [100];
    char id[Anzahl] [9];
    char * datetmp1;
    char * datetmp2;
    char * datetmp3;
    char * token;
    const char * sign = ":";
    const char * sign2 = ".";
    char * tmp;

    //char kennung1[];

    for (int i = 0; i < Anzahl; i++)
    {
        scanf("%s", data[i]);
        printf("%s", data[i]);

        token = strtok(data[i], sign);
        for(int x = 0; x < 3; x++){
            id[i][x] = token[0];
            token = strtok(NULL, sign);
        }

        datetmp1 = strtok(token, sign2);
        datetmp2 = strtok(NULL, sign2);
        datetmp3 = strtok(NULL, sign2);
        strcat(id[i], datetmp3);
        strcat(id[i], datetmp2);
        strcat(id[i], datetmp1);
        printf("%s:%s \n", id[i], data[i]);
    }


    //Zeilenweise einlesen der data.in-Datei
   
    //Extrahieren der Nutzerkennung -> Verwendung von strtok()


    //Ausgabe in Datei erzeugen

    return 0;
}
