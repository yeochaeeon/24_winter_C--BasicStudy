#include <iostream>

class human {
  
  private:
    char * m_name;
    int m_age;
  
  
  public :
    char * GetName() { return m_name; }
    int GetAge() { return m_age; }

    //constructor 

    human(char * t_name, int t_age) : m_name( t_name ), m_age( t_age ) {} 
    // t == temporaty , m == member 
    // 마무리 {} 도 필수 

    // destructor 

    ~human() {}

    void show();
};


void human::show(){

  std::cout << "저의 이름은 " << GetName() << "입니다" <<std::endl 
  << "저는 " << GetAge() << "살 입니다." << std::endl << std::endl ;

}


int main(){

  human me("여채언", 22);
  human you("옥소미", 21);
  me.show();
  you.show();

}