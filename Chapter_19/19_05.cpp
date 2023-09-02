#include <iostream> // ������ 19.5
#include <cstring>
using std::cout;
using std::ostream;

class T
{
private:
	double *arr;
public:
	int size;
	explicit T(int n);
	~T();
	T(const T& t);
	T& operator=(const T& t);
	friend ostream& operator<<(ostream& out, const T& t);
};

T::T(int n)
{
	int i;

	size = n;
	arr = new double[size];
	for(i = 0; i < size; i++) // ����, ������������ ������� �����. 
		arr[i] = i+1; 
}

T::~T()
{
	delete[] arr;
}

T::T(const T& t) /* � ������������� ���������� �� ������ �� ��� ������ � t3 = t1; �� size ��� arr ����� �� ����� ��� t3, ��� �� t ���������� ��� t1. */ 
{
	size = t.size;
	arr = new double[size];
	memcpy(arr, t.arr, size * sizeof(double));
}

T& T::operator=(const T& t) /* ����������� ��� ������� =. �� ������ �� ��� ������� t2 = t1; ��� t2 = t2; �� size ��� arr ����� �� ����� ��� t2, ��� �� t ���������� ���� ����� ��������. ��� �� ������������ ����������, � ����� ���������� ��� ���������� �� �������� �� ����� ��� void, ���� ������� ��� ������� ��� ����������. */ 
{
	if(this == &t) /* ��������� �� ������������ ��� ���� �� �����������, ���� �� ��� ������ t2 = t2; */ 
		return *this;
	delete[] arr; // ������������� ��� ����� �����. 
	size = t.size;
	arr = new double[size];
	memcpy(arr, t.arr, size * sizeof(double));
	return *this;
}

ostream& operator<<(ostream& out, const T& t) /* ����������� ��� ������� << �� �� ����� ������� ����������. */ 
{
	for(int i = 0; i < t.size; i++) 
		out << t.arr[i] << ' '; 
	out << "\n\n";
	return out;
}

