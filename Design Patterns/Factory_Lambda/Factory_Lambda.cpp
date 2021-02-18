class Product{
public:
    virtual void operation() = 0;
};

class ProductA : public Product{
public:
    void operation() override {
        cout << "Product A created" << endl;
    }
};

class ProductB : public Product{
public:
    void operation() override {
        cout << "Product B created" << endl;
    }
};

class ProductC : public Product{
public:
    void operation() override {
        cout << "Product C created" << endl;
    }
};

class ProductFactory {
private:
    unordered_map<string,std::function<Product*()>> hashMap;
public:
    ProductFactory(){
        hashMap.insert(make_pair("A", [](){return new ProductA();}));
        hashMap.insert(make_pair("B", [](){return new ProductB();}));
        hashMap.insert(make_pair("C", [](){return new ProductC();}));
    }

    Product* createProduct(const string& key) {
        if (hashMap.find(key) == hashMap.end())
            return nullptr;
        return hashMap.at(key)();
    }
};
