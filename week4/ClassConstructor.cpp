#include <iostream>

class Human
{
  public:
    // 멤버 함수 
    char* GetName() const { return m_name ; }
    int GetAge() const { return m_age ; }

    // void show(){
    //   std::cout << "제 이름은 " << m_name << "입니다 !" << std::endl 
    //   << "저는 " << m_age << "살 입니다 ! " << std::endl;
    // };

    // 생성자
    Human( char* t_name, int t_age );
    //  : m_name( t_name ), m_age( t_age ) {}

    // 소멸자
    ~Human() {};

    

  private:
    // 멤버 변수
    char* m_name ;
    int m_age ;
};


Human::Human( char* t_name, int t_age )
{
  m_name = t_name ;
  m_age = t_age ;
}

int main(){
    
    //Human me = {"여채언", 22 };
   
    Human me("여채언", 22); 
    // Human.();

    std::cout << "제 이름은 " << me.GetName() << "입니다 !" << std::endl 
       << "저는 " << me.GetAge() << "살 입니다 ! " << std::endl;
    return 0;

}