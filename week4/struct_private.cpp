#include <iostream>

struct Human {
  private:
    char *name;
    int age ;

  public:
    void show();
    void SetInfo( char * _name, int _age ) ;

};

void Human::show(){

    std::cout << "�� �̸��� " << name << "�Դϴ� !" << std::endl 
      << "���� " << age << "�� �Դϴ� ! " << std::endl;

}

void Human::SetInfo (char* _name, int _age ) {

    name = _name;
    age = _age;

}

int main(){
    
    //Human me = {"��ä��", 22 };
    Human me;
    me.SetInfo("��ä��", 22);
    me.show();
    return 0;

}