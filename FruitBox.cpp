#include <iostream>

using namespace std;

//Fruit
class Fruit {
public:
    int weight;
    int lose;
    
    Fruit();
    ~Fruit();
    virtual void loseWeight();
    virtual Fruit* GetClassType(void);
};

//Apple
class Apple : public Fruit {
public:
    Apple();
    void loseWeight();
    Apple* GetClassType(void);
};

//Orange
class Orange : public Fruit {
public:
    Orange();
    void loseWeight();
    Orange* GetClassType(void);
};

//Box
class Box {
private:
    Fruit* box[8];
    int order;
public:
    Box();
    ~Box();
    void passOneDay();
    bool putFruit(Fruit* fruit);
    int showApple();
    int showOrange();
    int showReducing();
    int showSum();
};

Fruit::Fruit():weight(0),lose(0) {
}

void Fruit::loseWeight() {
}

Fruit* Fruit::GetClassType(void) {
    return this;
}

Apple::Apple() {
    weight = 50;
}

void Apple::loseWeight() {
    if (weight > 30) {
        weight -= 4;
        lose = 4;
    } else {
        lose = 0;
    }
}

Apple* Apple::GetClassType(void) {
    return this;
}

Orange::Orange() {
    weight = 30;
}

void Orange::loseWeight() {
    if (weight > 18) {
        weight -= 3;
        lose = 3;
    } else {
        lose = 0;
    }
}

Orange* Orange::GetClassType(void) {
    return this;
}

Box::Box():order(0){
    for (int i = 0; i < 8; i++) {
        box[i] = NULL;
    }
}

void Box::passOneDay(){
    int i = 0;
    while (box[i] != NULL && i < 8) {
        box[i]->loseWeight();
        i++;
    }
}

bool Box::putFruit(Fruit* fruit){
    if (order < 8) {
        box[order] = fruit;
        order++;
        return true;
    } else {
        return false;
    }
}

int Box::showApple(){
    int i = 0;
    int count = 0;
    while (box[i] != NULL && i < 8) {
        if (typeid(*(box[i]->GetClassType()))== typeid(Apple)) {
            count++;
        }
        i++;
    }
    return count;
}

int Box::showOrange(){
    int i = 0;
    int count = 0;
    while (box[i] != NULL && i < 8) {
        if (typeid(*(box[i]->GetClassType()))== typeid(Orange)) {
            count++;
        }
        i++;
    }
    return count;
}

int Box::showReducing(){
    int i = 0;
    int count = 0;
    while (box[i] != NULL && i < 8) {
        count += box[i]->lose;
        i++;
    }
    return count;
}

int Box::showSum(){
    int i = 0;
    int count = 0;
    while (box[i] != NULL && i < 8) {
        count += box[i]->weight;
        i++;
    }
    return count;
}


int main(int argc, const char * argv[]) {
    Box* testbox = new Box();
    for (int i = 0; i < 4; i++) {
        testbox->putFruit(new Apple());
        testbox->putFruit(new Orange());
        testbox->passOneDay();
        cout << "Apple:" << testbox->showApple() << endl;
        cout << "Orange:" << testbox->showOrange() << endl;
        cout << "Reducing:" << testbox->showReducing() << endl;
        cout << "Sum:" << testbox->showSum() << endl;
    }
    return 0;
}

