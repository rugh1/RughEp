#include "drawing.h"
#include "point.h"
#include "route.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define DRAWING_RADIUS 10
#define corners(point) point.x - DRAWING_RADIUS, point.y + DRAWING_RADIUS, point.x + DRAWING_RADIUS, point.y - DRAWING_RADIUS

void drawPoint(Point point, HDC Hscreen) {
    Ellipse(Hscreen, corners(point));
    return;
}


void drawLine(Point a, Point b, HDC Hscreen) {
    int success = MoveToEx(Hscreen, a.x, a.y, NULL);
    if (success == 0) {
        return;
    }
    success = LineTo(Hscreen, b.x, b.y);
    return;
}

void drawRoute(Route route, HDC Hscreen) {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < route.sortedPoints.capacity; i++) {
            drawPoint(getPoint(route.sortedPoints, i), Hscreen);  // needs to be error hand
        }
        for (int i = 0; i < route.sortedPoints.capacity - 1; i++) {
            drawLine(getPoint(route.sortedPoints, i), getPoint(route.sortedPoints, i + 1), Hscreen); // needs to be error hand
        }
        Sleep(100);
    }
}