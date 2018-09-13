#include <iostream>

using namespace std;

class Operation {
protected:
    double numberA;
    double numberB;
public:
    virtual double getResult() {
        return 0;
    };
    void setNumberA(double a) {
        numberA = a;
    }
    void setNumberB(double b) {
        numberB = b;
    }
    double getNumberA() {
        return numberA;
    }
    double getNumberB() {
        return numberB;
    }
};

class OperationAdd : public Operation {
public:
    double getResult() {
        return numberA + numberB;
    }
};

class OperationSub : public Operation {
public:
    double getResult() {
        return numberA - numberB;
    }
};

class OperationMul : public Operation {
public:
    double getResult() {
        return numberA * numberB;
    }
};

class OperationDiv : public Operation {
public:
    double getResult() {
        if(-0.00000001 < numberB && numberB < 0.00000001) {
            cout << "除零错误" << endl;
            return 0;
        }
        return numberA / numberB;
    }
};

class OperationFactory {
private:
    Operation* operation;
public:
    OperationFactory():operation(NULL){}
    ~OperationFactory() {
        delete operation;
    }
    Operation* CreateOperate(char o) {
        switch(o) {
            case '+':
                operation = new OperationAdd();
                break;
            case '-':
                operation = new OperationSub();
                break;
            case '*':
                operation = new OperationMul();
                break;
            case '/':
                operation = new OperationDiv();
                break;
            default:
                cout << "无法识别该符号" << endl;;
        }
        return operation;
    }
};

int main(int argc, const char * argv[]) {
    double numberA;
    double numberB;
    char operate;
    
    cout<<"输入数字A: ";
    cin>>numberA;
    
    cout<<"运算符(+ - * /): ";
    cin>>operate;
    
    cout<<"输入数字B: ";
    cin>>numberB;
    
    OperationFactory factory;
    Operation* operation;
    
    operation = factory.CreateOperate(operate);
    operation->setNumberA(numberA);
    operation->setNumberB(numberB);

    cout<<"计算结果："<<operation->getResult()<<endl;
    return 0;
}
