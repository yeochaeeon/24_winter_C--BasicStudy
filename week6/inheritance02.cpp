#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }
    Base(int x) {
        std::cout << "Base constructor with value " << x << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() : Base(10) { // 부모 클래스의 생성자를 명시적으로 호출
        std::cout << "Derived constructor" << std::endl;
    }
};

int main() {
    
    Derived d;

    return 0;
}