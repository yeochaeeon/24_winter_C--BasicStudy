#include "wk4_assign.hpp"
#include <iostream>
/////// Human Ŭ������ ������ ���� ( �Ű������� ���� ������, �Ű����� m_name, m_hp, m_power�� ������)


////////////////

/////// ��� �Լ� Attack, GetInfo ����


////////////////


int main( )
{
	////// ��ü ����
	week04::Human attacker ;
	week04::Human defender( "��â��", 50, 10 )  ;

	////// ���� �� ��ü ���� Ȯ��
	std::cout << "\n====================== " << std::endl;	
	std::cout << "���� �� ��ü ���� Ȯ�� " << std::endl;
	std::cout << "======================\n" << std::endl;	
	week04::Human::GetInfo( attacker );
	week04::Human::GetInfo( defender );

	////// ���� ����
	std::cout << "\n====================== " << std::endl;	
	std::cout << "���� ���� " << std::endl;
	std::cout << "======================\n" << std::endl;	
	attacker.Attack( defender ) ;
	
	////// ���� �� ��ü ���� Ȯ��
	std::cout << "\n====================== " << std::endl;	
	std::cout << "���� �� ��ü ���� Ȯ��" << std::endl;
	std::cout << "======================\n" << std::endl;	
	week04::Human::GetInfo( attacker );
	week04::Human::GetInfo( defender );


	return 0;
}