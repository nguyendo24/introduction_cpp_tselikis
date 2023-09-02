#include <iostream> // ’σκηση 23.4
#include <string>
#include <vector>
using namespace std;

template <typename T1, typename T2> class Map_Key
{
private:
	T1 key;
	T2 val;
public:
	Map_Key() {};
	Map_Key(const T1& k, const T2& v) : key(k), val(v) {};
	bool check(const T1& k) const {return (key == k) ? true : false;}
	T2 get() const {return val;}
	Map_Key<T1, T2> operator+(const Map_Key& mk) const;
};
template <typename T1, typename T2> 
Map_Key<T1, T2> Map_Key<T1, T2>::operator+(const Map_Key& mk) const
{
	Map_Key<T1, T2> tmp;
	tmp.key = key + mk.key;
	tmp.val = val + mk.val;
	return tmp;
}

int main()
{
	int i;
	string s;
	Map_Key<string, int> mk_1("One", 1), mk_2("Two", 2); 
	Map_Key<string, int> mk_3 = mk_1 + mk_2;
	vector<Map_Key<string, int>> v;

	v.push_back(mk_1);
	v.push_back(mk_2);
	v.push_back(mk_3);
	cout << "Enter string: ";
	cin >> s;
	for(i = 0; i < v.size(); i++)
	{
		if(v[i].check(s))
		{
			cout << "Value:" << v[i].get() << '\n';
			return 0;
		} 
	}
	cout << "Not found\n";
	return 0;
}


