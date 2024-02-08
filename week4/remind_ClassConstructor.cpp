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
    // ������ {} �� �ʼ� 

    // destructor 

    ~human() {}

    void show();
};


void human::show(){

  std::cout << "���� �̸��� " << GetName() << "�Դϴ�" <<std::endl 
  << "���� " << GetAge() << "�� �Դϴ�." << std::endl << std::endl ;

}


int main(){

  human me("��ä��", 22);
  human you("���ҹ�", 21);
  me.show();
  you.show();

}