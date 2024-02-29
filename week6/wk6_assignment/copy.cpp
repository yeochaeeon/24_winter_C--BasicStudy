#include <vector>
#include "week06.hpp"

//// ( 1 ) ////
////// Animal�� ������, �Ҹ���, GetName ����

week06::Animal::Animal(std::string t_name) : m_name(t_name) {} 
week06::Animal::~Animal() {}
std::string week06::Animal::GetName()
{
    return m_name;
}

////////////////////////////////////////

////// Dog�� ������, Action ����

week06::Dog::Dog(std::string t_name, int t_waveNumber) : Animal(t_name), m_waveNumber(t_waveNumber) {}
void week06::Dog::Action()
{
	std::cout << GetName() << " ��(��) ������ " << m_waveNumber << "�� ���ϴ�!" << std::endl;

}



////////////////////////////////////////

////// Cat�� ������, Action ����

week06::Cat::Cat(std::string t_name, int t_jumpHeight) : Animal(t_name), m_jumpHeight(t_jumpHeight) {}
void week06::Cat::Action()
{
	std::cout << GetName() << " ��(��) " << m_jumpHeight << " cm��ŭ �����մϴ�!" << std::endl;

}


////////////////////////////////////////


int main( )
{
	//// ( 2 ) ////
	////// ��ü���� ������ vector ����
	std::vector<week06::Animal*> Animallist; //��ü�� �����͸� �����ؾ� �ϹǷ� <������ *(int* �� �����ϴ°�ó��.)>
	std::vector <week06::Animal*>:: iterator iter; //���͸� ��ȯ�ϱ� ���� �ݺ��� ����. iter�� ���� ���� ����� �ּڰ�!

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
			{
				std::cout << "�̸�, ���� ���� Ƚ�� �Է�( ���� ���� )" << std::endl;
				//// ( 3 ) ////
				////// ����ڷκ��� String, Int�� �Է� �޾� Dog ��ü ���� ( new �̿� )
				//new: �����޸� �Ҵ�. new�����ڴ� �ش� �޸𸮸� ����Ͽ� ��ü�� ���� ���� �Ҵ�� �޸��� �ּҰ� ���Ե� �����͸� ��ȯ�Ѵ�.
				std::cin >> tempName >> tempNum;
				week06::Dog *dog = new week06::Dog(tempName, tempNum);
				std::cout << "Animal ������ ȣ��\nDog ������ ȣ��" << std::endl;
				Animallist.push_back(dog); //��ü�� �ּڰ��� �߰�
				/////////////////////////////////////////////////////////////
				break ;
			}

			case 2 :
			{
				std::cout << "�̸�, ���� ���� �Է�( ���� ���� )" << std::endl ;
				//// ( 3 ) ////	
				////// ����ڷκ��� string, int�� �Է� �޾� Cat ��ü ���� ( new �̿� )
				std::cin >> tempName >> tempNum;
				week06::Cat *cat = new week06::Cat(tempName, tempNum);
				std::cout << "Animal ������ ȣ��\nCat ������ ȣ��" << std::endl;
				Animallist.push_back(cat);
				/////////////////////////////////////////////////////////////
				break ;
			}

			case 3 :
				std::cout << "\n!Action! " << std::endl ;
				//// ( 4 ) ////
				////// vector�� ��ȸ�ϸ� �� ��ü�� Action ȣ��
				for(iter = Animallist.begin(); iter != Animallist.end(); iter++) //vector.end()�� vector�� ���� + 1 �ּ� ��ȯ (�� ��� �ּ� �ƴ� ����!)
				{
					(*iter)->Action(); //���⼭ ȭ��ǥ �����ڸ� ����ؾ� �ϴ� ������..?
				}	//iter �� �ּҸ� ����Ű�� �ݺ����� . �׷��� *iter ��ü�� �ּҰ� ��.
					//����Ƽ ��, *iter�� �����Ͱ� ����Ű�� ��ü�� ��Ÿ����, (*iter)->Action();�� �ش� ��ü�� Action ��� �Լ��� ȣ���ϴ� ���Դϴ�. 
					//���� ������ ��Ұ� ��ü ��ü��� *iter.Action();�� ���� ���� ȣ���� �� �ְ�����, 
					//���⼭�� ��ü�� ���� �������̹Ƿ� (*iter)->Action();�� ����ؾ� �մϴ�.

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
	for(iter = Animallist.begin(); iter != Animallist.end(); iter++)
	{
		(*iter)->~Animal();
	}



	/////////////////////////////////////////////////////////////
	return 0 ;
}


//error ����:
//ó���� case���� ���õ� ������ ����. case�� �ȿ� �������� dog�� cat�� �������־��� �����ε�, ������������ �߰�ȣ{}�� �����ֱ⸦ ������ �� �ֱ� ������, 
//�Ϲ������� Swich���� �ۼ��Ѵٸ� �߰�ȣ�� ������� �ʾƵ� ������, Ư�� case�ȿ����� ���������� Ȱ���ϰ� �ʹٸ� �߰�ȣ�� ����Ͽ� ������ ������ �־�� �Ѵٰ� �Ѵ�.
//�߰�ȣ�� �ٿ��ִϱ� �ٷ� �����۵� �Ǿ���.
//�ñ��� ����: (*iter)->Action() ���� ȭ��ǥ�� ��Ʈ ����� ������...? �׸��� objNum �� ��� ����ؾ� �ϴ°���...! 