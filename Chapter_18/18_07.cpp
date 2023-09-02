#include <iostream> // ������ 18.7
#include <vector>
using namespace std;

template <typename T> T sum(const vector<T>& v)
{
	T t = {0}; /* ���� ������ �������� ������� �����. ��� ����������, �� �� T ����� int, �� t �� ����� 0. �� �� T ����� � ����� Product � ������������� �� ����� �� ����� ��� t ��� �� 0. � ������ ���� 0 ����� ���������� ���� �� ����������� ����� �� ��������. */
	for(int i = 0; i < v.size(); i++)
		t = t + v[i];
	return t;
}

class Product
{
	private:
		int code;
	public:
		float prc;
		Product(int c = 0, float p = 0);
		Product& operator+(const Product& p);
};

Product::Product(int c, float p)
{
	code = c;
	prc = p;
}

Product& Product::operator+(const Product& p)
{
	prc += p.prc;
	return *this;  
}

