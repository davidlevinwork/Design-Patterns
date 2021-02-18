#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Point {
    int x, y;
public:
    Point() {this->x = 0; this->y = 0;};
    Point(int x, int y) { this->x = x;  this->y = y;}
    int getX() {return x;};
    int getY() {return y;};
};


class Shape {
public:
    virtual void PrintShapeName() = 0;
    virtual Shape* clone() = 0;
};

class Triangle : public Shape {
    Point p1, p2, p3;
public:
    Triangle(Point p1, Point p2, Point p3) {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
    }
    void PrintShapeName() override {cout << "Triangle" << endl;}
    Shape* clone() override {return new Triangle(p1, p2, p3);};
};

class Rectangle : public Shape {
    Point p;
    float height, width;
public:
    Rectangle(Point p, float height, float width) {
        this->p = p;
        this->height = height;
        this->width = width;
    }
    void PrintShapeName() override {cout << "Rectangle" << endl;}
    Shape* clone() override {return new Rectangle(p, height, width);};
};


class ShapesHolder {
    vector<Shape*> vec;
public:
    void addShapeCopy(Shape* s) {vec.push_back(s->clone());};
};