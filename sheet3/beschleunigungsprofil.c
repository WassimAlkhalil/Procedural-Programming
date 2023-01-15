#include <stdio.h>
#include <math.h>

int main(void)
{
    /*
    1. Beschleunigungsprofil
    */ 

    //Eingabe/Ausgabe Parameter

    double p0, p1, p2;

    printf("Geben sie einen Wert für p0 an: ");
    scanf("%lf", &p0);
    printf("Geben sie einen Wert für p1 an: ");
    scanf("%lf", &p1);
    printf("Geben sie einen Wert für p2 an: ");
    scanf("%lf", &p2);
    printf("\na(t) = %.2f*t^2 + %.2f*t + %.2f \n", p2, p1, p0);

    //Berechnung der Beschleunigungen zu bestimmten Zeitpunkten  

    double t0, t1, beschleunigung_to, beschleunigung_t1;

    t0 = 0.0;
    beschleunigung_to = p2 * pow(t0, 2) + p1 * t0 + p0;
    t1 = 3.0;
    beschleunigung_t1 = p2 * pow(t1, 2) + p1 * t1 + p0;

    printf("\n3.1-2)\nAnfangsbeschleinigung bei t0 = %.2fs: %.2f ms^-2 \n", t0, beschleunigung_to);
    printf("Beschleunigung bei t1 = %.2fs: %.2f ms^-2 \n", t1, beschleunigung_t1);

    //Berechnung der Maximalbeschleunigung -> Überprüfen auf Maximum

    float tmax, atmax;
    tmax = (-p1)/(2*p2);
    atmax = p2*tmax*tmax + p1*tmax + p0;
    printf("\n3.1-3)\nMaximale Beschleunigung bei t=%.2f: %.2f ms^-2", tmax, atmax);

    
    float second_derivative_checkmax = 2 * p2; // Da der wert der zweiten ableitung kleiner als 0 ist, handelt es sich um Maximum
    printf("\nDa der wert der zweiten ableitung kleiner als 0 ist, handelt es sich um Maximum = %.2lf", second_derivative_checkmax);






    /*
    2. Der Weg ist das Ziel 
    */
    // Berechnung der Zeit t2 -> sqrt(x) 

    double a_const = 0.5;
    double t2;
    t2 = -(-4/2) + sqrt((4/2)*(4/2)+1);
    printf("t2 = %.2lfs\n", t2);

    // Berechnung der Geschwindigkeit zum Endzeitpunkt te = 20s

    printf("Berechnung der Geschwindigkeit am Endzeitpunkt t=20 \n");
     
     float te = 20.0;
     float t = te - t2;
     float v0 = 20.0;
     float v = a_const*t + v0;

     printf("Geschwindigkeit am Zeitpunkt t=20: %.2lf \n", v);

    // Berechnung des zurückgelegten Weges
    

    printf("\nEingaben der Zeit t in s: ");
    scanf("%f", &t);
            
    float distance;    

    float s0 = 1; 
    if (t > t2 && te >= t)   
    {                   
        distance = (1 / 2) * a_const * t*t + v0 * t + s0; 
        printf("Zuruckgelegter Weg = %.2f m\n", distance);
    }
    else
    {
        printf("Please consider the interval t2 < t <= te\n");
    }


    return 0;
}