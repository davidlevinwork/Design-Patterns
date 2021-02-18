#include <iostream>
#include <unordered_map>
using namespace std;

class Product{
public:
    virtual ~Product(){};
    virtual void operation() = 0;
};

class ProductA : public Product{
public:
    ProductA(){};
    virtual void operation(){
        cout << "Product A ";
    }
};

class ProductB : public Product{
public:

    ProductB(){};
    virtual void operation(){
        cout << "Product B ";
    }
};

class Creator{
public:
    ~Creator(){};
    virtual Product* create() = 0;
};

class productACreator : public Creator{
public:
    virtual Product* create(){
        return new ProductA();
    }
};

class productBCreator : public Creator{
public:
    virtual Product* create(){
        return new ProductB();
    }
};

class ProductFactory{
private:
    unordered_map<string, Creator*> map;
public:
    /** here we are paying O(n) time and space - for the initalization of the Hash-Map */
    ProductFactory()
    {
        map.insert(make_pair("A", new productACreator()));
        map.insert(make_pair("B", new productBCreator()));
    }

    /** We can reach the item in O(1) */
    Product* createProduct(string type)
    {
        Creator* c = map.at(type);
        if(c != nullptr) return c->create();
        return nullptr;
    }
};