<!-- ---
marp: true
--- -->


# C++_Basic_Week_07

_�ۼ��� : Ȳ����_

---


## ���� ����


---

### ���� �Ҵ�

C++���� ���� �Ҵ��� ���ؼ�, `new`�� `delete`�� ����� �� �ֽ��ϴ�.   


```cpp
int* p = new int;
```

`new` �޸𸮸� �Ҵ��ϰ�, **�Ҵ�� �޸��� �ּ�** �� ��ȯ�մϴ�. 

---

```cpp
delete p;
```

`delete`�� �̿��Ͽ� `new` �� �Ҵ�� �޸𸮸� ���� �� �� �ֽ��ϴ�.   

---

### ���캾�ô�

```cpp
class IntArray {
private:
    int* arr;
    int size;

public:
    IntArray( int size ) : size( size ) 
    {
        arr = new int[ size ] ; 
    }

    ~IntArray() 
    {
        delete[] arr ; 
    }
};
```

[new, delete](https://learn.microsoft.com/ko-kr/cpp/cpp/new-and-delete-operators?view=msvc-170)

---

### vector

`vector`�� STL�� �����̳� Ŭ������, **ũ�Ⱑ �������� �迭** �Դϴ�!   
    
��Ÿ�� ���߿� ����� �߰��� ������ �����ϸ�, �ڵ����� �޸𸮸� �������ݴϴ�.    

---

<p align="center">
<img src = "../images/vector.png" width="80%" height="80%" title="robot"></img>
<br>������ ����
</p>

<!-- ![vetor�� ����](../images/vector.png) -->

---

1. ��Ÿ�� ���� ��Ҹ� **�߰��ϰų� ����** �� �� �ֽ��ϴ�.
2. �迭ó�� **�ε����� ����Ͽ� ��ҿ� ������ ����** �� �� �ֽ��ϴ�.
3. ���������� �����͸� **���ӵ� �޸� ����** �� �����մϴ�. 
4. ��Ҹ� �߰��ϰų� ������ �� **�ڵ����� �޸𸮸� �Ҵ��ϰų� ����** �մϴ�.
   
---

<br>

```cpp
#include <vector>

// ���� ����
std::vector<int> vec; // �� ����
std::vector<int> vec2(5); // ũ�Ⱑ 5�̰� ��� ��Ұ� 0�� ����
std::vector<int> vec3(5, 1); // ũ�Ⱑ 5�̰� ��� ��Ұ� 1�� ����

// ��� �߰�
vec.push_back(1); // ���� ���� ��� �߰�

// ��� ����
int first = vec[0]; // �ε����� ����
int first2 = vec.at(0); // at �Լ��� ����
int last = vec.back(); // ������ ��� ����

// ��� ����
vec.pop_back(); // ���� ���� ��� ����

// ũ�� �� �뷮
int size = vec.size(); // ���� ũ�� ��ȯ
int capacity = vec.capacity(); // ���� �뷮 ��ȯ

```

---


���ʹ� ���� �迭�̱� ������ ũ�Ⱑ ������������, ��Ҹ� �߰��ϸ鼭 ������ �뷮( capacity )�� �ʰ��ϸ�, ���ʹ� �ڵ����� �� ū �޸𸮸� �Ҵ��ϰ� ��� ��Ҹ� �� �޸𸮷� �����մϴ�.    


```cpp
std::vector<int> vec; 
vec.reserve(1000);
```

���� ���� `reserve` �� �̿��Ͽ� �̸� ������ ũ�⸦ �������� �� �ֽ��ϴ�.

[���� ���� ��α�](https://dense.tistory.com/entry/cpp-stl-vector)   
[���� ���� ���Ĺ���](https://learn.microsoft.com/ko-kr/cpp/standard-library/vector-class?view=msvc-170)   

---

## �����ε��� �������̵�

### �����ε�

**�Լ� �ߺ� ����**   
���� �̸��� �Լ��� �Ű������� �ٸ��� ����Ͽ� �Ű������� ���� �ٸ� �Լ��� ����Ǵ� ��.   

---

```cpp
void add( int a, int b )
{
    std::cout << "�� ������ �� : " << a + b << std::endl ;
}

void add( double a, double b )
{
    std::cout << "�� �Ǽ��� �� : " << a + b << std::endl ;
}
```
---

- ��� �Լ�( �޼ҵ� ) �̸��� ���ƾ� �մϴ�.
- ��ȯ���� ���Ƶ� �ǰ� �޶� �˴ϴ�.
- �Ű������� ������ �޶���Ѵ�.
- �Ű������� ������ ������ ���, �ڷ����� �޶�� �մϴ�.

---

### �������̵�

**�Լ� ������**   
��� �޾����� �θ� Ŭ������ �Լ��� ������� �ʰ�, �ٸ� ����� �����Ҷ� �Լ��� �ڽ� Ŭ������ ���� �̸�, �Ű������� �������ؼ� ����ϴ� ��.


---

```cpp
class Parent
{
    public:
    void add( int a )
    {
        std::cout << a + a << std::endl ;
    }
}

class Child : public Parent
{
    public:
    void add( int a )
    {
        std::cout << a + a + a << std::endl ;
    }
}

int main()
{
    Parent A ;
    Child B ;

    A.add( 100 ) ;
    B.add( 100 ) ;
}
```

---

- �������̵� �ϰ��� �ϴ� ����Լ�( �޼ҵ� )�� ���� Ŭ������ �����ؾ��մϴ�.
- ����Լ�( �޼ҵ� ) �̸��� ���ƾ� �մϴ�.
- ����Լ�( �޼ҵ� )�� �Ű����� ����, �ڷ����� �����ؾ� �մϴ�.
- ����Լ�( �޼ҵ� )�� ��ȯ���� �ڷ����� ���ƾ� �մϴ�.
- ���� �޼ҵ�� �����ϰų�, ���ο� ������ �߰��Ǿ�� �մϴ�.

---

## ������ �����ε�

�׷� ������ �����ε��� �����?

---

```cpp
class Human
{
    public:
    std::string m_name ;
    int m_age ;

    Human( std::string t_name, int t_age ) : m_name( t_name ), m_age( t_age ) {} 

    void ShowInfo()
    {
        std::cout << "name : " << this->m_name << ", age : " << this->m_age ;
    }
    Human operator+( Human &t_human )
    {
        std::cout << "Add two humans" << std::endl ;

        return Human( this->m_name + t_human.m_name , this->m_age + t_human.m_age ) ;
    }
}
```

`+` �����ڸ� �����ε��� `Human` ��ü ������ `+` ������ �����ϰ� �� �� �ֽ��ϴ�.   

---

## �ǽ��غ���

```cpp
class MyClass
{
	private:
	int m_int ;
	double m_double ;

	public:
	MyClass( int t_int, double t_double ) : m_int( t_int ), m_double( t_double ) {}
	void PrintInfo() 
	{
		std::cout << "\n\n=== Myclass PrintInfo() call ===" << std::endl ;
		std::cout << "int : " << this->m_int << std::endl ;
		std::cout << "double : " << this->m_double << std::endl ;
	}
	MyClass operator+( MyClass& ) ;
} ;
```
�Ʒ��� ��°���� �������� `MyClass`�� `+`�����ڸ� �����ε��ϴ� �ڵ带 �ۼ����ּ���.

---


<!-- ![��� ���](../images/operator02.png) -->
<p align="center">
<img src = "../images/operator02.png" width="80%" height="80%" title="friends"></img>
<br>��°��
</p>

---

## auto, friend Ű����

### auto Ű����

C++���� `auto` Ű����� �����Ϸ��� �ڵ����� ������ Ÿ���� �߷��ϵ��� �մϴ�.   

```cpp
auto i = 0; // i�� int Ÿ���� �˴ϴ�.
int i = 0; // ��������� int Ÿ���� �����߽��ϴ�.
```

---

��� ���ô� ������ �����ϴ�.

```cpp
// ���� �ݺ�
for(int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << ' ';
}
for(auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << ' ';
}
for(auto& elem : vec) {
    std::cout << elem << ' ';
}
```

---

### friend Ű���� 

`friend` Ű����� **Ŭ���� �Ǵ� �Լ��� ���� ���� ����** �� �ο��ϴ� �� ���˴ϴ�.

<!-- <p align="center">
<img src = "../images/friends.jpg" width="80%" height="80%" title="friends"></img>
<br>����մϴ�
</p> -->

```cpp
class MyClass {
private:
    int secret = 42 ;

public:
    friend void revealSecret( MyClass& mc ) ;
};

void revealSecret( MyClass& mc ) {
    std::cout << "The secret is " << mc.secret << std::endl ; // friend �Լ��� private ����� ���� ����
}

int main() {
    MyClass mc ;
    revealSecret( mc ) ; 
    return 0 ;
}
```

`MyClass`�� `friends`�� ���� �� `void revealSecret( MyClass& mc )`�Լ��� `MyClass`�� `private`, `protected`�� ������ �� �ֽ��ϴ�.

---
### auto Ű���� ����

`auto` Ű���� ���� �帱�� ��Ÿ�ӿ� �ڷ����� ������ �� �ִٰ� ����帰 �� ������ **������ �߸��� �����Դϴ�...**   
<br>

`auto`�� ������ �������� �߷� �� �ڷ������� **ġȯ** �ǹǷ� ��Ÿ�� �������� ����Ǵ°� �ƴմϴ�.  

```cpp
auto a = 1 ;
```
�� �ڵ尡 �����Ϸ��� ����
```cpp
int a = 1 ;
```
�� ����Ǵ� �� �Դϴ�.

���� �����ֽ�

```cpp
auto a = 1 ;
a = "string" ;
```
������ �Ʒ� �ڵ�� ������ �ڵ�� ��޵ǹǷ�,
```cpp
int a = 1 ;
a = "string" ;
```
�� Ÿ�� ��ȯ ������ �߻��ϰ� �˴ϴ�. ������ �غ�� ȥ���� ��� �˼��մϴ� ?

## ����

�̹� ������ �������� `������ �����ε�`�� �غ��ô�.   

### ( 1 ) ������ ����

������ ����� �̷��� ���ڿ��� �Ű������� �޾� `Human` ��ü�� �����ϴ� �����ڸ� �������ּ���.   

### ( 2 ) + ������ �����ε�

Human ��ü���� + ������ �ϸ� ������ ���� �����մϴ�.    
- `age` ������ **�ܼ� ���� ���ϱ� ����**�� �մϴ�.  
- `name`�� ù�ڸ� ���Ͽ� **���ĺ� ������ ����** �̸��� ã���ϴ�. *( adam, jack �񱳽� adam , ��ҹ��� ���� x )*    
   
���� �� ��ü�� `m_age`�� ���� ��, ���ĺ� ������ ���� �̸� `t_name`�� ���� ��ü�� ��ȯ�մϴ�.

�� `age`, `name`

### ( 3 ) << ������ �����ε�

`<<` �����ڸ� �����ε��Ͽ� �Ʒ� �ڵ常���� `Human` ��ü���� `m_age`, `m_name`���� ����� �� �ְ� �������ּ���.

```cpp
std::cout << a << std::endl ;
```

### ( 4 ) >> ������ �����ε�

`>>` �����ڸ� �����ε��Ͽ� �Ʒ� �ڵ常���� `Human` ��ü�� ���� `m_age`, `m_name`�� ���� �ʱ�ȭ�� �� �ְ� �������ּ���.   

```cpp
std::cin >> a ;
```

�Ʒ� ��� ����� �������� ���� ���ּ���. `main` �Լ��� �������� �����ŵ� �˴ϴ�. 

<p align="center">
<img src = "../images/assignment07.png" width="80%" height="80%" title="assignment07"></img>
<br>��� ���
</p>