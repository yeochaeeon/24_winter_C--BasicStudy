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
    Derived() : Base(10) { // �θ� Ŭ������ �����ڸ� ��������� ȣ��
        std::cout << "Derived constructor" << std::endl;
    }
};

int main() {
    
    Derived d;

    return 0;
}