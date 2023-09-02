#include <iostream> // ’σκηση 18.5
#include <string>
using std::cout;
using std::cin;
using std::istream;

class Student
{
private:
	int code;
	int courses;
	float *grd;
	int suc; /* Προστέθηκε αυτό το πεδίο για τον αριθμό των επιτυχόντων μαθημάτων. */
public:
	~Student();
	void show() const;
	int operator>(const Student& s) const;
	friend istream& operator>>(istream& in, Student& s);
	Student& operator=(const Student&) = delete; /* Κατάργηση αντιγραφής. */
};

Student::~Student()
{
	delete[] grd;
}

int Student::operator>(const Student& s) const
{
	if(suc > s.suc)
		return 1;
	else if(suc < s.suc)
		return 2;
	else
		return 3;
}

void Student::show() const
{
	cout << "\nCode:" << code << '\n';
}


istream& operator>>(istream& in, Student& s)
{
	int i;

	cout << "Enter code: ";
	in >> s.code;
	cout << "Enter number of courses: ";
	in >> s.courses;
	s.grd = new float[s.courses];
	s.suc = 0;

	for(i = 0; i < s.courses; i++)
	{
		cout << "Enter grade: ";
		in >> s.grd[i];
		if(s.grd[i] >= 5)
			s.suc++;
	}
	return in;
}

int main()
{	
	int i; 
	Student s1, s2;

	cin >> s1 >> s2;
	i = (s1 > s2); 
	if(i == 1)
		s1.show();
	else if(i == 2)
		s2.show();
	else
		cout << "\nSame number of passed courses\n";
	return 0;
}

