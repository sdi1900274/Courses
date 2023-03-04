#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

typedef struct triangle_static {
    Point points[3];
} Triangle;

void point_print(Point p) 
{
    printf("(%d, %d)", p.x, p.y);
}

void point_move_horizontally(Point* p, int units) 
{
    p->x += units;
}

void triangle_print(Triangle* t) 
{
    for (int i = 0; i < 3; i++) {
        point_print(t->points[i]);
    }
}

void triangle_move_horizontally(Triangle* t, int units) 
{
    for (int i = 0; i < 3; i++) {
        point_move_horizontally(&t->points[i], units);
    }
}

int main(void)
{
    Point* a = malloc(sizeof(Point));
    a->x = 0;
    a->y = 0;

    point_print(*a);
    printf("\n");

    point_move_horizontally(a, 5);

    point_print(*a);
    printf("\n");

    free(a);

    Triangle* t = malloc(sizeof(Triangle));
    t->points[0].x = 0;
    t->points[0].y = 0;
    t->points[1].x = 1;
    t->points[1].y = 0;
    t->points[2].x = 0;
    t->points[2].y = 1;

    triangle_print(t);
    printf("\n");

    triangle_move_horizontally(t, 5);

    triangle_print(t);
    printf("\n");

    free(t);

    return 0;
}