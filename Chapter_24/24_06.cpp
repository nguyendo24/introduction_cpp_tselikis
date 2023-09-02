#include <iostream> // ’σκηση 24.6 
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	int ch, key_ch;
	string fname;

	cout << "Enter input file: ";
	cin >> fname;
	ifstream fin(fname.c_str());
	if(fin.is_open() == false)
	{
		cout << "Error: Input file can't be loaded\n";
		exit(EXIT_FAILURE); 
	}
	cout << "Enter output file: ";
	cin >> fname;
	ofstream fout(fname.c_str());
	if(fout.is_open() == false)
	{
		fin.close();
		cout << "Error: Output file can't be created\n";
		exit(EXIT_FAILURE); 
	}
	cin.get();
	cout << "Enter key char: ";
	key_ch = cin.get();
	while(1)
	{
		ch = fin.get();
		if(!fin)
			break;
		fout << (char)(ch ^ key_ch); 
	}
	fin.close();
	fout.close();
	return 0;
}

