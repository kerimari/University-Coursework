#include <stdio.h>
#include <math.h> // Required for sqrt() and pow()

/**
 * Define a structure to represent a point in 2D Cartesian plane.
 */
typedef struct {
    float x;
    float y;
} Point;

/**
 * Calculates the Euclidean distance from the origin (0,0).
 * Formula: distance = sqrt(x^2 + y^2)
 */
float calculate_distance(Point p) {
    return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

/**
 * Determines which quadrant the point lies in.
 */
void print_quadrant(Point p) {
    if (p.x > 0 && p.y > 0) printf("Plane: Quadrant I (QI)\n");
    else if (p.x < 0 && p.y > 0) printf("Plane: Quadrant II (QII)\n");
    else if (p.x < 0 && p.y < 0) printf("Plane: Quadrant III (QIII)\n");
    else if (p.x > 0 && p.y < 0) printf("Plane: Quadrant IV (QIV)\n");
    else printf("Plane: Point is on an axis or origin.\n");
}

int main() {
    Point myPoint;

    printf("Enter x and y coordinates: ");
    scanf("%f %f", &myPoint.x, &myPoint.y);

    printf("\n--- Analysis ---\n");
    printf("Point: (%.2f, %.2f)\n", myPoint.x, myPoint.y);
    printf("Distance from Origin: %.2f units\n", calculate_distance(myPoint));
    print_quadrant(myPoint);

    return 0;
}
