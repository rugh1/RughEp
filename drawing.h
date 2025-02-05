#ifndef DRAWING_H
#define DRAWING_H

#include <windows.h>  // For HDC
#include "point.h"    // Assuming Point is defined here
#include "route.h"    // Assuming Route is defined here


void drawPoint(Point point, HDC Hscreen);
void drawLine(Point a, Point b, HDC Hscreen);
void drawRoute(Route route, HDC Hscreen);

#endif // DRAWING_H
