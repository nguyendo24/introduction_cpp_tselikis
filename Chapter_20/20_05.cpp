#include <iostream> // ’σκηση 20.5
#include <string>
using std::cout;
using std::string;

class Product
{
protected:
	int code;
public:
	Product(int c);
	virtual ~Product() {}; /* Δεν χρειάζεται, απλά για να συνηθίζετε. */
	virtual void show() const;
};

class Book : public Product
{
private:
	string title;
public:
	Book(string t, int c);
	virtual void show() const override;
};

void f(const Product *p1, const Product *p2);

Product::Product(int c)
{
	code = c;	
}

void Product::show() const
{
	cout << "C:" << code << '\n';
}

Book::Book(string t, int c) : Product(c)
{	
	title = t;
}

void Book::show() const
{
	cout << "C:" << code << " T:" << title << '\n'; /* Αφού το code είναι προστατευμένο μέλος μπορούμε να το προσπελάσουμε. */
}

int main()
{
	Product prod(100); 
	Book b("C++", 200);

	Product *p1 = &prod;
	Product *p2 = &b;
	f(p1, p2);
	return 0;
}

void f(const Product *p1, const Product *p2) 
{
	p1->show(); 
	p2->show(); 
}

