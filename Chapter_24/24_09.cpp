#include <iostream> // ’σκηση 24.9 
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	bool found;
	int i, len;
	char title[100], str[100];
	string fname;

	cout << "Enter file name: ";
	cin >> fname;
	fstream fstr(fname.c_str(), ios_base::in | ios_base::out | ios_base::trunc | ios_base::binary); 
	if(fstr.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	cin.get();
	for(i = 0; i < 10; i++)
	{
		cout << "Enter title: ";
		cin.getline(title, sizeof(title));
		len = strlen(title);
		fstr.write((char*)&len, sizeof(int));
		fstr.write(title, len);
	}
	cout << "Enter title to search: ";
	cin.getline(str, sizeof(str));

	found = 0;
	fstr.seekg(0);
	while(1)
	{
		fstr.read((char*)&len, sizeof(int));
		if(!fstr)
			break; 
		fstr.read(title, len);
		if(!fstr)
			break; 
		title[len] = '\0';
		if(strcmp(title, str) == 0)
		{
			found = 1;
			break;
		}
	}
	if(found == 0)
		cout << "\nTitle not found\n";
	else
		cout << "\nTitle found\n";
	fstr.close();
	return 0;
}

