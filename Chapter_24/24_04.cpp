#include <iostream> // ’σκηση 24.4
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	bool found;
	string fname, str1, str2;

	cout << "Enter first file: ";
	cin >> fname;
	ifstream fin_f(fname.c_str());
	if(fin_f.is_open() == false)
	{
		cout << "Error: first is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	cout << "Enter second file: ";
	cin >> fname;
	ifstream fin_s(fname.c_str());
	if(fin_s.is_open() == false)
	{
		fin_f.close();
		cout << "Error: second is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	found = 0;
	while(1)
	{
		getline(fin_f, str1);
		getline(fin_s, str2);
		if(!fin_f || !fin_s)
			break; /* Ελέγχουμε αν φτάσαμε στο τέλος κάποιου αρχείου ή αν συνέβη κάποιο λάθος. Σε και στις δύο περιπτώσεις ο βρόχος τερματίζει. */
		if(str1 == str2)
		{
			cout << "The same line is: " << str1 << '\n';
			found = 1;
			break; /* Αφού βρέθηκε κοινή γραμμή, δεν συνεχίζουμε με άλλες συγκρίσεις. */
		}
	}
	if(found == 0)
		cout << "There is no common line\n";
	fin_f.close();
	fin_s.close();
	return 0;
}

