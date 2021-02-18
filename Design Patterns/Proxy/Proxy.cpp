#include <stdio.h>
#include <math.h>
#include <map>
#include <iostream>

using namespace std;

/** Subject */
class MathCalculator {
public:
    virtual double getTotalPow(int x, int y) = 0;
};

/** Real subject */
class PowCalculator : public MathCalculator{
public:
    double getTotalPow(int x, int y)
    {
        return (x*x + y*y);
    }
};

/** Proxy */
class DistanceCache : public MathCalculator {
private:
    map<string, double> myMap;
    MathCalculator* calc;
public:
    DistanceCache(MathCalculator* d) { this->calc = d; }

    double getTotalPow(int x, int y)
    {
        map<string, double> :: iterator itr;

        auto k1 = to_string(x) + to_string(y);
        for(auto itr = myMap.find(k1); itr != myMap.end(); itr++)
        {
            return itr->second;
        }

        auto k2 = to_string(y) + to_string(x);
        for(auto itr = myMap.find(k2); itr != myMap.end(); itr++)
        {
            return itr->second;
        }

        double distance = calc->getTotalPow(x,y);
        myMap.insert({k1, distance});
        myMap.insert({k2, distance});
    }
};