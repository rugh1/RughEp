#include "point.h"
#include "route.h"
#include <stdio.h>
#include <windows.h>
#include <math.h>


void createRandomInts(int* buffer, int max) {
	int random = rand() % (max);
	int count = 0;
	int wasAlready = 1;
	for (int i = 0; i < max; i++) {
		while (wasAlready == 1) {
			wasAlready = 0;
			random = rand() % (max);
			for (int j = 0; j < count; j++) {
				if (buffer[j] == random) {
					wasAlready = 1;
				}
			}
		}
		buffer[i] = random;
		count++;
		wasAlready = 1;
	}
	return;
}


Route createRandomRoute(ArrayOfPoint points) {
	Route newRoute;
	int* randomed = (int*)malloc(sizeof(int) * points.capacity);
	createRandomInts(randomed, points.capacity);
	newRoute.sortedPoints.points = (Point*)malloc(points.length);
	newRoute.sortedPoints.length = points.length;
	newRoute.sortedPoints.capacity = points.capacity;
	for (int i = 0; i < points.capacity; i++)
	{
		newRoute.sortedPoints.points[i] = getPoint(points, randomed[i]);
	}
	free(randomed);
	newRoute.length = calculateDistanceForRoute(newRoute.sortedPoints);
	return newRoute;
}


Route mutateRoute(Route route) { // still needs testing
	Route newRoute;
	newRoute.length = route.length;
	newRoute.sortedPoints.points = (Point*)malloc(route.sortedPoints.length);
	newRoute.sortedPoints.length = route.sortedPoints.length;
	newRoute.sortedPoints.capacity = route.sortedPoints.capacity;
	for (int i = 0; i < route.length; i++)
	{
		newRoute.sortedPoints.points[i] = getPoint(route.sortedPoints, i);
	}
	int a = rand() % (route.length);
	int b = rand() % (route.length);
	Point tmp = getPoint(newRoute.sortedPoints, a);
	

	return newRoute;
}

void printRoute(Route route) {
	for (int i = 0; i < route.sortedPoints.capacity; i++) {
		printf("(%i,%i) ", getPoint(route.sortedPoints, i).x, getPoint(route.sortedPoints, i).y);
	}
	printf("\n");
}

int calculateDistanceForRoute(ArrayOfPoint sortedPoints) { //squared
	int sum = 0;
	for (int i = 0; i < sortedPoints.capacity - 1; i++) {
		sum += calculateDistanceSquared(getPoint(sortedPoints, i), getPoint(sortedPoints, i + 1));
	}
	return sum;
}