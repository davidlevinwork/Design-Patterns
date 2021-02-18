#include <list>
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

class Employee {
protected:
    string _name;
public:
    void work() { cout << _name << ":work" << endl; };
    virtual Employee* cloneMe() = 0;
};

class TA : public Employee{
public:
    TA() { _name = "TA"; }
    Employee* cloneMe() { return new TA(); }
};

class Developer : public Employee{
public:
    Developer() { _name = "Developer"; }
    Employee* cloneMe() { return new Developer(); }
};

class Manager : public Employee{
public:
    Manager() { _name = "Manager"; }
    Employee* cloneMe() { return new Manager(); }
};

class EmployeeFactory {
    map<string, Employee*> _map;
public:
    EmployeeFactory()
    {
        _map.insert({"ta", new TA});
        _map.insert({"manager", new Manager});
        _map.insert({"developer", new Developer});
    }

    Employee *create(const string& key)
    {
        if (_map.find(key) != _map.end())
            return _map.at(key)->cloneMe();
        return nullptr;
    }
};