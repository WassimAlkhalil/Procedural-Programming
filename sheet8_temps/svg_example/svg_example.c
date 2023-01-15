#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*
Ziel: eine Datei im SVG-Format erstellen.
*/

int main(void) {
    /*
    Parameter des Rechteckes definieren
    */
    double x = 10.0;
    double y = 20.0;
    double width = 10.0;
    double height = 20.0;
    double rot = 50.0;
    double rx = 0.0;
    double ry = 0.0;
    char color[] = {"red"};

    /*
    Das Programm erstellt automatisch eine SVG-Datei.
    Dazu werden die Funktionen fopen(); fprintf(); fclose() benötigt.
    */
    FILE * fp; //Zeiger vom Typ FILE -> Zur Verarbeitung von Dateien
    /*
    Datei mit dem Namen svg_example.svg öffnen -> fopen()
    w - schreiben
    */
    fp = fopen("svg_example.svg","w");
    /*
    Einzelne Zeilen in die SVG-Datei schreiben
    
    ::Beginn der SVG-Datei::
    -> SVG-Dateien kann so im Webbrowser angezeigt werden    
    transform='scale(1 -1): Spiegeln der Einträge an der X-Achse bzw. y-Achse
    */
    fprintf(fp, "<?xml version='1.0' encoding='UTF-8'?>\n"
    "<svg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' version='1.1' width='100%%' height='100%%' viewBox='-50 -50 100 100' transform='scale(1 -1)'>\n"
    "  <title>Exampel</title>\n");
    //fprintf(fp, "<svg transform='scale(1 -1)'>\n");
    /*
    Zeichnen eines Rechtecks
    -> siehe dazu https://de.wikipedia.org/wiki/Scalable_Vector_Graphics
    */
    fprintf(fp, "<rect x='%f' y='%f' width='%f' height='%f' transform='rotate(%f %f %f)' style='fill:%s; stroke-width:0;' />\n",x, y, width, height, rot, rx, ry, color);
    /*
    ::Ende der SVG-Datei::
    */
    fprintf(fp, "</svg>\n");
    
    /*
    Schließen der Datei svg_example.svg
    */
    fclose(fp);

    return 0;

}
