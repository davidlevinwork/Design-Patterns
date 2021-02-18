#include <iostream>
using namespace std;

/**
 * Abstract Product A (A = sword)
 */
class Sword {
public:
    virtual ~Sword() {};
    virtual string dataSword() const = 0;
};

/**
 * Product A1
 */
class plainSword : public Sword {
public:
    string dataSword() const override { return "Plain sword\n"; };
};

/**
 * Product A2
 */
class LightSword : public Sword {
    string dataSword() const override { return "Light sword\n"; };
};

/**
 * Abstract Product B (B = shield)
 */
class Shield {
public:
    virtual ~Shield() {};
    virtual string dataShield() const = 0;
};

/**
 * Product B1
 */
class plainShield : public Shield {
public:
    string dataShield() const override { return "Plain shield\n"; };
};

/**
 * Product B2
 */
class LightShield : public Shield {
    string dataShield() const override { return "Light shield\n"; };
};

/**
 * Abstract factory
 */
class Armory {
public:
    virtual Sword *createSword() const = 0;
    virtual Shield *createShield() const = 0;
};

/**
 * Concrete Factory 1
 */
class StarWarsArmory : public Armory {
public:
    Sword *createSword() const override { return new LightSword(); }
    Shield *createShield() const override { return new LightShield(); }
};

/**
 * Concrete Factory 2
 */
class PlainArmory : public Armory {
public:
    Sword *createSword() const override { return new plainSword(); }
    Shield *createShield() const override { return new plainShield(); }
};

void Client(Armory &weapon)
{
    Sword *sword = weapon.createSword();
    std::cout << sword->dataSword();
    Shield *shield = weapon.createShield();
    std::cout << shield->dataShield() <<endl;
}