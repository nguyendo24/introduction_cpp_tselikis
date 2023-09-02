#include <iostream> // ’σκηση 24.12 
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Employee 
{
	char name[100];
	int tax_num;
	int salary;
};

int main()
{
	const int SIZE = 100;
	int i, num_empl;
	Employee empl[SIZE];

	ofstream fout("test.bin", ios_base::out | ios_base::trunc | ios_base::binary); 
	if(fout.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	num_empl = 0; 
	for(i = 0; i < SIZE; i++)
	{
		cout << "\nEnter full name: ";
		cin.getline(empl[i].name, sizeof(empl[i].name));
		if(strcmp(empl[i].name, "fin") == 0)
			break;

		cout << "Enter tax number: ";
		cin >> empl[i].tax_num;

		cout << "Enter salary: ";
		cin >> empl[i].salary;

		num_empl++;
		cin.get();
      }
	// Γράφουμε κατευθείαν όλες τις δομές στο αρχείο.
	fout.write((char*)empl, num_empl * sizeof(Employee));
	fout.close();
	return 0;
}

