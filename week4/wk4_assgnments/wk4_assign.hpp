#include <iostream>
#include <string>

namespace week04
{
	class Human
	{
		// ��� ���� ( m_name, m_hp, m_power )
        private :
            char * m_name;
            int m_hp;
            int m_power;

		// ��� �Լ� ( Attack, GetInfo )
        public:
            void Attack(Human &defender) ;
            void GetInfo(Human) ;

		// ������ ( 1. �Ű����� ���� ����Ʈ ������, 2. �Ű����� m_name, m_hp, m_power�� ������ )
    
            Human(); // 1. ����Ʈ ������ ���� 
            Human( char* t_name, int t_hp, int t_power ); // 2. �Ű������� �ִ� ������ ���� 
	} ;

}