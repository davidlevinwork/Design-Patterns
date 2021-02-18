#include <iostream>
#include <vector>
using namespace std;

class Level {
public:
    virtual void printGame() = 0;
};

class MarioLevel : public Level {
public:
    void printGame() {cout << "mario level game" << endl;}
};

class AladdinLevel : public Level {
public:
    void printGame() {cout << "aladdin level game" << endl;}
};

/** Director */
class LevelBuilder {
public:
    virtual void createEnemy() = 0;
    virtual void createCharacter() = 0;
    virtual Level* getLevel() = 0;

};

class MarioLevelBuilder : public LevelBuilder {
    int numberOfEnemy = 1;
public:
    void createEnemy() override {cout << "creating enemy number " << numberOfEnemy++ << " for Mario level" << endl;};
    void createCharacter() override {cout << "creating mario character for Mario level" << endl;};
    Level* getLevel() {return new MarioLevel();};
};

class AladdinLevelBuilder : public LevelBuilder {
    int numberOfEnemy = 1;
public:
    void createEnemy() override {cout << "creating enemy number " << numberOfEnemy++ << " for Aladdin level" << endl;};
    void createCharacter() override {cout << "creating aladdin character for Aladdin level" << endl;};
    Level* getLevel() {return new AladdinLevel();};
};

/** Builder */
class LevelDirector {
    LevelBuilder* builder;
public:
    LevelDirector(LevelBuilder* builder) {this->builder = builder;};
};

/** Concrete builder */
class easyLevel : public LevelDirector {
    LevelBuilder* builder;
public:
    easyLevel(LevelBuilder* builder) : LevelDirector(builder) {
        builder->getLevel()->printGame();
        builder->createCharacter();
        builder->createEnemy();
    };
};

/** Concrete builder */
class mediumLevel : public LevelDirector {
    LevelBuilder* builder;
public:
    mediumLevel(LevelBuilder* builder) : LevelDirector(builder) {
        builder->getLevel()->printGame();
        builder->createCharacter();
        for(int i = 0; i < 3; i++)
            builder->createEnemy();
    };
};

/** Concrete builder */
class hardLevel : public LevelDirector {
    LevelBuilder* builder;
public:
    hardLevel(LevelBuilder* builder) : LevelDirector(builder) {
        builder->getLevel()->printGame();
        builder->createCharacter();
        for(int i = 0; i < 10; i++)
            builder->createEnemy();
    };
};