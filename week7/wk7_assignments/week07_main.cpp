//#include "week07.hpp"
#include <iostream>
#include <string>
#include <algorithm>

namespace week07
{
	class Human
	{
		private:
		int m_age ;
		std::string m_name ;

		public:
		Human() {}
		Human( int , std::string ) ;

		Human operator+( Human& ) ; //������ �Ҷ� human:: �� �ʿ��� ..�ֳ��ϸ� human�� ����̱� �����̰� ..
		friend std::ostream& operator<<( std::ostream& , const Human& ) ; // const : ���� ������ �ʱ� ������ . (const�� default�� �ٿ��ִ°� ���ƿ밡��ġŲ.)
		friend std::istream& operator>>( std::istream& , Human& ) ; //�Է��� �޴� ��ü�� ���� ���� �� �ֱ� ������ const ������ 
        // friend : �ۿ��� ������ �Լ��� ���ٰ� �����.��, human�� private����Լ��� ������ �� �ִ� �ɷ��� �ο��� �Լ� 
	} ;
} 
/////// ( 1 ) ///////

week07::Human::Human(int t_age, std::string t_name): m_age(t_age),m_name(t_name) {}

/////////////////////
/////// ( 2 ) ///////

week07::Human week07::Human::operator+(Human& b) {
        int newAge = m_age + b.m_age;
        std::string newName = std::min(m_name, b.m_name);
        return Human(newAge, newName);
    }


/////////////////////

/////// ( 3 ) ///////

std::ostream& week07::operator<<(std::ostream& os, const Human& human)
{
    //std::cout << "========== + ������ ȣ�� ==========" << std::endl;

    os << "Name: " << human.m_name << ", Age: " << human.m_age;
    return os;
}



/////////////////////

/////// ( 4 ) ///////
std::istream& week07::operator>>(std::istream& is, Human& human)
{
    std::cout << "�̸�, ���� �Է� (���� ����) "; 
    is >> human.m_name >> human.m_age;
    //std::getline(is >> std::ws, human.m_name);
    return is;
}


/////////////////////


int main()
{
	week07::Human a ;
	week07::Human b ;

	std::cout << "========== ��ü 2�� �Է� ==========" << std::endl ;

	std::cin >> a ;
	std::cin >> b ;	

	std::cout << a << std::endl ;
	std::cout << b << std::endl ;


	week07::Human c = a + b ;

	std::cout << "\n========== C ���� ��� ==========" << std::endl ;
	std::cout << c << std::endl ;

	return 0 ;
}
