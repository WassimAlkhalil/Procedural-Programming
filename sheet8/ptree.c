#include <stdio.h>
#include <math.h>

// Function to draw a square in SVG format
void drawSquare(double x, double y, double sideLength) {
  printf("<rect x='%.2f' y='%.2f' width='%.2f' height='%.2f' />\n", x, y, sideLength, sideLength);
}

// Function to calculate the starting points of the squares
void calculatePoints(double *x, double *y, double hypotenuseLength, double angle, int depth) {
  if (depth == 0) {
    // Base case: starting point of the square is P(0|0)
    *x = 0;
    *y = 0;
  } else {
    // Recursive calculation of starting points
    double a = hypotenuseLength * sin(angle);
    double b = hypotenuseLength * cos(angle);
    double x1, y1;
    calculatePoints(&x1, &y1, a, angle, depth - 1);
    *x = x1 - b * sin(angle - M_PI / 2);
    *y = y1 - b * cos(angle - M_PI / 2);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Invalid number of arguments.\n");
    return 1;
  }

  // Read in input parameters
  double hypotenuseLength = atof(argv[1]);
  double angle = atof(argv[2]) * M_PI / 180;
  int depth = atoi(argv[3]);

  // Error avoidance: check if input parameters are valid
  if (hypotenuseLength <= 0 || angle <= 0 || angle >= M_PI || depth < 0) {
    printf("Invalid input parameters.\n");
    return 1;
  }

  // SVG header
  printf("<svg width='100%%' height='100%%' viewBox='-100 -100 200 200'>\n");

  // Calculate starting points and draw squares
  double x, y;
  calculatePoints(&x, &y, hypotenuseLength, angle, depth);
  drawSquare(x, y, hypotenuseLength);
  calculatePoints(&x, &y, hypotenuseLength * sin(angle), angle, depth - 1);
  drawSquare(x, y, hypotenuseLength * sin(angle));
  calculatePoints(&x, &y, hypotenuseLength * cos(angle), angle - M_PI / 2, depth - 1);
  drawSquare(x, y, hypotenuseLength * cos(angle));

  // SVG footer
  printf("</svg>\n");

  return 0;
}

/*
This program reads in three input parameters: the starting length of the hypotenuse, the angle alpha and the recursion depth. 
It then calculates the starting points of the squares and uses the drawSquare() function to draw them in SVG format. 
The output is a Pythagoras tree with the given hypotenuse length, angle alpha and recursion depth.
To test the program, you can compile and run it with different values for the input parameters.
*/