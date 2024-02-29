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

		Human operator+( Human& ) ; //재정의 할때 human:: 이 필요함 ..왜냐하면 human의 멤버이기 때문이고 ..
		friend std::ostream& operator<<( std::ostream& , const Human& ) ; // const : 값이 변하지 않기 때문에 . (const는 default로 붙여주는게 좋아용가리치킨.)
		friend std::istream& operator>>( std::istream& , Human& ) ; //입력을 받는 객체라서 값이 변할 수 있기 때문에 const 가빠짐 
        // friend : 밖에서 정의한 함수와 같다고 보면됨.단, human의 private멤버함수에 접근할 수 있는 능력이 부여된 함수 
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
    //std::cout << "========== + 연산자 호출 ==========" << std::endl;

    os << "Name: " << human.m_name << ", Age: " << human.m_age;
    return os;
}



/////////////////////

/////// ( 4 ) ///////
std::istream& week07::operator>>(std::istream& is, Human& human)
{
    std::cout << "이름, 나이 입력 (띄어쓰기 구분) "; 
    is >> human.m_name >> human.m_age;
    //std::getline(is >> std::ws, human.m_name);
    return is;
}


/////////////////////


int main()
{
	week07::Human a ;
	week07::Human b ;

	std::cout << "========== 객체 2개 입력 ==========" << std::endl ;

	std::cin >> a ;
	std::cin >> b ;	

	std::cout << a << std::endl ;
	std::cout << b << std::endl ;


	week07::Human c = a + b ;

	std::cout << "\n========== C 정보 출력 ==========" << std::endl ;
	std::cout << c << std::endl ;

	return 0 ;
}
