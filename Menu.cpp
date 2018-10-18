#include<iostream>
#include<list>
#include<string>

using namespace std;

class MenuComponent {
protected:
    string name;
public:
    MenuComponent(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    virtual void add(MenuComponent* menuComponent) = 0;
    virtual void print() = 0;
};

class MenuItem: public MenuComponent {
private:
    double price;
public:
    MenuItem(string name, double price):MenuComponent(name) {
        this->price = price;
    }
    double getPrice() {
        return price;
    }
    void add(MenuComponent* menuComponent) {}
    void print() {
        cout << getName() << ":" << getPrice() << endl;
    }
};

class Menu: public MenuComponent {
private:
    list<MenuComponent*> menuComponents;
public:
    Menu(string name): MenuComponent(name){}
    void add(MenuComponent* menuComponent) {
        menuComponents.push_back(menuComponent);
    }
    void print() {
        cout << endl << getName() << endl;
        for(list<MenuComponent*>::iterator iter = menuComponents.begin(); iter!=menuComponents.end(); iter++) {
            (*iter)->print();
        }
    }
};

int main(int argc, const char * argv[]) {
    MenuComponent* allMenus = new Menu("ALL MENUS");
    MenuComponent* dinerMenu = new Menu("DINER MENU");
    MenuComponent* oneFood = new MenuItem("ONE FOOD", 3.23);
    allMenus->add(dinerMenu);
    dinerMenu->add(oneFood);
    allMenus->print();
    return 0;
}
