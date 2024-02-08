#include <iostream>

struct Human {
    char * name;
    int age ;

    void show();
}; //구조체 선언 후 세미콜론 필수 


void Human::show() { // 리턴타입 명시 필수 

    std::cout << "제 이름은 " << name << "입니다 !" << std::endl 
      << "저는 " << age << "살 입니다 ! " << std::endl;

}

int main(){
    
  Human me = {"채언", 22};
  me.show();

}
