#include <iostream> // ’σκηση 24.1 
#include <fstream>
#include <cstdlib> 
#include <string> 
using namespace std;

class Student 
{
private: 
	int code;
	string name; 
	float grd;
public: 
	Student(int c, const string& n, float g) : code(c), name(n), grd(g) {}
	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);
	void show() const {cout << "N:" << name << " C:" << code << " G:" << grd << '\n';}

};

istream& operator>>(istream& in, Student& s)
{
	in >> s.name >> s.code >> s.grd;
	return in;
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << s.name << '\t' << s.code << '\t' << s.grd << '\n';
	return out;
}

int main() // Συμπληρώνουμε τα κενά στον κώδικα.
{
	Student s1(1, "First", 2.5), s2(5, "Second", 7.5);

	fstream fstr("test.txt", ios_base::in | ios_base::out | ios_base::trunc); 
	if(fstr.is_open() == false) 
	{
		cout << "Error: File can not be opened\n";
		exit(EXIT_FAILURE); 
	}
	fstr << s1 << s2;
	fstr.seekg(0);
	fstr >> s1 >> s2;
	s1.show();
	s2.show();
	fstr.close(); 
	return 0;
}

