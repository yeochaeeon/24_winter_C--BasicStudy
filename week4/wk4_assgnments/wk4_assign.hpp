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

		// ������ ( �Ű����� ���� ����Ʈ ������, �Ű����� m_name, m_hp, m_power�� ������ )
            Human(); // ����Ʈ ������ ���� 
            Human( char* t_name, int t_hp, int t_power ); // ������ ���� 
	} ;

}