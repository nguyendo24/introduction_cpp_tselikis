#include <iostream> // ’σκηση 16.5
#include <vector>
using std::vector;
using std::cout;

template <typename T> double avg(const vector<T>& v);
template <typename T1, typename T2> void avg(T1 t1, T2 t2, double *p);

int main()
{
	double i;
	vector<int> v = {1, 2, 4};

	avg(1, 2, &i);
	std::cout << "Avg_1:" << avg(v) << '\n';
	std::cout << "Avg_2:" << i << '\n';
	return 0;
}

template <typename T> double avg(const vector<T>& v)
{
	T sum;
	int i, size;

	size = v.size();
	sum = 0;
	for(i = 0; i < size; i++)
		sum += v[i];
	return (double)sum/size;
}

template <typename T1, typename T2> void avg(T1 t1, T2 t2, double *p)
{
	*p = (t1+t2)/2.0;
}

