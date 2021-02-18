#include <iostream>
#include <vector>
using namespace std;

/**
 * Component
 */
class Component {
public:
    virtual void act() = 0;
};

/**
 * Concrete component
 */
class SomeComponent : public Component{
public:
    virtual void act(){ cout<<"Making some Component -->"; }
};

/**
 * Decorator
 */
class Decorator : public Component{
    Component* i;
    static vector<Decorator*> myList;
public:
    Decorator(Component* i)
    {
        this->i = i;
        myList.push_back(this);
    }
    virtual void addedBehavior() = 0;
    virtual int getPriority() = 0;
    void push(Decorator* d) { myList.push_back(d); }

    void sort(vector<Decorator*> &l)
    {
        for(int i = 0; i < l.size(); ++i)
        {
            for(int j = 0; j < l.size() - 1; ++j)
            {
                if(l[j]->getPriority() > l[j+1]->getPriority()) swap(l[j], l[j+1]);
            }
        }
    }

    virtual void act()
    {
        sort(myList);
        if(!myList.empty())
        {
            Decorator* d = myList.back();
            myList.pop_back();
            d->act();
            d->addedBehavior();
        }
        else i->act();
    }
};

/**
 * Concrete Decorator
 */
class A : public Decorator{
public:
    A(Component* i) : Decorator(i){};
    int getPriority() override { return 1; };
    void act() { Decorator::act(); };
    void addedBehavior() override {cout << "A -->";};
};

/**
 * Concrete Decorator
 */
class B : public Decorator{
public:
    B(Component* i) : Decorator(i){};
    int getPriority() override { return 2; };
    void act() { Decorator::act(); };
    void addedBehavior() override {cout << "B -->";};
};

/**
 * Concrete Decorator
 */
class C : public Decorator{
public:
    C(Component* i) : Decorator(i){};
    int getPriority() override { return 3; };
    void act() { Decorator::act(); };
    void addedBehavior() override {cout << "C -->";};
};

vector<Decorator*> Decorator::myList;