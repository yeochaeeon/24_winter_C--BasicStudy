#include <iostream>
#include <string>

class Person {
protected: // private �� �ٲٰ� �ٽ� �غ��� 
    std::string name;
public:
    Person(std::string n) : name(n) {}
    std::string getName() {
        return name;
    }
};

////Student, Teacher Ŭ���� ����

class Student : public Person {
public :
    Student(std::string n) : Person(n) {}
    void study() {
        std::cout << name << " is studying" << std::endl;
    } // name ��� getName()
};

class Teacher :  public Person {
public :
    Teacher(std::string n) : Person(n) {}
    void teach (){
        std::cout << name << " is teaching" << std::endl;
    } // name ��� getName()
} ;

////

int main() {
    Student student("John");
    Teacher teacher("Anna");

    student.study();
    teacher.teach();

    return 0;
}