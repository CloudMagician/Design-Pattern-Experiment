#include<iostream>

using namespace std;

class SoupCooker {
public:
    void action() {
        cout << "Soup Done!" << endl;
    }
};

class VegetableCooker {
public:
    void action() {
        cout << "Vegetable Done!" << endl;
    }
};

class MeatCooker {
public:
    void action() {
        cout << "Meat Done!" << endl;
    }
};

class WaiterCommend {
public:
    virtual void execute(){};
};

class SoupCommend: public WaiterCommend {
private:
    SoupCooker* receiver;
    
public:
    SoupCommend() {
        receiver = new SoupCooker();
    }
    void execute() {
        receiver->action();
    }
};

class VegetableCommend: public WaiterCommend {
private:
    VegetableCooker* receiver;
    
public:
    VegetableCommend() {
        receiver = new VegetableCooker();
    }
    void execute() {
        receiver->action();
    }
};

class MeatCommend: public WaiterCommend {
private:
    MeatCooker* receiver;
    
public:
    MeatCommend() {
        receiver = new MeatCooker();
    }
    void execute() {
        receiver->action();
    }
};


class Customer {
private:
    WaiterCommend* commend;
    
public:
    Customer(WaiterCommend* commend) {
        this->commend = commend;
    }
    
    void setCommend(WaiterCommend* commend) {
        this->commend = commend;
    }
    
    void call() {
        commend->execute();
    }
};

int main(int argc, const char * argv[]) {
    Customer* lzx = new Customer(new SoupCommend());
    lzx->call();
    lzx->setCommend(new MeatCommend());
    lzx->call();
    lzx->setCommend(new VegetableCommend());
    lzx->call();
    return 0;
}
