#include <iostream>
#include <string>

class Person {
protected: // private 로 바꾸고 다시 해보기 
    std::string name;
public:
    Person(std::string n) : name(n) {}
    std::string getName() {
        return name;
    }
};

////Student, Teacher 클래스 정의

class Student : public Person {
public :
    Student(std::string n) : Person(n) {}
    void study() {
        std::cout << name << " is studying" << std::endl;
    } // name 대신 getName()
};

class Teacher :  public Person {
public :
    Teacher(std::string n) : Person(n) {}
    void teach (){
        std::cout << name << " is teaching" << std::endl;
    } // name 대신 getName()
} ;

////

int main() {
    Student student("John");
    Teacher teacher("Anna");

    student.study();
    teacher.teach();

    return 0;
}