#ifndef H_generation
#define H_generation

struct {
	Route* routes;
	int size;
	int count;
}typedef Generation;

Generation createNewGeneration(ArrayOfPoint points, int size);
void insertRoute(Generation arr, Route route);
void freeGeneration(Generation gen);
#endif // !H_generation

