#include <iostream> // Άσκηση 18.8
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;
template <typename T> void sort(vector<T>& v);

class Product
{
	private:
		int code;
		float prc;
	public:
		Product(int c = 0, float p = 0) {code = c; prc = p;}
		bool operator>(const Product& p) const;
		void show() const {cout << "C:" << code << " P:" << prc << '\n';}
};

bool Product::operator>(const Product& p) const
{
	if(prc > p.prc)
		return true;
	return false;
}

class Employee
{
	private:
		string name;
		float sal; 
	public:
		Employee(const string& n = "", float s = 0) {name = n; sal = s;}
		bool operator>(const Employee& e) const;
		void show() const {cout << "N:" << name << " S:" << sal << '\n';}
};

bool Employee::operator>(const Employee& e) const
{
	if(name > e.name)
		return true;
	return false;
}

int main()
{
	int i;
	vector<Product> v_prd = {Product(10, 3.5), Product(20, 1.5), Product(30, 2.5)};
	vector<Employee> v_emp = {Employee("Mike", 100), Employee("John", 200), Employee("Nick", 300)};

	sort(v_prd);
	sort(v_emp);
	for(i = 0; i < v_prd.size(); i++)
		v_prd[i].show();
	for(i = 0; i < v_emp.size(); i++)
		v_emp[i].show();
	return 0;
}

template <typename T> void sort(vector<T>& v)
{
	int i, j, size; 
	T tmp; // Θα κληθεί ο κατασκευαστής της κάθε κλάσης.

	size = v.size();
	for(i = 0; i < size-1; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(v[i] > v[j]) /* Για την σύγκριση των στοιχείων καλείται η συνάρτηση υπερφόρτωσης του > της κάθε κλάσης. */
			{
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}

