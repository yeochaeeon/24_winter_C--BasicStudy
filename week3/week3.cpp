#include <iostream>

int& add(int& a , int& b) {
    
    int sum = a + b;
    int& ret_val = sum;

    return ret_val;
    //return sum;
}

int main() {

    int num1 = 1;
    int num2 = 2;

    int& a = num1;
    int& b = num2;

    std::cout << add(num1, num2) << std::endl;
}



