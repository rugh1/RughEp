#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include "point.h"
#include "route.h"

#define corners(point) point.x - DRAWING_RADIUS, point.y + DRAWING_RADIUS, point.x + DRAWING_RADIUS, point.y - DRAWING_RADIUS
#define distance(a, b) (abs(a.x - b.x) << 1) + (abs(a.y - b.y) << 1)

#include "route.c"
#include "point.c"

/*
struct {
	ArrayOfPoint sortedPoints;
	int length;
}typedef Route;
*/

struct {
	Route* items;
	int size;
}typedef Generation;





HDC HSCREEN;


BOOL drawPoint(Point point) {
	return Ellipse(HSCREEN, corners(point));
}


BOOL drawLine(Point a, Point b) {
	int success = MoveToEx(HSCREEN, a.x, a.y, NULL);
	if (success == 0) {
		return 0;
	}
	success = LineTo(HSCREEN, b.x, b.y);
	return success;
}






int main() {
	srand(time(NULL)); // use current time as seed for random generator
	int NumOfPoints = 10;
	HSCREEN = GetDC(NULL);
	ArrayOfPoint Points;
	Points.points = malloc(NumOfPoints * sizeof(Point));
	Points.capacity = NumOfPoints;
	Points.length = NumOfPoints * sizeof(Point);
	setPoints(Points);
	for (;;) {
		Route route = createRandomRoute(Points);
		printRoute(route);
		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < Points.capacity; i++) {
				BOOL success = drawPoint(getPoint(Points, i));  // needs to be error hand
			}
			for (int i = 0; i < route.sortedPoints.capacity - 1; i++) {
				BOOL success = drawLine(getPoint(route.sortedPoints, i), getPoint(route.sortedPoints, i + 1)); // needs to be error hand
			}
			Sleep(100);
		}
		Sleep(1000);
		free(route.sortedPoints.points);
	}
	free(Points.points);
}
