#include "wk4_assign.hpp"
#include <iostream>

/////// Human Ŭ������ ������ ���� ( 1.�Ű������� ���� ������, 2. �Ű����� m_name, m_hp, m_power�� ������)

week04::Human::Human() : m_name("��ä��"), m_hp(5000), m_power(10) {} // 1.����Ʈ ������ ���� (������ ���)

week04::Human::Human( char* t_name, int t_hp, int t_power )  // 2. �Ű����� m_name, m_hp, m_power�� ������
{
    m_name = t_name ;
    m_hp = t_hp ;
    m_power = t_power ;
}
/////////////////////////////////////////


///////��� �Լ� Attack, GetInfo ���� 

void week04::Human::GetInfo(Human){
    std::cout << m_name << "�� ����" << std::endl
                << "ü��: " << m_hp << ", " << "�Ŀ�: " << m_power << std::endl<< std::endl;
}

void week04::Human::Attack(Human &defender) {
    std::cout << "������ " << m_power << "��ŭ�� ���� ����!" << std::endl
                << "������: " << m_name << " => " << "�����: " << defender.m_name << std::endl;

    defender.m_hp -= 10;
}
///////////////////////////////////////////


int main( )
{
	////// ��ü ����
	week04::Human attacker ; // ����Ʈ ������ �Ͻ��� ȣ�� 
	week04::Human defender("��â��", 50, 10);

	////// ���� �� ��ü ���� Ȯ��
	std::cout << "\n====================== " << std::endl;	
	std::cout << "���� �� ��ü ���� Ȯ�� " << std::endl;
	std::cout << "======================\n" << std::endl;	
	attacker.GetInfo( attacker );
	defender.GetInfo( defender );

	////// ���� ����
	std::cout << "\n====================== " << std::endl;	
	std::cout << "���� ���� " << std::endl;
	std::cout << "======================\n" << std::endl;	
	attacker.Attack( defender ) ;
	
	////// ���� �� ��ü ���� Ȯ��
	std::cout << "\n====================== " << std::endl;	
	std::cout << "���� �� ��ü ���� Ȯ��" << std::endl;
	std::cout << "======================\n" << std::endl;	
	attacker.GetInfo( attacker );
	defender.GetInfo( defender );


	return 0;
}