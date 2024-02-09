#include <iostream>
#include <string>

namespace week04
{
	class Human
	{
		// 멤버 변수 ( m_name, m_hp, m_power )
        private :
            char * m_name;
            int m_hp;
            int m_power;
            
		// 멤버 함수 ( Attack, GetInfo )
        public:
            void Attack(Human &defender) ;
            void GetInfo(Human) ;

		// 생성자 ( 매개변수 없는 디폴트 생성자, 매개변수 m_name, m_hp, m_power인 생성자 )
            Human(); // 디폴트 생성자 선언 
            Human( char* t_name, int t_hp, int t_power ); // 생성자 선언 
	} ;

}