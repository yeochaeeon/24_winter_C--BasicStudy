# C++_Basic_Week_05

_�ۼ��� : Ȳ����_

> ����� �����?

---

<br>

�ȳ��ϼ��� ������ ������û�� �� �ϼ̳���?   
�����е��� ��ó�� 4�г⿡ �ð�ǥ§�ٰ� ����Ͻ��� ���ð�, �̸��̸� �������ǥ ���ð� ��ȹ �����νñ� �ٶ��ϴ�...   

<!-- ![����](../images/robot.jpeg)

--- -->

<p align="center">
<img src = "../images/robot.jpeg" width="80%" height="80%" title="robot"></img>
<br>�̸�... �̸�!!!!
</p>

���� �� �������� �����ϰ� �Ѿ�ڽ��ϴ�.   

## ���� ����

### 1. ��� ����

**`#include<iostream>`�� �ѹ��� ��� �˴ϴ�.**
 
 `#include "week04.hpp"`�� ��ó�� �������� ó���Ǵ� �����Դϴ�. ������ �������� ó���Ǵµ�, `week04.hpp` ������ ������ ��� �ش� ���Ͽ� �ٿ��ֱ��մϴ�.

```cpp
// week04.hpp
#include <iostream>
```

```cpp
// week04_main.cpp
#include "week04.hpp"
```
���� `week04.hpp`�� ǥ�� ����� ���̺귯�� `iostream`�� ������ ��� ���� �ٿ��ֱ� �˴ϴ�. �׷� `week04_main.cpp`���� `#include <iostream>` �� �����ص� `iostream` ���̺귯���� ��� �� �� �ֽ��ϴ�. ?

### 2. Static

�������� �����帰 **��ü ���� ���� ������ ������ �������� �Լ� `GetInfo` ��** `static` Ű���带 ����Ͻø� ������ �����մϴ�. `static`���� ���� �� ��� �Լ��� ��� ������ ���� ��ü�� ����Ű�� `this`��� Ű����� ���ε����� �ʴµ�, �̴� ���������� �ش� ��� �Լ�, ��� ������ ����� �� �ְ� �մϴ�. ( �ڼ��� ������ ���� �ٷ�ڽ��ϴ�. )

<details>
<summary>04���� ���� ��� ����</summary>
<div markdown="1">

week04.hpp

```cpp
#include <iostream>
#include <string>

namespace week04
{
	class Human
	{
		// ��� ���� ( m_name, m_hp, m_power )
        private:
        std::string m_name = "John Doe" ;
        int m_hp = 100 ;
        int m_power = 10 ;
        
		// ��� �Լ� ( Attack, GetInfo )
        public:
        void Attack( Human& defender ) ;
        static void GetInfo( Human t_human ) ;

		// ������ ( �Ű����� ���� ����Ʈ ������, �Ű����� m_name, m_hp, m_power�� ������ )
        Human() ;
        Human( std::string t_name, int t_hp,int t_power ) ;
	} ;
}
```

week04_main.cpp

```cpp
#include "week04.hpp"

/////// Human Ŭ������ ������ ���� ( �Ű������� ���� ������, �Ű����� m_name, m_hp, m_power�� ������)

week04::Human::Human( ){};

week04::Human::Human( std::string t_name, int t_hp, int t_power )
{  
    m_name = t_name;
    m_hp = t_hp;
    m_power = t_power;
}
////////////////

/////// ��� �Լ� Attack, GetInfo ����
void week04::Human::Attack( Human& defender )
{
	std::cout << "������ " << this->m_power << "��ŭ�� ���� ���� !!!!" << std::endl;
	std::cout << "������ : " << this->m_name << " => ����� : " << defender.m_name << std::endl;
	std::cout << std::endl ;

	defender.m_hp -= this->m_power;
}

void week04::Human::GetInfo( Human t_human )
{
    std::cout << t_human.m_name << "�� ����" << std::endl;
    std::cout << "ü�� : " << t_human.m_hp << ", �Ŀ� : "<< t_human.m_power << std::endl ;
	std::cout << std::endl ;	
}

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
```


</div>
</details>

---

# ���

