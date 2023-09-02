#include <iostream> // ’σκηση 19.2
#include <string>
using std::cout;
using std::string;

class T
{
private:
	string str;
	int key;
public:
	void show() const {cout << str << ' ' << key;} 
	T() {}
	T(const T& t);
	int& operator[](string s);
};

T::T(const T& t) 
{
	cout << "Yes\n";
	str = t.str;
	key = t.key;
}

int& T::operator[](string s) 
{
	str = s;
	return key;
}

