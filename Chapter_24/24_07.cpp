#include <iostream> // ’σκηση 24.7 
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Country
{
private:
	string name;
	string capital;
	int pop;
public:
	Country(const string& n = "", const string& c = "", int p = 0) : name(n), capital(c), pop(p) {}
	void set(const string& n, const string& c, int p);
	int get_pop() const {return pop;}
	void show() const;
};
void Country::set(const string& n, const string& c, int p)
{
	name = n;
	capital = c;
	pop = p;
}

void Country::show() const
{
	cout << name << '\t' << capital << '\t' << pop << '\n';
}

int main()
{
	int i, pop;
	string name, capital;
	Country tmp;
	vector<Country> cntr;

	ifstream fin("country.txt");
	if(fin.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	while(1)
	{
		fin >> name >> capital >> pop;
		if(!fin)
			break;
		tmp.set(name, capital, pop);
		cntr.push_back(tmp); // Αποθήκευση της χώρας. 
	}
	cout << "Enter population: ";
	cin >> pop;
	for(i = 0; i < cntr.size(); i++)
		if(cntr[i].get_pop() >= pop)
			cntr[i].show();

	fin.close();
	return 0;
}