C++���� ����� �� Ŭ������ �ٸ� Ŭ������ ��� ����( �Ӽ� )�� ��� �Լ�( �޼��� )�� �����޴� ��ü ���� ���α׷����� �ٽ� ����Դϴ�.

2���� �� �����ؼ� ���� �� ���,

1. �θ� Ŭ���� ( Parent class, Base class, Super class ) 
- ��� ������ ��� �Լ��� �����ִ� Ŭ���� �Դϴ�.
  
2. �ڽ� Ŭ���� ( Child Class, Derived class, Sub class )
- �θ� Ŭ�����κ��� ����� �޴� Ŭ���� �Դϴ�.

C++���� Ŭ���� ���� ����� ������ ���� ǥ���˴ϴ�.

```cpp
class ParentClass 
{
    // ParentClass�� �����
};

class ChildClass : public ParentClass 
{
    // ChildClass �����
};
```
## ����� ���� ������

�� Ŭ������ ������� ���� �����ڸ� ����� �� �ֵ�, ��ӿ��� ���� �����ڸ� Ȱ���� 3���� ������ �ֽ��ϴ�.

1. ����( Public ) ���
   + ���� �Ϲ����� ������ ����Դϴ�. ���⼭ �ڽ� Ŭ������ �θ� Ŭ������ **��� `Public` �� `protect` ����� �����޽��ϴ�.**

2. ��ȣ( Protected ) ���
   + ��ȣ ��ӿ��� �ڽ� Ŭ������ �θ� Ŭ������ ��� `Public` �� `Protected` ����� ����������, �̵� ��δ� **�ڽ� Ŭ�������� `protected` ����� �˴ϴ�.**

3. �����( Private ) ���
   + ����� ����� �ڽ� Ŭ������ �θ� Ŭ������ ��� `Public` �� `protect` ����� ����������, �̵� ��δ� **�ڽ� Ŭ�������� `private` ����� �˴ϴ�.**

**�θ� Ŭ������ `private` ������� �ڽ� Ŭ�������� �������� ������ ���ѵ˴ϴ�.** �θ� Ŭ������ `public` �� `protected` ��� �Լ��� ���� ���������� �����ϰų� ������ �� �ֽ��ϴ�. 

<p align="center">
<img src = "../images/jub.png" width="80%" height="80%" title="robot"></img>
<br>���� ������ 3����
</p>

�ڵ�� ���캸�ڽ��ϴ�.


### �ǽ�
��� ������

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
public:
    Person(std::string n) : name(n) {}
    std::string getName() {
        return name;
    }
};

////Student, Teacher Ŭ���� ����

////

int main() {
    Student student("John");
    Teacher teacher("Anna");

    student.study();
    teacher.teach();

    return 0;
}

```

`Person`�̶�� �θ� Ŭ������ �����, �� Ŭ������ `name`�̶� `private` ��� ������ `getName`�̶�� `public` ��� �Լ��� �������ֽ��ϴ�.    
`getName` �Լ��� name�� ��ȯ�մϴ�.

`Person` Ŭ������ `public` ����ϴ� `Student`�� `Teacher`�� �ڽ� Ŭ������ ������ּ���. 

`Student` Ŭ������ `study`��� �Լ���, `Teacher` Ŭ������ `teach`��� �Լ��� �����ϴ�.

`study` �Լ��� "?? is studying"��, `teach` �Լ��� "??is teaching"�� ����մϴ�. (??�� ����� �̸�)



��ӿ��� ������ ����

```cpp
#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }
    Base(int x) {
        std::cout << "Base constructor with value " << x << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() : Base(10) { // �θ� Ŭ������ �����ڸ� ��������� ȣ��
        std::cout << "Derived constructor" << std::endl;
    }
};

int main() {
    Derived d;

    return 0;
}
```





����� �ѱ� �����°� ��ġ�� �� ?

���� ��ɾ �����Ͽ� locale�� �����մϴ�: 
sudo locale-gen ko_KR.UTF-8

�� ��, ���� ��ɾ �����Ͽ� locale ������ ������Ʈ�մϴ�: sudo update-locale LANG=ko_KR.UTF-8