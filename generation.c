#include "point.h"
#include "route.h"
#include <stdio.h>
#include <stdlib.h>
#include "generation.h"

Generation createNewGeneration(ArrayOfPoint points, int size) { // posiible should just call an array of routes a generation
	Generation newGeneration;
	newGeneration.routes = (Route*)malloc(sizeof(Route) * size);
	newGeneration.count = 0;
	newGeneration.size = size;
	for (int i = 0; i < size; i++) {
		insertRoute(newGeneration, createRandomRoute(points));
	}
	return newGeneration;
}

Generation createGenerationFromGen(ArrayOfPoint points, int size, Generation gen) { // posiible should just call an array of routes a generation
	Generation newGeneration;

	newGeneration.routes = (Route*)malloc(sizeof(Route) * size);
	newGeneration.count = 0;
	newGeneration.size = size;
	for (int i = 0; i < gen.count; i++)
	{
		insertRoute(newGeneration, gen.routes[i]);
	}
	for (int i = newGeneration.count; i < size; i++) {
		insertRoute(newGeneration, createRandomRoute(points));
	}
	return newGeneration;
}


void insertRoute(Generation arr, Route route) {
	if (arr.count == arr.size) {
		return;
	}
	Route tmp;
	int i = arr.count - 1;
	arr.routes[arr.count] = route;
	
	while (i > 0 && arr.routes[i].length > route.length) {
		arr.routes[i + 1] = arr.routes[i];
		arr.routes[i] = route;
		i--;
	}
	arr.count++;
	return;
}

void freeGeneration(Generation gen) {
	for (int i = 0; i < gen.count; i++) {
		free(gen.routes[i].sortedPoints.points);
	}
	free(gen.routes);
	return;
}