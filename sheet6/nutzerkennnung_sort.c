#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>




int main(void) {
    int const Maxcolcount = 100;
    FILE *fPointer;
    char data[10][Maxcolcount];
    char rowCountStr[Maxcolcount];

    fPointer = fopen("kennungen_temp.dat", "r");

    if (fPointer == NULL)
    {
        printf("can not be opened");
        return 0;
    }

    // reading the lines zeilenweise
    char line[Maxcolcount];
    unsigned k = 0;

    while (fgets(line, 100, fPointer) != NULL)
    {
        unsigned line_length = strlen(line);

        for (unsigned j = 0; j < line_length; j++)
            data[k][j] = line[j];

        k++; 
        // clearing

        memset(line, 0, sizeof(line));
    }

    fclose(fPointer);

    //selection sort

    char str[Maxcolcount];
    unsigned rows = (sizeof(data) / sizeof(data[0]));
    unsigned cols = (sizeof(data) / rows / sizeof(data[0][0]));
    int minindex;

    for (unsigned i = 0; i < rows; i++) {
        minindex = i;

        strcpy(str, data[i]);

        for (unsigned j = i; j < rows; j++) {
            int result = strcmp(data[j], str);

            if (result < 0) {
                strcpy(str, data[j]);
                minindex = j;
            }
        }

        char temp[100];
        strcpy(temp, data[i]);
        strcpy(data[i], data[minindex]);
        strcpy(data[minindex], temp);
    }

    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            if (data[i][j] == '\n')
                break;
           
            printf("%c ", data[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}