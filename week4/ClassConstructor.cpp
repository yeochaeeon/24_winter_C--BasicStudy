#include <iostream>

class Human
{
  public:
    // ��� �Լ� 
    char* GetName() const { return m_name ; }
    int GetAge() const { return m_age ; }

    // void show(){
    //   std::cout << "�� �̸��� " << m_name << "�Դϴ� !" << std::endl 
    //   << "���� " << m_age << "�� �Դϴ� ! " << std::endl;
    // };

    // ������
    Human( char* t_name, int t_age );
    //  : m_name( t_name ), m_age( t_age ) {}

    // �Ҹ���
    ~Human() {};

    

  private:
    // ��� ����
    char* m_name ;
    int m_age ;
};


Human::Human( char* t_name, int t_age )
{
  m_name = t_name ;
  m_age = t_age ;
}

int main(){
    
    //Human me = {"��ä��", 22 };
   
    Human me("��ä��", 22); 
    // Human.();

    std::cout << "�� �̸��� " << me.GetName() << "�Դϴ� !" << std::endl 
       << "���� " << me.GetAge() << "�� �Դϴ� ! " << std::endl;
    return 0;

}