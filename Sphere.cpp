#include "Sphere.h"

Sphere::Sphere() {};
Sphere::Sphere(float radius, Point center, Material mat)
{
    this->radius = radius;
    this->center = center;
    this->mat = mat;
};

//Utilizar Vertex
void Sphere::applyTransform(Matriz transform)
{
    Vertex c = Vertex(this->center[0], this->center[1], this->center[2], 1);
    c = transform * c;
    this->center = Point(c[0], c[1], c[2]);
}
//Utilizar Vertex
void Sphere::setCameraCoordinates(Matriz worldToCamera)
{
    Vertex c = Vertex(this->center[0], this->center[1], this->center[2], 1);
    c = worldToCamera * c;
    this->center = Point(c[0], c[1], c[2]);
}
//Utilizar Vertex
void Sphere::setWorldCoordinates(Matriz cameraToWorld)
{
    Vertex c = Vertex(this->center[0], this->center[1], this->center[2], 1);
    c = cameraToWorld * c;
    this->center = Point(c[0], c[1], c[2]);
}

Point Sphere::rayIntersect(Point rayOrigin, Point rayDirection)
{
    Point pV0N = rayDirection.normalized();
    Point C0P0 = rayOrigin - center;
    double a = pV0N.dot(pV0N);
    double b = pV0N.dot(C0P0);
    double c = C0P0.dot(C0P0) - this->radius * this->radius;
    double delta = b * b - a * c;

    if (delta > 0) {
        double t1 = (-b + sqrt(delta)) / a;
        double t2 = (-b - sqrt(delta)) / a;
        Point intersection1 = (rayOrigin + pV0N * t1);
        Point intersection2 = (rayOrigin + pV0N * t2);
        double distance1 = sqrt(pow(intersection1[0] - rayOrigin[0], 2) + pow(intersection1[1] - rayOrigin[1], 2) + pow(intersection1[2] - rayOrigin[2], 2));
        double distance2 = sqrt(pow(intersection2[0] - rayOrigin[0], 2) + pow(intersection2[1] - rayOrigin[1], 2) + pow(intersection2[2] - rayOrigin[2], 2));
        Point intersection = (distance1 < distance2) ? intersection1 : intersection2;
        return intersection;
    }
    else if (delta == 0) {
        double t1 = (-b + sqrt(delta)) / a;
        Point intersection = (rayOrigin + pV0N * t1);
        return intersection;
    }
    else {
        return Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);
    }
};

Point Sphere::normal(Point point)
{
    Point normal = (point - this->center).normalized();
    return normal;
}

void Sphere::scaling(Point scale) // 0, 1, 1
{
    this->radius *= scale[0];
};

void Sphere::rotate(Matriz rotate)
{
    this->center = VertexToPoint(rotate * PointToVertex(this->center));
};

void Sphere::translating(Point translate) {
    this->center += translate;
}

//Point* Sphere::Bounds() {
//    Point max_bounds = Point(this->center[0] + this->radius, this->center[1] + this->radius, this->center[2] + this->radius);
//   Point min_bounds = Point(this->center[0] - this->radius, this->center[1] - this->radius, this->center[2] - this->radius);
//
//    return new Point(min_bounds, max_bounds);
//};