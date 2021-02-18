#include <iostream>
#include <vector>
using namespace std;

class CycleException{ };
class Employee {
public:
    virtual void print() { cout << "Employee" << endl; }
    virtual ~Employee() {}
};

class Engineer : public Employee {
public:
    virtual void print() { cout << "Engineer" << endl; }
};


class Manager : public Employee {
public:
    static vector<Employee*> hasManager;
    static vector<Employee*> vecManager;
    vector <Employee*> workers;
    virtual void print() { cout << "Manager" << endl; }

    void addEmployee(Employee* e)
    {
        for(int i = 0; i < hasManager.size(); ++i)
        {
            if(hasManager[i] == e) throw CycleException();
        }
        for(int i = 0; i < vecManager.size(); ++i)
        {
            if(vecManager[i] == e) throw CycleException();
        }
        if(this == e) throw CycleException();
        workers.push_back(e);
        vecManager.push_back(this);
        hasManager.push_back(e);

    }
    virtual ~Manager()
    {
        for(int i = 0; i < workers.size(); ++i) { delete(workers[i]); }
    }
};

vector<Employee*> Manager::hasManager;
vector<Employee*> Manager::vecManager;