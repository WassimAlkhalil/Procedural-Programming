#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_START 1
//Einbinden der Header stdlib.h und time.h

int main(void) 
{
    srand(time(NULL));
    /*
    Aktivierung des Start-Schalter
    */
    int startbutton = false;
    
    printf("Zum starten 1 drücken\n");
    scanf("%d", &startbutton);

    /*
    Variablen initialisieren */

    int filler_output = 100;    // m_IN -- MASSE DES SCHÜTTGUTS
    int container_target_mass[2] = {500, 550};    //  m_soll wie viele gewicht in dem Behälter rein soll
    int release_mass = 50;    // m_out wie viel rausgelassen wird wenns nicht im toleranz bereich ist
    float container = 0.0; //[0,10], [50,55], [0,5]   
    float filled_container[10]; 
    float mass_average = 0;
    
    /*
    Befüllen der Schüttgutbehälter
    - Verwenden von while- und do-while-Schleifen zum Befüllen und Ablassen des Schüttgut
    - Verwenden einer for-Schleife, um insgesamt 10 Behälter zu befüllen
    */

    if(startbutton){
        printf("Start\n\n");
        for(int i = 1; i <= 10; i++){
            
            printf("Befüllung Behälter %d\n", i);
            while(container <= container_target_mass[0]/10){    //50 
                float current_fill_mass = rand() % filler_output;
                container += current_fill_mass/10;
            }

            if(container > container_target_mass[1]/10){  //55
                printf("Gewicht überschritten\nöffne Ablassstutzen\n");
            }
            while(container > container_target_mass[1]/10){
                float current_release_mass = rand() % release_mass;
                container -= current_release_mass/10;
            }

            printf("Behälter %d befüllt mit %.1fkg\n\n", i, container);
            filled_container[i-1] = container;
            mass_average += container/10;
            container = 0.0;
        }
    }
    
    /*
    Prozess abschließen -> Ausgabe im Terminal*/    
    printf("Mittelwert aller Behälter: %.1fkg\nalle Behälter:\n", mass_average);
    for(int i = 1; i <= 10; i++){
        printf("%.1f, ", filled_container[i-1]);
    }

    printf("\n\nready");

    return 0;
}