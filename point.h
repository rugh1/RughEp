#ifndef POINT_H
#define POINT_H


typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* points;
    int capacity;
    int length;
} ArrayOfPoint;


Point GetPoint(ArrayOfPoint array, int index);
BOOL SetPoints(ArrayOfPoint array);
int CalculateDistanceSquared(Point a, Point b);
int CalculateDistanceForRoute(ArrayOfPoint sorted_points);

#endif // POINT_H
