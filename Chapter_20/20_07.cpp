#include <iostream> // ’σκηση 20.7
#include <string>
using std::cout;
using std::string;

class Fruit
{
private:
	string name;
	int cal; 
public:
	Fruit(const string& s, int c) : name(s), cal(c) {}
	virtual ~Fruit() {}; 
	virtual int operator+(int num);
};

class Apple : public Fruit
{
private:
	int antiox; 
public:
	Apple(int ant, const string& name, int cal) : Fruit(name, cal), antiox(ant) {}
	virtual int operator+(int num) override;
};

int Fruit::operator+(int num)
{
	cal += num;
	return cal;
}

void f(Fruit& p, int num);

int Apple::operator+(int num)
{
	antiox += num;
	return antiox;
}

int main()
{
	Fruit fr("F1", 10);
	Apple ap(20, "F2", 30);

	f(fr, 5); // Το πρόγραμμα εμφανίζει 15.
	f(ap, 5); // Το πρόγραμμα εμφανίζει 25.
	return 0;
}

void f(Fruit& p, int num)
{
	cout << p+num << '\n'; 
}

