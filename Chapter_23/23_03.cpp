#include <iostream> // ’σκηση 23.3
using std::cout;
using std::ostream;

template <typename T> class Circle
{
private:
	T rad;
public:
	Circle<T>(T r = 0) {rad = r;}
	void operator+(T i) {rad += i;}
	Circle<T> operator+(const Circle<T>& c) const;
	template <typename V> friend ostream& operator<<(ostream& out, const Circle<V>& c);
};

template <typename T> Circle<T> Circle<T>::operator+(const Circle<T>& c) const
{
	Circle<T> tmp;
	tmp.rad = rad + c.rad;
	return tmp;
}

template <typename V> ostream& operator<<(ostream& out, const Circle<V>& c)
{
	out << c.rad << '\n';
	return out;
}

