#ifndef H_ROUTE
#define H_ROUTE 
struct {
	ArrayOfPoint sortedPoints;
	int length;
}typedef Route;

void createRandomInts(int* buffer, int max);
Route createRandomRoute(ArrayOfPoint points);
void printRoute(Route route);
int calculateDistanceForRoute(ArrayOfPoint sortedPoints);
#endif