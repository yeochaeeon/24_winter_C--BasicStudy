#include "wk4_assign.hpp"
#include <iostream>

/////// Human 클래스의 생성자 정의 ( 1.매개변수가 없는 생성자, 2. 매개변수 m_name, m_hp, m_power인 생성자)

week04::Human::Human() : m_name("여채언"), m_hp(5000), m_power(10) {} // 1.디폴트 생성자 정의 (간략한 방식)

week04::Human::Human( char* t_name, int t_hp, int t_power )  // 2. 매개변수 m_name, m_hp, m_power인 생성자
{
    m_name = t_name ;
    m_hp = t_hp ;
    m_power = t_power ;
}
/////////////////////////////////////////


///////멤버 함수 Attack, GetInfo 정의 

void week04::Human::GetInfo(Human){
    std::cout << m_name << "의 정보" << std::endl
                << "체력: " << m_hp << ", " << "파워: " << m_power << std::endl<< std::endl;
}

void week04::Human::Attack(Human &defender) {
    std::cout << "데미지 " << m_power << "만큼의 공격 수행!" << std::endl
                << "공격자: " << m_name << " => " << "방어자: " << defender.m_name << std::endl;

    defender.m_hp -= 10;
}
///////////////////////////////////////////


int main( )
{
	////// 객체 생성
	week04::Human attacker ; // 디폴트 생성자 암시적 호출 
	week04::Human defender("이창율", 50, 10);

	////// 공격 전 객체 정보 확인
	std::cout << "\n====================== " << std::endl;	
	std::cout << "공격 전 객체 정보 확인 " << std::endl;
	std::cout << "======================\n" << std::endl;	
	attacker.GetInfo( attacker );
	defender.GetInfo( defender );

	////// 공격 수행
	std::cout << "\n====================== " << std::endl;	
	std::cout << "공격 수행 " << std::endl;
	std::cout << "======================\n" << std::endl;	
	attacker.Attack( defender ) ;
	
	////// 공격 후 객체 정보 확인
	std::cout << "\n====================== " << std::endl;	
	std::cout << "공격 후 객체 정보 확인" << std::endl;
	std::cout << "======================\n" << std::endl;	
	attacker.GetInfo( attacker );
	defender.GetInfo( defender );


	return 0;
}