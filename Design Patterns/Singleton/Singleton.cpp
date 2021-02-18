#include <iostream>
using namespace std;

class Singleton
{
    Singleton();     
    static Singleton* instance; 

public:
    static Singleton* getInstance(); 
};

Singleton* Singleton::instance = nullptr; 


Singleton* Singleton::getInstance()
{
    if (instance == nullptr) instance = new Singleton(); 
    return instance; 
}

Singleton::Singleton() {}