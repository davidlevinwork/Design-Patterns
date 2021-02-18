#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
    int ID, age;
    string name;
    Person(string name, int age, int ID) {
        this->name = std::move(name);
        this->age = age;
        this->ID = ID;
    }
};

class Comparator {
public:
    virtual bool compareBetween(Person p1, Person p2) = 0;
};

class IDSorter : public Comparator {
public:
    bool compareBetween(Person p1,Person p2) override {
        return p1.ID < p2.ID;
    }
};

class NameSorter : public Comparator {
public:
    bool compareBetween(Person p1, Person p2) override {
        int size  = min(p1.name.size(), p2.name.size());
        for(int i = 0; i < size; i++) {
            if(p1.name[i] < p2.name[i]) return true;
            if(p2.name[i] < p1.name[i]) return false;
        }
        if(p1.name.size() < p2.name.size()) return true;
        return false;
    }
};

class AgeSorter : public Comparator {
public:
    bool compareBetween(Person p1, Person p2) override {
        return p1.age < p2.age;
    }
};

class Sorter {
    Comparator *compare;
public:
    Sorter(Comparator *compare) {this->compare = compare;}
    void swap(Person &p1, Person &p2) {
        Person temp = p1;
        p1 = p2;
        p2 = temp;
    }
    void sort(vector<Person> &vecPersons) {
        for(int j = 0; j < vecPersons.size(); j++) {
            for (int i = 0; i < vecPersons.size() - 1; i++) {
                if (!compare->compareBetween(vecPersons[i], vecPersons[i + 1]))
                    swap(vecPersons[i], vecPersons[i + 1]);
            }
        }
    }
};