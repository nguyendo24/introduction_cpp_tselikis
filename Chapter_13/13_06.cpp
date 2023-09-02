#include <iostream> // ’σκηση 13.6
#include <string> 
#include <vector> 
using namespace std; 

struct Product
{
	string name;
	int code;
	float prc;
};

const Product *find_prod(const vector<Product>& v, int code); 

int main()
{
	const Product *ptr;
	int code;
	float prc;
	Product tmp;
	vector<Product> prod; 

	while(1)
	{
		cout << "\nPrice: ";
		cin >> prc;
		if(prc <= 0)
			break;

		tmp.prc = prc;
		cin.get();
		cout << "Name: ";
		getline(cin, tmp.name);

		cout << "Code: ";
		cin >> tmp.code;
		prod.push_back(tmp);
	}
	if(prod.size() == 0)
	{
		cout << "No product is stored\n";
		return 0; 
	}
	cout << "\nEnter code to search: ";
	cin >> code;

	ptr = find_prod(prod, code);
	if(ptr == nullptr)
		cout << "\nNo product with code = " << code << '\n';
	else
		cout << "\nN:" << ptr->name << " C:" << code << " P:" << ptr->prc << '\n';
	return 0;
}

const Product *find_prod(const vector<Product>& v, int code)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].code == code)
			return &v[i]; /* Αν βρεθεί ο κωδικός του προϊόντος, η συνάρτηση τερματίζει άμεσα και επιστρέφει τη διεύθυνση της δομής. */
	}
	return nullptr; /* Αν φτάσουμε σε αυτό το σημείο σημαίνει ότι ο κωδικός του προϊόντος δεν βρέθηκε, οπότε η συνάρτηση επιστρέφει nullptr. */
}

