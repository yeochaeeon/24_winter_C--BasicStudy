#include "week2.hpp"
#include <iostream>

void week2::drawStar()
{
	// ����ڷκ��� �ݺ� Ƚ���� �Է¹޾Ƽ� �ش� Ƚ����ŭ ���� ���� ������ ����մϴ�.
	// �� �ٸ��� ���� ������ 1���� �þ�ϴ�.
	// �ۼ��� �Ʒ� �ڵ� ������ �ۼ��� �ּ���
	// !! �Լ��� ȣ�� �Ǿ�����, __func__�� �̿��� "drawStar�Լ� ȣ��!" �̶�� ������ ��µǰ� ���ּ��� !!
	int number ;
	std::cout << __func__ << "�Լ� ȣ��!" << std::endl;
	std::cout << "�ݺ� Ƚ���� �Է��ϼ��� : " ;
	std::cin >> number ;
	for(int i = 1; i<= number ; i++){
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int week2::add( int a, int b) {
	return a + b;
}

// ���ڷ� ���޵� 2���� int ������ ���� ���� ���� ��ȯ�ϴ� �Լ� add�� �ۼ��� �ּ���.
// add �Լ��� week02 ���ӽ����̽��� ���ǵǾ� �ֽ��ϴ�.

int main()

{
	int choice = 0;
	int a,b;

	while ( true )
	{	
		std::cout << "====================================" << std::endl;	
		std::cout << "1. �� ���" 
					<< " 2. ���ϱ�" 
						<< " 3. ����" << std::endl;

		// switch ���� ����ؼ� choice ������ ���� ���� ���ϴ� ����� �����ϵ��� �������ּ���
		// 1, 2, 3�� �ƴ� �ٸ� �Է��� ������, �߸��� �Է��̶� ������ ����ϰ� �ٽ� �Է��ϵ��� ������ �ּ���.
		// 1�� : �� ���, 2�� : ���ϱ�, 3�� : ���α׷� ����
		// !! ���ڰ� �ԷµǾ �ٽ� �Է��ϵ��� ������ �ּ��� !!
		
		std::cin >> choice ;
		switch(choice) {
			case 1 : 
				week2::drawStar();
				break;
			case 2 :
				printf("���� �� ���� �Է��ϼ���!\n");
				std::cin >> a >> b;
				week2::add(a,b);
				std::cout << a << "���ϱ�" << b << "(��)��" << week2::add(a,b) << "�Դϴ�." << std::endl;
				break;
			case 3 :
				printf("���� !");
				return 0;
			default : 
				printf("�߸��� �Է��Դϴ�.\n");
				std::cin.clear();
				while (std::cin.get() != '\n');
				// cin.ignore(100,'\n') 
				// cin.ignore( ����� ���� ������ ���� , ������ )
				//while (std::cin.get() != '\n');
				//std::cin.ignore(); 
		}
	}	
}