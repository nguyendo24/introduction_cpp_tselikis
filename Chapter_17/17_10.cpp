#include <iostream> // ’σκηση 17.10
#include <string>
#include <vector>
using std::vector;
using std::string;

class Publisher
{
private:
	string name;
public:
	void set(const string& name) {this->name = name;}
	string get() const {return name;}
};

class Book
{
private:
	string isbn;
	float prc;
public:
	Book(const string& isbn, float prc, const string& name);
	Publisher pub;
};


Book::Book(const string& isbn, float prc, const string& name)
{
	this->isbn = isbn;
	this->prc = prc;
	pub.set(name);
}

vector<Publisher> fill(const vector<Book>& v_book) 
{
	int i;
	vector<Publisher> v_pub;
	
	for(i = 0; i < v_book.size(); i++)
		v_pub.push_back(v_book[i].pub);
	return v_pub;
}

Publisher* find(vector<Publisher>& v_pub)
{
	int i, j, cnt, max, pos;
	string name;
	
	max = 0;
	for(i = 0; i < v_pub.size(); i++)
	{
		cnt = 0;
		name = v_pub[i].get();
		for(j = i+1; j < v_pub.size(); j++)
		{
			if(name == v_pub[j].get())
				cnt++;
		}
		if(cnt > max)
		{
			max = cnt;
			pos = i;
		}
	}
	if(max == 0)
		return nullptr;
	else
		return &v_pub[pos];
}

int main()
{
	Publisher *p;
	vector<Book> vec_book = {Book("1-2-3", 30, "First"), Book("4-5-6", 40, "Sec"), Book("7-8-9", 50, "First")}; /* Γεμίζουμε το διάνυσμα με κάποια στοιχεία. */
	vector<Publisher> vec_pub = fill(vec_book);
	p = find(vec_pub);
	if(p != nullptr)
		std::cout << "Name:" << p->get() << '\n';
	else
		std::cout << "No publisher with more than one book.\n";
	return 0;
}

