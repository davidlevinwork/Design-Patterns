#include <iostream>
#include <vector>
using namespace std;

class SorterClass {
public:
    virtual void sort(vector<int> &vec) = 0;
    virtual void printSorterName() = 0;
};

class abstractSorter : public SorterClass {
public:
    virtual void swap(int &num1, int &num2) {int temp = num1; num1 = num2; num2 = temp;}
};

class BubbleSort : public abstractSorter {
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

class InsertionSort : public abstractSorter {
public:
    void sort(vector<int> &vec) override {
        int key, j;
        for (int i = 1; i < vec.size(); i++) {
            key = vec[i];
            j = i - 1;
            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j--;
            }
            vec[j + 1] = key;
        }
    }
    void printSorterName() {cout << "Insertion-sort" << endl;};

};

class Task {
public:
    virtual void sortAndIncrease(vector<int> &vec) = 0;
};

class SorterTask : public Task {
    SorterClass* sorter;
public:
    SorterTask(SorterClass* sorter) {this->sorter = sorter;};
    void sortAndIncrease(vector<int> &vec) override {
        sorter->sort(vec);
        sorter->printSorterName();
        for(int & value : vec)
            value++;
    }
};