#include <iostream> // ’σκηση 16.2
#include <string>
using std::cout;
using std::string;

struct Student
{
	string name;
	float grd;
};

const string& cmp(const string& a, const string& b);
string cmp(const Student& a, const Student& b);

int main()
{
	string s1 = "alpha", s2 = "beta"; 
	Student st1 = {"N.Smith", 6.5}, st2 = {"P.Krow", 5.2}; 

	string tmp = cmp(s1, s2); /* To see that we can assign the return value to a simple variable. */
	cout << tmp << '\n';

	tmp = cmp(st1, st2); 
	if(tmp == "")
		cout << "Same grades\n";
	else
		cout << tmp << '\n';
	return 0;
}

const string& cmp(const string& a, const string& b)
{
	if(a > b)
		return a;
	else
		return b;
}

string cmp(const Student& a, const Student& b)
{
	if(a.grd > b.grd)
		return a.name;
	else if(a.grd < b.grd)
		return b.name;
	else 
		return "";
}

