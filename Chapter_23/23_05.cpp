#include <iostream> // ������ 23.5
#include <cstring>
#include <stdexcept>

template <typename T> class Sort_Arr
{
private:
	int size;
	T *p;
public:
	Sort_Arr();
	Sort_Arr(int s);
	~Sort_Arr();
	Sort_Arr(const Sort_Arr& s);
	Sort_Arr& operator=(const Sort_Arr& t);
	T& operator[](int pos) const;
	void bubble_sort();
	void show() const;
};

template <typename T> Sort_Arr<T>::Sort_Arr()
{
	p = nullptr;
}

template <typename T> Sort_Arr<T>::Sort_Arr(int s)
{
	int i;

	size = s;
	p = new T[size];
	for(i = 0; i < size; i++)
	{
		std::cout << "Enter number: ";
		std::cin >> p[i];
	}
}

template <typename T> Sort_Arr<T>::~Sort_Arr()
{
	delete[] p;
}

template <typename T> Sort_Arr<T>& Sort_Arr<T>::operator=(const Sort_Arr<T>& t) /* ����������� ��� ������� =. �� ������ ��� ����� �� ��� ������ sa_3 = sa_2 = sa_1; */
{
	if(this == &t) /* ������� ������������ ��� �� ������ ���������, ��� �� ������������ ��������� ��� ����������. */
		return *this;
	delete[] p;
	size = t.size;
	p = new T[size];
	memcpy(p, t.p, size*sizeof(T)); /* ��������� size ���������. �� ������� ��� ���� ��������� ��������� ��� ��� ���� ��� ��� ����� sizeof(T). */
	return *this;
}

template <typename T> Sort_Arr<T>::Sort_Arr(const Sort_Arr<T>& t) /* � ������������� ���������� �� ������ �� ��� ������ sa_5(sa_4); �� size ��� p ����� �� ����� ��� sa_5, ��� �� t ���������� ��� sa_4. */
{
	size = t.size;
	p = new T[size];
	memcpy(p, t.p, size*sizeof(T));
}

template <typename T> void Sort_Arr<T>::show() const  
{
	for(int i = 0; i < size; i++)
		std::cout << p[i] << '\n';
}

template <typename T> T& Sort_Arr<T>::operator[](int pos) const  
{
	if(pos < 0 || pos > size)
		throw std::out_of_range("Error: out_of_range\n");
	return p[pos];
}

template <typename T> void Sort_Arr<T>::bubble_sort()
{
	bool reorder;
	int i, j;
	T tmp;

	for(i = 1; i < size; i++)
	{
		reorder = 0;
		for(j = size-1; j >= i; j--)
		{
			if(p[j] < p[j-1])
			{
				// ������������ �����. 
				tmp = p[j];
				p[j] = p[j-1];
				p[j-1] = tmp;
				reorder = 1;
			}
		}
		if(reorder == 0)
			return;
	}
}

