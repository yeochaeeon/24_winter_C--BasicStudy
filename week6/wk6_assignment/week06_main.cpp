#include <vector>
#include "week06.hpp"

//// ( 1 ) ////
////// Animal�� ������, �Ҹ���, GetName ����







////////////////////////////////////////

////// Dog�� ������, Action ����






////////////////////////////////////////

////// Cat�� ������, Action ����






////////////////////////////////////////


int main( )
{
	//// ( 2 ) ////
	////// ��ü���� ������ vector ����




	////////////////////////////////////////

	int mainNum, objNum, tempNum ;
	std::string tempName ;
	bool exitFlag = 0 ;

	while( true )
	{
		std::cout << "\n  (1) Dog ��ü ����  /  (2) Cat ��ü ����  /  (3) ��ü ��ü Action  /  (4) ����  " << std::endl;
		std::cin >> mainNum ;
		switch( mainNum )
		{
			case 1 :
				std::cout << "�̸�, ���� ���� Ƚ�� �Է�( ���� ���� )" << std::endl ;
				//// ( 3 ) ////
				////// ����ڷκ��� String, Int�� �Է� �޾� Dog ��ü ���� ( new �̿� )




				/////////////////////////////////////////////////////////////
				break ;

			case 2 :
				std::cout << "�̸�, ���� ���� �Է�( ���� ���� )" << std::endl ;
				//// ( 3 ) ////	
				////// ����ڷκ��� string, int�� �Է� �޾� Cat ��ü ���� ( new �̿� )



				/////////////////////////////////////////////////////////////
				break ;

			case 3 :
				std::cout << "\n!Action! " << std::endl ;
				//// ( 4 ) ////
				////// vector�� ��ȸ�ϸ� �� ��ü�� Action ȣ��





				/////////////////////////////////////////////////////////////
				break ;

			case 4 :
				std::cout << "���α׷� ����!" << std::endl ;
				exitFlag = 1 ;
				break ;

			default :
				std::cout << "�߸��� �Է��Դϴ�." << std::endl ;	
        		std::cin.clear() ;
        		std::cin.ignore( INT_MAX, '\n' ) ;
				continue;
		}
		if ( exitFlag ) break ;
	}
	//// ( 5 ) ////
	////// vector�� ��ȸ�ϸ� �� ��ü�� �Ҹ��� ȣ��




	/////////////////////////////////////////////////////////////
	return 0 ;
}