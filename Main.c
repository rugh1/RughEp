#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include "point.h"
#define corners(point) point.x - DRAWING_RADIUS, point.y + DRAWING_RADIUS, point.x + DRAWING_RADIUS, point.y - DRAWING_RADIUS
#define distance(a, b) (abs(a.x - b.x) << 1) + (abs(a.y - b.y) << 1)

#include "point.c"


struct {
	ArrayOfPoint sorted_points;
	int length;
}typedef Route;


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


int CalculateDistanceForRoute(ArrayOfPoint sorted_points) { //squared
	int sum = 0;
	for (int i = 0; i < sorted_points.capacity - 1; i++) {
		sum += CalculateDistanceSquared(GetPoint(sorted_points, i), GetPoint(sorted_points, i + 1));
	}
	return sum;
}



int main() {
	srand(time(NULL)); // use current time as seed for random generator
	int NumOfPoints = 10;
	HSCREEN = GetDC(NULL);
	ArrayOfPoint Points;
	Points.points = malloc(NumOfPoints * sizeof(Point));
	Points.capacity = NumOfPoints;
	Points.length = NumOfPoints * sizeof(Point);
	SetPoints(Points);

	for (;;) {
		for (int i = 0; i < Points.capacity; i++) {
			BOOL success = drawPoint(GetPoint(Points, i));  // needs to be error hand

		}
		for (int i = 0; i < Points.capacity - 1; i++) {
			BOOL success = drawLine(GetPoint(Points, i), GetPoint(Points, i + 1)); // needs to be error hand
		}
		//Sleep(1);
	}
	free(Points.points);
}
