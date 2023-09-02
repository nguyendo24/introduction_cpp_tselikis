#include <iostream> // ’σκηση 24.2 
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	bool found; 
	string code, tmp;
	double prc;

	fstream fstr("test.txt", ios_base::in | ios_base::out | ios_base::trunc); 
	if(fstr.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	while(1)
	{
		cout << "Enter price: ";
		cin >> prc;
		if(prc == -1)
			break;
		cin.get();
		cout << "Enter product code: ";
		getline(cin, code);
		fstr << code << ' ' << prc << '\n';
	}
	cin.get();
	cout << "Enter product code to search for: ";
	getline(cin, tmp);

	found = 0;
	fstr.seekg(0); 
	while(1)
	{
		fstr >> code >> prc;
		if(!fstr)
			break;
		if(code == tmp)
		{
			found = 1;
			break; /* Αφού το προϊόν βρέθηκε μπορούμε να τερματίσουμε τον βρόχο. */
		}
	}
	if(found == 0)
		cout << tmp << " code is not listed\n";
	else
		cout << "The price for product " << code << " is " << prc << '\n';
	fstr.close();
	return 0;
}

