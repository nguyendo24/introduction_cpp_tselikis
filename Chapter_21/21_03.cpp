#include <iostream> // ’σκηση 21.3 
#include <string>
using std::string;

class Person
{
private:
	string name;
	int code;
public:
	Person(const string& n = "None", int c = -1) : name(n), code(c) {}
	virtual ~Person() {}
	virtual float& operator[](int i) = 0;
};

class Student : public Person
{
private:
	float grd[5];
public:
	virtual float& operator[](int i);
};

class Employee : public Person
{
private:
	float fee[3];
public:
	virtual float& operator[](int i);
};

float& Student::operator[](int i)
{
	return grd[i];
}

float& Employee::operator[](int i)
{
	return fee[i];
}

