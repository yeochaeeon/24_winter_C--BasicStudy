#include <iostream>

struct Human {
  private:
    char *name;
    int age ;

  // 갑자기 함수가?
  public:
    void show(){
      std::cout << "제 이름은 " << name << "입니다 !" << std::endl 
      << "저는 " << age << "살 입니다 ! " << std::endl;
    };
    void SetInfo( char * _name, int _age ) ;

};

// void Human::show(){
//   std::cout << <<std::endl;
//   std::cout << <<std::endl;
// }

void Human::SetInfo (char* _name, int _age ) {

    name = _name;
    age = _age;

}

int main(){
    
    //Human me = {"여채언", 22 };
    Human me;
    me.SetInfo("여채언", 22);
    me.show();
    return 0;

}