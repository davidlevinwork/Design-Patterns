#include <iostream>
using namespace std;

/**
 * Component
 */
class Pizza {
public:
    virtual void make() = 0;
};

/**
 * Concrete component
 */
class SimplePizza : public Pizza {
public:
    void make() override { cout << "Making simple pizza"; }
};

/**
 * Decorator
 */
class PizzaDecorator : public Pizza {
    Pizza* pizza;
public:
    PizzaDecorator(Pizza* newPizza) { pizza = newPizza; }
    void make() override
    {
        pizza->make();
    }
};

/**
 * Concrete Decorator A
 */
class withA : public PizzaDecorator {
public:
    withA(Pizza* newPizza) : PizzaDecorator(newPizza){}
    void make() override
    {
        PizzaDecorator::make();
        cout << " + A"; 
    }
};

/**
 * Concrete Decorator B
 */
class withB : public PizzaDecorator {
public:
    withB(Pizza* newPizza) : PizzaDecorator(newPizza){}
    void make() override
    {
        PizzaDecorator::make(); 
        cout << " + B"; 
    }
};

/**
 * Concrete Decorator C
 */
class withC : public PizzaDecorator {
public:
    withC(Pizza* newPizza) : PizzaDecorator(newPizza){}
    void make() override
    {
        PizzaDecorator::make(); 
        cout << " + C"; 
    }
};