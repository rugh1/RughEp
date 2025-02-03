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


Point getPoint(ArrayOfPoint array, int index);
BOOL setPoints(ArrayOfPoint array);
int calculateDistanceSquared(Point a, Point b);
int calculateDistanceForRoute(ArrayOfPoint sorted_points);

#endif // POINT_H
