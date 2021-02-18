#include <iostream>
using namespace std;

/**
 * Abstraction class - an abstract class
 */
class Color {
public:
    virtual string myColor() = 0;
};

class RedColor : public Color{
public:
    string myColor() override { return "red color "; }
};

class BlueColor : public Color {
public:
    string myColor() override { return "blue color "; }
};

/**
 * Implementor class - an abstract class
 */
class Shape {
protected:
    Color* color;
public:
    Shape(Color* color) { this->color = color; }
    virtual float getArea() = 0;
    virtual void printDetails() = 0;
};


class Rectangle : public Shape {
    float height, width;
public:
    Rectangle(float height, float width, Color* color) : Shape(color){
        this->height = height;
        this->width = width;
    }
    float getArea() override { return width * height; }
    void printDetails() override { cout << color->myColor() + "rectangle" << endl; }
};

class Triangle : public Shape {
    float height, length;
public:
    Triangle(float height, float length, Color* color) : Shape(color) {
        this->height = height;
        this->length = length;
    }
    float getArea() override { return (length * height) / 2.0f; }
    void printDetails() override {cout << color->myColor() + "Triangle" << endl;}
};