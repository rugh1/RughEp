#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>

#define corners(point) point.x - DRAWING_RADIUS, point.y + DRAWING_RADIUS, point.x + DRAWING_RADIUS, point.y - DRAWING_RADIUS
#define distance(a, b) (abs(a.x - b.x) << 1) + (abs(a.y - b.y) << 1)


struct {
	int x;
	int y; 
}typedef Point;

struct {
	Point* points;
	int capacity;
	int length;
}typedef ArrayOfPoint;


struct {
	ArrayOfPoint sorted_points;
	int length;
}typedef Route;


HDC HSCREEN;
const int X_SCREEN_LIMIT = 1920 - 200; //needs to change to depend on the window size
const int y_SCREEN_LIMIT = 1080 - 200; //needs to change to depend on the window size
const int DRAWING_RADIUS = 10;


Point GetPoint(ArrayOfPoint array, int index) {
	if (index < array.capacity && index >= 0) {
		return array.points[index];
	}
	Point default_point = { 0, 0 };
	return default_point;
}

BOOL SetPoints(ArrayOfPoint array) {
	int x;
	int y;
	for (int i = 0; i < array.capacity; i++) {
		x = DRAWING_RADIUS * 3 + rand() % X_SCREEN_LIMIT;
		y = DRAWING_RADIUS * 3 + rand() % y_SCREEN_LIMIT;
		Point point = { x, y };
		array.points[i] = point;
	}
	return 0;
}


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


int CalculateDistanceSquared(Point a, Point b) { // maybe better for performance 
	return (abs(a.x - b.x) << 1) + (abs(a.y - b.y) << 1);
}




int CalculateDistanceForRoute(ArrayOfPoint sorted_points) {
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
}

