#include <iostream> // ’σκηση 17.6
#include <cstring>
using std::cout;
using std::cin;

class T
{
private:
	char *s;
public:
	T(char str[]);
	T();
	~T();
	void show() const;
};

T::T()
{
	s = nullptr; /* Αρχικοποιούμε τον δείκτη, ώστε να μην υπάρχει πρόβλημα με την αποδέσμευση της μνήμης. Για παράδειγμα, για το t2 δεν έχει δεσμευτεί μνήμη. */
}

T::T(char str[])
{
	s = new char[strlen(str)+1];
	strcpy(s, str);
}

T::~T()
{
	delete[] s;
}

void T::show() const
{
	for(char *p = s+strlen(s)-1; p >= s; p--)
		cout << *p;
}

