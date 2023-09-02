#include <iostream> // ������ 19.3
#include <cstring>
#include <cstdlib> // ��� ��� exit().
using std::cout;
using std::ostream;

class T
{
private:
	char *s;
public:
	explicit T(const char str[]);
	T() {s = nullptr;}
	~T();
	T(const T& t);
	T operator+(const T& t);
	T& operator=(const T& t);
	char& operator[](int i);
};

T::T(const char str[])
{
	s = new char[strlen(str)+1];
	strcpy(s, str);
}

T::~T()
{
	delete[] s;
}

T T::operator+(const T& t) /* ����������� ��� ������� +. �� ������ �� ��� ������ t1+t2; �� s ����� �� ����� ��� t1, ��� �� t ���������� ��� t2. */
{
	T tmp; 

	tmp.s = new char[strlen(s)+strlen(t.s)+1];
	tmp.s[0] = '\0';
	strcpy(tmp.s, s);
	strcat(tmp.s, t.s);
	return tmp;
}

T& T::operator=(const T& t) /* ����������� ��� ������� =. ����� �� ������ �� ��� ������ t3 = t1+t2; �� s ����� �� ����� ��� t3, ��� �� t ���������� ��� ����������� ��� ���������� � ��������� operator+. */
{
	if(this == &t) /* ������� ������������ ��� �� ������ ���������, ��� �� ������������ ��������� ��� ����������. */
		return *this;

	delete[] s;
	s = new char[strlen(t.s)+1];
	strcpy(s, t.s);
	return *this;
}

T::T(const T& t) /* � ������������� ���������� �� ������ �� ��� ������ � t5(t4); �� s ����� �� ����� ��� t5, ��� �� t ���������� ��� t4. */ 
{
	s = new char[strlen(t.s)+1];
	strcpy(s, t.s);
}

char& T::operator[](int i) 
{
	if(i < 0 || i >= strlen(s)) /* ������� ����� ��� �� ������ ���������, ��� �� ������������ ��������� ��� ����������. */
		exit(EXIT_FAILURE); 
	return s[i];
}

