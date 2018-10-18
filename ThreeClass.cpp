//本质为一个类只能有一个实例对象

class ThreeClass {
private:
    static ThreeClass instance1;
    static ThreeClass instance2;
    static ThreeClass instance3;
    
    ThreeClass(){}
    
public:
    static ThreeClass getInstance() {
        if (instance1==null) {
            instance1 = new ThreeClass();
            return instance1;
        } else if (instance2==null) {
            instance2 = new ThreeClass();
            return instance2;
        } else if (instance3==null) {
            instance3 = new ThreeClass();
            return instance3;
        }
        return instance3;
    }
}
