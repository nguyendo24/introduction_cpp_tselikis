#include <iostream> // ’σκηση 16.6
#include <vector>
#include <string>
using std::vector;
using std::string;

const int SIZE = 5;

template <typename T> T find(T a, T b, T c);
template <typename T> void find(const T arr[], T& min, T& max);
template <typename T> T* find(T* first, T* last, const T& val);

int main()
{
	int i = 3, j = 1, k = 2;
	double m, n, a[SIZE] = {5.1, 1.1, 2.1, 3.1, 4.1};
	string *p, *last, str = "Test";
	vector<string> vec{"Alpha", "Beta", "Gamma", "Delta"};

	std::cout << "Sum:" << find(i, j, k) << '\n';

	find(a, m, n);
	std::cout << "Min:" << m << " Max:" << n << '\n';
	
	last = &vec[0] + vec.size();
	p = find(&vec[0], last, str);
	if(p == last)
		std::cout << "The string is not found\n";
	else
		std::cout << "The string " << *p << " is found\n";
	return 0;
}

template <typename T> T find(T a, T b, T c)
{
	T max;

	max = a+b;
	if(max < a+c)
		max = a+c;
	if(max < b+c)
		max = b+c;
	return max;
}

template <typename T> void find(const T arr[], T& min, T& max)
{
	int i;

	min = max = arr[0];
	for(i = 1; i < SIZE; i++)
	{
		if(arr[i] < min)
			min = arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
}

template <typename T> T* find(T* first, T* last, const T& val)
{
	T* ptr;

	for(ptr = first; ptr < last; ptr++)
		if(*ptr == val)
			return ptr;
	return last;
}

