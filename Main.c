#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include "point.h"
#include "route.h"
#include "generation.h"
#include "drawing.h"

#ifndef UNICODE
#define UNICODE
#endif


#define distance(a, b) (abs(a.x - b.x) << 1) + (abs(a.y - b.y) << 1)


HDC HSCREEN;

//todo:
//add get and sets to everything (should done it at start but still)
//check mutation
//add window to show everything much nicer
//add text
//add cross



int main() {
    srand(time(NULL)); // use current time as seed for random generator
    int NumOfPoints = 7;
    HSCREEN = GetDC(NULL);
    ArrayOfPoint points;
    points.points = (Point*)malloc(NumOfPoints * sizeof(Point));
    points.capacity = NumOfPoints;
    points.length = NumOfPoints * sizeof(Point);
    setPoint(points);
    Generation gen = createNewGeneration(points, 1000);
    for (int i = 0; i < 5040; i++) {
        printRoute(gen.routes[0]);
        drawRoute(gen.routes[0], HSCREEN);
        Generation tmp = createGenerationFromGen(points, 1000, gen, 10);
        freeGenerationNext(gen, 10);
        gen = tmp;
    }
    freeGeneration(gen);
    free(points.points);
    return 0;
}