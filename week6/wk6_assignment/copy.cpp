#include <vector>
#include "week06.hpp"

//// ( 1 ) ////
////// Animal의 생성자, 소멸자, GetName 정의

week06::Animal::Animal(std::string t_name) : m_name(t_name) {} 
week06::Animal::~Animal() {}
std::string week06::Animal::GetName()
{
    return m_name;
}

////////////////////////////////////////

////// Dog의 생성자, Action 정의

week06::Dog::Dog(std::string t_name, int t_waveNumber) : Animal(t_name), m_waveNumber(t_waveNumber) {}
void week06::Dog::Action()
{
	std::cout << GetName() << " 이(가) 꼬리를 " << m_waveNumber << "번 흔듭니다!" << std::endl;

}



////////////////////////////////////////

////// Cat의 생성자, Action 정의

week06::Cat::Cat(std::string t_name, int t_jumpHeight) : Animal(t_name), m_jumpHeight(t_jumpHeight) {}
void week06::Cat::Action()
{
	std::cout << GetName() << " 이(가) " << m_jumpHeight << " cm만큼 점프합니다!" << std::endl;

}


////////////////////////////////////////


int main( )
{
	//// ( 2 ) ////
	////// 객체들을 저장할 vector 정의
	std::vector<week06::Animal*> Animallist; //객체의 포인터를 저장해야 하므로 <생성자 *(int* 로 선언하는것처럼.)>
	std::vector <week06::Animal*>:: iterator iter; //벡터를 순환하기 위한 반복자 지정. iter에 들어가는 값은 요소의 주솟값!

	////////////////////////////////////////

	int mainNum, objNum, tempNum ;
	std::string tempName ;
	bool exitFlag = 0 ;

	while( true )
	{
		std::cout << "\n  (1) Dog 객체 생성  /  (2) Cat 객체 생성  /  (3) 전체 객체 Action  /  (4) 종료  " << std::endl;
		std::cin >> mainNum ;
		switch( mainNum )
		{
			case 1 :
			{
				std::cout << "이름, 꼬리 흔드는 횟수 입력( 띄어쓰기 구분 )" << std::endl;
				//// ( 3 ) ////
				////// 사용자로부터 String, Int를 입력 받아 Dog 객체 생성 ( new 이용 )
				//new: 동적메모리 할당. new연산자는 해당 메모리를 사용하여 객체를 만든 다음 할당된 메모리의 주소가 포함된 포인터를 반환한다.
				std::cin >> tempName >> tempNum;
				week06::Dog *dog = new week06::Dog(tempName, tempNum);
				std::cout << "Animal 생성자 호출\nDog 생성자 호출" << std::endl;
				Animallist.push_back(dog); //객체의 주솟값을 추가
				/////////////////////////////////////////////////////////////
				break ;
			}

			case 2 :
			{
				std::cout << "이름, 점프 높이 입력( 띄어쓰기 구분 )" << std::endl ;
				//// ( 3 ) ////	
				////// 사용자로부터 string, int를 입력 받아 Cat 객체 생성 ( new 이용 )
				std::cin >> tempName >> tempNum;
				week06::Cat *cat = new week06::Cat(tempName, tempNum);
				std::cout << "Animal 생성자 호출\nCat 생성자 호출" << std::endl;
				Animallist.push_back(cat);
				/////////////////////////////////////////////////////////////
				break ;
			}

			case 3 :
				std::cout << "\n!Action! " << std::endl ;
				//// ( 4 ) ////
				////// vector을 순회하며 각 객체의 Action 호출
				for(iter = Animallist.begin(); iter != Animallist.end(); iter++) //vector.end()는 vector의 끝점 + 1 주소 반환 (끝 요소 주소 아님 주의!)
				{
					(*iter)->Action(); //여기서 화살표 연산자를 사용해야 하는 이유는..?
				}	//iter 는 주소를 가리키는 반복자임 . 그래서 *iter 자체는 주소가 됨.
					//지피티 왈, *iter는 포인터가 가리키는 객체를 나타내고, (*iter)->Action();은 해당 객체의 Action 멤버 함수를 호출하는 것입니다. 
					//만약 벡터의 요소가 객체 자체라면 *iter.Action();과 같이 직접 호출할 수 있겠지만, 
					//여기서는 객체에 대한 포인터이므로 (*iter)->Action();을 사용해야 합니다.

				/////////////////////////////////////////////////////////////
				break ;

			case 4 :
				std::cout << "프로그램 종료!" << std::endl ;
				exitFlag = 1 ;
				break ;

			default :
				std::cout << "잘못된 입력입니다." << std::endl ;	
        		std::cin.clear() ;
        		std::cin.ignore( INT_MAX, '\n' ) ;
				continue;
		}
		if ( exitFlag ) break ;
	}
	//// ( 5 ) ////
	////// vector을 순회하며 각 객체의 소멸자 호출
	for(iter = Animallist.begin(); iter != Animallist.end(); iter++)
	{
		(*iter)->~Animal();
	}



	/////////////////////////////////////////////////////////////
	return 0 ;
}


//error 사항:
//처음에 case문과 관련된 오류가 났다. case문 안에 지역변수 dog과 cat를 선언해주었기 때문인데, 지역변수들은 중괄호{}로 생명주기를 지정할 수 있기 때문에, 
//일반적으로 Swich문을 작성한다면 중괄호를 사용하지 않아도 되지만, 특정 case안에서만 지역변수를 활용하고 싶다면 중괄호를 사용하여 범위를 지정해 주어야 한다고 한다.
//중괄호를 붙여주니까 바로 정상작동 되었다.
//궁금한 사항: (*iter)->Action() 에서 화살표와 도트 사용의 차이점...? 그리고 objNum 을 어디에 사용해야 하는건지...! 