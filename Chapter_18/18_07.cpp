#include <iostream> // ’σκηση 18.7
#include <vector>
using namespace std;

template <typename T> T sum(const vector<T>& v)
{
	T t = {0}; /* Ένας τρόπος ανάθεσης αρχικής τιμής. Για παράδειγμα, αν το T είναι int, το t θα γίνει 0. Αν το T είναι ο τύπος Product ο κατασκευαστής θα κάνει τα πεδία του t ίσα με 0. Η αρχική τιμή 0 είναι απαραίτητη ώστε να υπολογιστεί σωστά το άθροισμα. */
	for(int i = 0; i < v.size(); i++)
		t = t + v[i];
	return t;
}

class Product
{
	private:
		int code;
	public:
		float prc;
		Product(int c = 0, float p = 0);
		Product& operator+(const Product& p);
};

Product::Product(int c, float p)
{
	code = c;
	prc = p;
}

Product& Product::operator+(const Product& p)
{
	prc += p.prc;
	return *this;  
}

