#include <iostream> // ’σκηση 24.11 
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	const int SIZE = 5;
	bool found;
	int i, len, back, buf[SIZE], sign[SIZE];

	ifstream fin("test.dat", ios_base::in | ios_base::binary); 
	if(fin.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	cout << "Enter virus signature (" << SIZE << " integers)\n";
	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter number: ";
		cin >> sign[i];
	}
	len = sizeof(sign);
	found = 0;
	back = len - sizeof(int);
	while(1)
	{
		fin.read((char*)buf, SIZE * sizeof(int));
		if(!fin)
			break;
		if(memcmp(buf, sign, len) == 0)
		{
			found = 1;
			break;
		}
		else
			fin.seekg(-back, ios_base::cur); /* Πηγαίνουμε πίσω για να ελέγξουμε την επόμενη πεντάδα. */
	}
	if(found == 1)
		cout << "SOS: Virus found\n";
	else
		cout << "That virus signature isn't found\n";
	fin.close();
	return 0;
}

