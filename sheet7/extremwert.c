#include <stdio.h>

//sonstige Header
#include <math.h>
#define POLDEG 4
#define ITERATIONDEPTH 10

//Konstanten definieren
double a[POLDEG] = {-0.1, 0, -1, 0.375};
int x[POLDEG] = {1, 2, 3, 4};

//Funktionen
int dpoly1(int n, double *a, int *x){
  for(int i = 1; i <= n; i++){
    a[i-1] = i * a[i-1];
    x[i-1] = i - 1;
  }

  return 0;
}

int dpoly2(int n, double *a, int *x){
  for(int i = 1; i <= n; i++){
    a[i-1] = i * (i-1) * a[i-1];
    x[i-1] = i - 2;
  }

  return 0;
}

int bisection(double *intervall, double *a, int *x, int len){
  double value_1 = 0, value_2 = 0;
  double tmparr[2] = {intervall[0], (intervall[0]+intervall[1])/2};

  for(int i = 0; i < len; i++){
    value_1 += a[i] * pow(tmparr[0], x[i]);
  }

  for(int i = 0; i < len; i++){
    value_2 += a[i] * pow(tmparr[1], x[i]);
  }

  if((value_1 > 0 && value_2 < 0) || (value_1 < 0 && value_2 > 0)){
    intervall[1] = tmparr[1];
    return 0;
  }
  else if(value_1 == 0){
    intervall[0] = tmparr[0];
    intervall[1] = tmparr[0];
  }
  else if(value_2 == 0){
    intervall[0] = tmparr[1];
    intervall[1] = tmparr[1];
  }
  else{
    tmparr[1] = intervall[1];
    tmparr[0] = (intervall[0]+intervall[1])/2;

    for(int i = 0; i < len; i++){
      value_1 += a[i] * pow(tmparr[0], x[i]);
    }

    for(int i = 0; i < len; i++){
      value_2 += a[i] * pow(tmparr[1], x[i]);
    }
    if(value_1 == 0){
      intervall[0] = tmparr[0];
      intervall[1] = tmparr[0];
    }
    else if(value_2 == 0){
      intervall[0] = tmparr[1];
      intervall[1] = tmparr[1];
    }
    else{
      intervall[0] = tmparr[0];
    }
  }

  return 0;
}

//Hauptprogramm
int main(void)
{

    //Initialisierung
    double a_1[POLDEG] = {-0.1, 0, -1, 0.375};
    double a_2[POLDEG] = {-0.1, 0, -1, 0.375};
    int x_1[POLDEG] = {1, 2, 3, 4};
    int x_2[POLDEG] = {1, 2, 3, 4};
    double intervall[2] = {-1.5, 3};
    double extreme = 2, deriv_2 = 0;
    
    //Berechnung Extremwert
    dpoly1(POLDEG, &a_1, &x_1);
    dpoly2(POLDEG, &a_2, &x_2);

    for(int i = 0; i < ITERATIONDEPTH; i++){
      bisection(&intervall, &a_1, &x_1, sizeof(a)/sizeof(a[0]));
    }

    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
      extreme += a[i] * pow((intervall[0] + intervall[1])/2, x[i]);
      deriv_2 += a_2[i] * pow((intervall[0] + intervall[1])/2, x_2[i]);
    }

    //Ausgabe im Terminal
    printf("Extremum: %f bei x = %f\n", extreme, (intervall[0] + intervall[1])/2);
    
    if(deriv_2 > 0){
      printf("Es handelt sich um ein Minimum!\nf\'\'(%.2f) = %f", (intervall[0] + intervall[1])/2, deriv_2);
    }
    else if(deriv_2 < 0){
      printf("Es handelt sich um ein Maximum!");
    }
    else{
      printf("Es kann keine Aussage getroffen werden!");
    }

  return 0;
}