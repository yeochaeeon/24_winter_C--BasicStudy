#include <iostream>

struct Human {
    char * name;
    int age ;

    void show();
}; //����ü ���� �� �����ݷ� �ʼ� 


void Human::show() { // ����Ÿ�� ��� �ʼ� 

    std::cout << "�� �̸��� " << name << "�Դϴ� !" << std::endl 
      << "���� " << age << "�� �Դϴ� ! " << std::endl;

}

int main(){
    
  Human me = {"ä��", 22};
  me.show();

}
