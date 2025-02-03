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
	ArrayOfPoint sortedPoints;
	int length;
}typedef Route;


struct {
	Route* items;
	int size;
}typedef Generation;


Route createRandomRoute(ArrayOfPoint points) {
	Route newRoute; 
	int* randomed = createRandomInts(points.capacity);
	newRoute.sortedPoints.points = malloc(points.length);
	newRoute.sortedPoints.length = points.length;
	newRoute.sortedPoints.capacity = points.capacity;
	for (int i = 0; i < points.capacity; i++)
	{
		newRoute.sortedPoints.points[i] = getPoint(points, randomed[i]);
	}
	free(randomed);
	newRoute.length = calculateDistanceForRoute(newRoute(newRoute.sortedPoints));
	return newRoute;
}





int* createRandomInts(int max) {
	int* arr = malloc(sizeof(int) * (max));
	int random = rand() % (max);
	int count = 0;
	int wasAlready = 1;
	for (int i = 0; i < max; i++) {
		while (wasAlready == 1) {
			wasAlready = 0;
			random = rand() % (max);
			for (int j = 0; j < count; j++) {
				if (arr[j] == random) {
					wasAlready = 1;
				}
			}
		}
		arr[i] = random;
		count++;
		wasAlready = 1;
	}
	return arr;

}




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


int calculateDistanceForRoute(ArrayOfPoint sortedPoints) { //squared
	int sum = 0;
	for (int i = 0; i < sortedPoints.capacity - 1; i++) {
		sum += calculateDistanceSquared(getPoint(sortedPoints, i), getPoint(sortedPoints, i + 1));
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
	setPoints(Points);

	for (;;) {
		for (int i = 0; i < Points.capacity; i++) {
			BOOL success = drawPoint(getPoint(Points, i));  // needs to be error hand

		}
		for (int i = 0; i < Points.capacity - 1; i++) {
			BOOL success = drawLine(getPoint(Points, i), getPoint(Points, i + 1)); // needs to be error hand
		}
		//Sleep(1);
	}
	free(Points.points);
}
