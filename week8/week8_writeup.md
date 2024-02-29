<!-- ---
marp: true
--- -->


# C++_Basic_Week_08

_�ۼ��� : Ȳ����_

---

## ���� ����

---


```cpp
/////// ( 1 ) ///////
week07::Human::Human( int t_age, std::string t_name ) : m_age( t_age ), m_name( t_name ) {} ;
/////////////////////
```

---

```cpp

/////// ( 2 ) ///////
week07::Human week07::Human::operator+( Human& t_human )
{
	std::cout << "\n========== + ������ ȣ�� ==========" << std::endl ;	
	std::cout << "Name : " << this->m_name << " or " << t_human.m_name << std::endl ;	
	std::cout << "Age : " << this->m_age << " + " << t_human.m_age << std::endl ;	

	int tempAge ;
	std::string tempName ;

	tempAge = this->m_age + t_human.m_age ;

	tempName = ( tolower( this->m_name[0] ) < tolower( t_human.m_name[0]) ) ? this->m_name : t_human.m_name ; 

	return Human( tempAge , tempName ) ;
} ;
/////////////////////

````
---

```cpp

/////// ( 3 ) ///////
std::ostream& week07::operator<<( std::ostream& os , const week07::Human& t_human )
{
	os << "Name : " << t_human.m_name << ", Age : " << t_human.m_age ;
	return os ;
} ;
/////////////////////

```

---

```cpp

/////// ( 4 ) ///////
std::istream& week07::operator>>( std::istream& is , week07::Human& t_human )
{
	std::cout << "�̸�, ���� �Է� ( ���� ���� ) " << std::endl ;	
	is >> t_human.m_name >> t_human.m_age ;
	return is ;
} ;
/////////////////////
```


---

### ���ĺ� �ҹ��� �˻�

```cpp
tempName = ( tolower( this->m_name[0] ) < tolower( t_human.m_name[0]) ) ? this->m_name : t_human.m_name ; 
```
<!-- �� std::ostream&���� week07�� ���̸� ������ ���µ� operator���� week07::�� �ٿ��� ������ ���� �ʴ���...?

�ϴ� operator�Լ��� week07 ���ӽ����̽����� �������� HumanŬ�������� ������ �ʱ� �����ΰ� ��� �����ϴ� ��

//����: ������ �����ε��� ��ü���� ���μ����� �� �𸣰ڴ�(Ư�� ����� ������ �����ε����� �� �Ű������� ������ �Ǿ�� �ϴ��� �𸣰ڴ�)
//���ĺ� ������ ���� �̸��� ��ҹ��� �������� �ʰ� ���ϰ� �ϱ� ���ؼ� �ҹ��ڷ� �� �ٲ㼭 ���ϴ� ����� �����ߴµ�
//�ٸ� ����� ������ �ñ��ϴ�. -->

---

### >>, << ������ �����ε�

---

#### 1. ������� �Ǵ� ����

`��Ʈ��`�� �Ϸ��� �����ͳ� �������� �帧�� ����   

+ �Է�
  - Ű���� �Է� -> �Է� ��Ʈ�� -> ���α׷�
  
![input stream](../images/input_stream.png)

---

+ ���
  - ���α׷� -> ��� ��Ʈ�� -> ���

![output stream](../images/output_stream.png)

---

#### 2. ���� std::cout, std::cin�� �۵� ���

ǥ�� ��� ��Ʈ���� `std::cout`**��ü** �� ��³����� ���� �Ǹ� ���.

ǥ�� �Է��� `std::cin`**��ü** �� �Է� ������ ���޵Ǹ�, ���α׷��� ����.

<!-- [cout ��� ���� ����](https://repilria.tistory.com/243) -->

---

#### 3. �����ε��ϸ� ��� �۵��ϳ� ?
   
<br>

������ �����ε��� 2���� ����

1. Ŭ������ ����Լ��� �����ε�
   ```cpp
    a.operator+(a);
   ```
2. �ܺ��Լ��� ``friend``�������� �����ε�
   ```cpp
    operator+(a, a);
   ```

---

```cpp
std::ostream& week07::operator<<( std::ostream& os , const week07::Human& t_human )
{
	os << "Name : " << t_human.m_name << ", Age : " << t_human.m_age ;
	return os ;
} ;
```
���� ���� �����ε� �� �Լ��� `std::cout << C ;`�� ȣ���ϴ� ����,

```cpp
operator<<( std::cout , C )
```
�� ���� �Ű������� �Լ� ȣ���� �Ͱ� �����մϴ�.   

---

**���������**
�ڱ� �ڽ��� �������� �ʴ� ���� �����ڵ�, _( +, -, *, / )_ ���� ��� �ܺ� �Լ��� �����ϴ� ���� ��Ģ   

<br>

�ݴ�� �ڱ� �ڽ��� �����ϴ� ���� �����ڵ�, *( +=, -= )* ���� ��� ��� �Լ��� �����ϴ� ���� ��Ģ

---

### ���ӽ����̽� 

- `std::ostream&`�� `operator`�� ����

```cpp
std::ostream& week07::operator<<( std::ostream& os , const week07::Human& t_human )
{
	os << "Name : " << t_human.m_name << ", Age : " << t_human.m_age ;
	return os ;
} ;
```

---

## ���ø�

```cpp
class Vector {
  std::string* data;
  int capacity;
  int length;

 public:
  // ������
  Vector(int n = 1) : data(new std::string[n]), capacity(n), length(0) {}

  // �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
  void push_back(std::string s) {
    if (capacity <= length) {
      std::string* temp = new std::string[capacity * 2];
      for (int i = 0; i < length; i++) {
        temp[i] = data[i];
      }

      delete[] data;
      data = temp;
      capacity *= 2;
    }

    data[length] = s;
    length++;
  }
```

---

```cpp
  // ������ ��ġ�� ���ҿ� �����Ѵ�.
  std::string operator[](int i) { return data[i]; }

  // x ��° ��ġ�� ���Ҹ� �����Ѵ�.
  void remove(int x) {
    for (int i = x + 1; i < length; i++) {
      data[i - 1] = data[i];
    }
    length--;
  }

  // ���� ������ ũ�⸦ ���Ѵ�.
  int size() { return length; }

  ~Vector() {
    if (data) {
      delete[] data;
    }
  }
};
```

���� �����ð��� �ٷ� `vector` Ŭ������ �ڵ� �Դϴ�.   

---

```cpp
class Vector {
  char* data;
  int capacity;
  int length;

 public:
  // ������
  Vector(int n = 1) : data(new char[n]), capacity(n), length(0) {}

  // �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
  void push_back(char s) {
    if (capacity <= length) {
      char* temp = new char[capacity * 2];
      for (int i = 0; i < length; i++) {
        temp[i] = data[i];
      }
      delete[] data;
      data = temp;
      capacity *= 2;
    }

    data[length] = s;
    length++;
  }
```

---

```cpp
class Vector {
  T* data;
  int capacity;
  int length;

 public:
  // ������
  Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

  // �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
  void push_back(T s) {
    if (capacity <= length) {
      T* temp = new T[capacity * 2];
      for (int i = 0; i < length; i++) {
        temp[i] = data[i];
      }
      delete[] data;
      data = temp;
      capacity *= 2;
    }

    data[length] = s;
    length++;
  }
```

---

```cpp
  // ������ ��ġ�� ���ҿ� �����Ѵ�.
  T operator[](int i) { return data[i]; }

  // x ��° ��ġ�� ���Ҹ� �����Ѵ�.
  void remove(int x) {
    for (int i = x + 1; i < length; i++) {
      data[i - 1] = data[i];
    }
    length--;
  }

  // ���� ������ ũ�⸦ ���Ѵ�.
  int size() { return length; }

  ~Vector() {
    if (data) {
      delete[] data;
    }
  }
};

```

---


**���ø�** �� �Լ��� Ŭ������ ���������� *�ٽ� �������� �ʾƵ�, �پ��� �ڷ���*���� ����� �� �ֵ��� �ϰ� ����� ���� **Ʋ** �Դϴ�.   

ũ�� 2���� ������ �ֽ��ϴ�.   

1. Ŭ���� ���ø�
2. �Լ� ���ø�


<br>

---

### �Լ� ���ø�

---

�ڵ�� ���캸�ڽ��ϴ�.   

```cpp
int add( int a, int b )
{
    return a + b ;
}

double add( double a, double b )
{
    return a + b ;
}
```

�� `add`�� �Ű������� ���� �� ���ڸ� ���ؼ� ��ȯ�ϴ� **������ ������ �ϴ�** �Լ��Դϴ�.   
������, ��ȯ���� �ڷ����� �Ű������� �ڷ����� �ٸ��� ������ `�Լ� �����ε�`���� 2�� �����߽��ϴ�.   

---

������ �Լ� ���ø��� ����ϸ�, �̷��� �ۼ��� �� �ֽ��ϴ�.   

```cpp
template <typename MyTemplate>
MyTemplate add( MyTemplate a, MyTemplate b )
{
    return a + b ;
}
```

---

### �ǽ��غ���

�Ű������� Ÿ���� ����ϴ� �Լ� `printInfo` �Լ��� �����غ��ô�.   
������ Ÿ���� `typeid( ���� ).name()`�� ���� ����� �� �ֽ��ϴ�.   
```cpp
std::cout << typeid( ���� ).name() << std::endl ;
```

<br>

![template02 ��� ���](../images/template02_output.png)
*��� ���*

---

## Ŭ���� ���ø�



Ŭ�������� �̷� ���ø��� �� ȿ�������� ����� �� �ֽ��ϴ�.   

```cpp
template<typename T>
class Box {
    T content;

public:
    Box(const T& content) : content(content) {}
    const T& get() const { return content; }
};
```

---

## ���ø� Ư��ȭ



���ø����� �پ��� �ڷ����� �ٷ�� ������,
Ư�� �ڷ������� �ٸ��� �����ϰ� �����ϱ� ���ؼ� `���ø� Ư��ȭ`��� ������ �����ؾ��մϴ�.

```cpp
template<>
class Box<int> {
    int content;

public:
    Box(const int& content) : content(content) {}

    const int& get() const { return content; }

    void countUp()
    {
        for( int i = 0; i < content; i++ ){ std::cout << i << std::endl ; }
    }

};
```

[���ø� Ư��ȭ](https://learn.microsoft.com/ko-kr/cpp/cpp/template-specialization-cpp?view=msvc-170)

---

## ��ε帮�� ���� ��



1. �������� ��~~~ û ~~~ ����
2. Ʋ���͵�..?
3. ���� ���� ��Դ´�...

<br>

![ȭ����](../images/park_thumbs.jpeg)

---

+ [C++ ����](https://learn.microsoft.com/ko-kr/cpp/cpp/?view=msvc-170)

+ [����� �ڵ� C++](https://modoocode.com/category/C++)