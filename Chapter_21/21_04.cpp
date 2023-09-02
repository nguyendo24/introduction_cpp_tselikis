#include <iostream> // ’σκηση 21.4 
#include <string>
using std::cout;
using std::string;

class School
{
private:
	string name;
public:
	School(const string& n) : name(n) {}
	School() {}
	virtual ~School() {}
	virtual void show() const;
};

void School::show() const
{
	cout << "School: " << name << '\n';
}
class Programming : virtual public School
{
private:
	int courses; 
public:
	Programming(int num) : courses(num) {}
	virtual void show() const;
};

void Programming::show() const
{
	cout << "Prog_Courses: " << courses << '\n';
}

class Network : virtual public School
{
private:
	int courses; 
public:
	Network(int num) : courses(num) {}
	virtual void show() const;
};

void Network::show() const
{
	cout << "Net_Courses: " << courses << '\n';
}

class Student : public Programming, public Network 
{
private:
	string name;
	int code; 
public:
	Student(const string& sch_n, const string& stud_n, int num, int prg_c, int prg_n) : School(sch_n), Programming(prg_c), Network(prg_n), name(stud_n), code(num) {}
	virtual void show() const;
};

void Student::show() const
{
	cout << "Stud:" << name << ' ' << "Code:" << code << '\n';
	// Κλήση της κάθε show().
	Programming::show();
	Network::show();
	School::show();
}

