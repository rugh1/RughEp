#include "point.h"
#include <windows.h>

#define X_SCREEN_LIMIT (1920 - 200) // Adjust for dynamic screen size if needed
#define Y_SCREEN_LIMIT (1080 - 200)
#ifndef DRAWING_RADIUS 
#define DRAWING_RADIUS 10
#endif // DRAWIN_RADUIS 

Point getPoint(ArrayOfPoint array, int index) {
    if (index < array.capacity && index >= 0) {
        return array.points[index];
    }
    Point default_point = { 0, 0 };
    return default_point;
}

void setPoint(ArrayOfPoint array) {
    int x, y;
    for (int i = 0; i < array.capacity; i++) {
        x = DRAWING_RADIUS * 3 + rand() % X_SCREEN_LIMIT;
        y = DRAWING_RADIUS * 3 + rand() % Y_SCREEN_LIMIT;
        Point point = { x, y };
        array.points[i] = point;
    }
    return;
}

int calculateDistanceSquared(Point a, Point b) {
    return (abs(a.x - b.x) << 1) + (abs(a.y - b.y) << 1);
}

