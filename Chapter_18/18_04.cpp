#include <iostream> // ’σκηση 18.4
#include <cstring>
using std::cout;
using std::cin;

class T
{
private:
	char *s;
public:
	T(char str[]);
	~T();
	int operator==(const T& t) const;
	void operator+(const T& t);
	void operator-(char ch);
	char* operator()(int pos) const;
	void show() const {cout << s << '\n';}
};

T::T(char str[])
{
	s = new char[strlen(str)+1];
	strcpy(s, str);
}

T::~T()
{
	delete[] s;
}

int T::operator==(const T& t) const
{
	return strcmp(s, t.s);
}
void T::operator+(const T& t)
{
	char *p;

	p = new char[strlen(s)+strlen(t.s)+1];
	p[0] = '\0';
	strcpy(p, s);
	strcat(p, t.s);
	delete[] s; // Αποδέσμευση παλιάς μνήμης.
	s = p; // Ο δείκτης s δείχνει στη νέα μνήμη.
}

void T::operator-(char ch)
{
	for(int i = 0; i < strlen(s); i++)
		if(s[i] == ch)
			s[i] = '*';
}

char* T::operator()(int pos) const
{
	return s+pos; 
}

