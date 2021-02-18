#include <iostream>
#include <vector>
using namespace std;

class SorterClass {
public:
    virtual void sort(vector<int> &vec) = 0;
    virtual void printSorterName() = 0;
};


class BubbleSort : public SorterClass {
    virtual void swap(int &num1, int &num2) {int temp = num1; num1 = num2; num2 = temp;}
public:
    void sort(vector<int> &vec) override {
        for(int j = 0; j < vec.size(); j++) {
            for (int i = 0; i < vec.size() - 1; i++) {
                if(vec[i] > vec[i + 1])
                    swap(vec[i], vec[i + 1]);
            }
        }
    }
    void printSorterName() override {cout << "Bubble-sort" << endl;};
};


class Task {
public:
    virtual void sortAndIncrease(vector<int> &vec) = 0;
};

class BubbleSortTask : public BubbleSort, public Task {
public:
    void sortAndIncrease(vector<int> &vec) override {
        sort(vec);
        printSorterName();
        for(int & value : vec)
            value++;
    }
};