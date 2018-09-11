#include <iostream>

using namespace std;

class Role;

//Box
class Box {
public:
    int money;
    Box();
    ~Box();
    Box(int money);
    void showMoney(Role* role);
};

//PoisonBox
class PoisonBox : public Box {
public:
    PoisonBox(int money);
    void showMoney(Role* role);
};

//Role
class Role {
public:
    int blood;
    int money;
    double resistance;  //毒抗性
    double luck;        //幸运值
    
    Role();
    ~Role();
    void openBox(Box* box);
    void moneyChange(int cmoney);
    void bloodChange(int cblood);
};

//Mage
class Mage : public Role {
public:
    Mage();
};

//Solider
class Solider : public Role {
public:
    Solider();
};


Box::Box(){
}

Box::Box(int money):money(money){
}

void Box::showMoney(Role* role){
    role->moneyChange(money);
    money = 0;
    role->bloodChange(0);
}

PoisonBox::PoisonBox(int money):Box(money){
}

void PoisonBox::showMoney(Role* role){
    role->moneyChange(int(money*role->luck));
    money = 0;
    role->bloodChange(int(role->blood*role->resistance)-1);
}

Role::Role():blood(100),money(0),resistance(1),luck(1) {
}

void Role::openBox(Box* box) {
    box->showMoney(this);
}

void Role::moneyChange(int cmoney) {
    money += cmoney;
}

void Role::bloodChange(int cblood) {
    blood += cblood;
}

Mage::Mage() {
    resistance = 0.7;
    luck = 1.4;
}

Solider::Solider() {
    resistance = 0.7;
    luck = 1.4;
}


int main(int argc, const char * argv[]) {
    Box* boxA = new Box(32);
    Box* boxB = new Box(54);
    Box* boxC = new PoisonBox(12);
    Box* boxD = new PoisonBox(15);
    
    Role* Wang = new Solider();
    Role* Lu = new Mage();
    
    cout << Wang->money << "," << Wang->blood << endl;
    cout << Lu->money << "," << Lu->blood << endl;

    Wang->openBox(boxA);
    Wang->openBox(boxC);
    Lu->openBox(boxB);
    Lu->openBox(boxD);
    
    cout << Wang->money << "," << Wang->blood << endl;
    cout << Lu->money << "," << Lu->blood << endl;
    
    return 0;
}
