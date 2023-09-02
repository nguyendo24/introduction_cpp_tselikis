#include <iostream> // ’σκηση 23.2
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;

class Employee
{
private:
	string name;
	int sal;
public:
	Employee(const string& n, int s) : name(n), sal(s) {}
	void show() const {cout << "N:" << name << " S:" << sal << '\n';} // Σε αυτό το πρόγραμμα δεν χρειάζεται να είναι virtual.
};

class Manager : public Employee
{
private:
	string dpt;
public:
	Manager(const string& d, const string& n, int s) : Employee(n, s), dpt(d) {}
	void show() const;
};

void Manager::show() const 
{
	Employee::show();
	cout << "D:" << dpt << '\n';	
}

template <typename T> class Person
{
private:
	vector<T> v;
public:
	void show() const;
	void add(T t) {v.push_back(t);}
};

template <typename T> void Person<T>::show() const
{
	for(int i = 0; i < v.size(); i++)
		v[i]->show();
}

