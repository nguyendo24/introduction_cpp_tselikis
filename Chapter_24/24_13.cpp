#include <iostream> // ’σκηση 24.13
#include <fstream>
#include <cstdlib>
using namespace std;

struct Employee 
{
	char name[100];
	int tax_num;
	int salary;
};

int main()
{
	int count, amount, sum_sal;
	Employee tmp_emp;

	ifstream fin("test.bin", ios_base::in | ios_base::binary); 
	if(fin.is_open() == false)
	{
		cout << "Error: Input file can't be loaded\n";
		exit(EXIT_FAILURE); 
	}
	ofstream fout("data.bin", ios_base::out | ios_base::trunc | ios_base::binary); 
	if(fout.is_open() == false)
	{
		fin.close();
		cout << "Error: Output file can't be created\n";
		exit(EXIT_FAILURE); 
	}
	cout << "Enter amount: ";
	cin >> amount;
	count = sum_sal = 0;
	while(1)
	{
		fin.read((char*)&tmp_emp, sizeof(Employee)); /* Διάβασμα εγγραφής. */
		if(!fin)
			break;
		if(tmp_emp.salary > amount)
		{
			fout.write((char*)&tmp_emp, sizeof(Employee));
			sum_sal += tmp_emp.salary;
			count++;
		}
	}
	if(count)
		cout << "Avg:" << (float)sum_sal/count << '\n';
	else 
		cout << "No employee gets more than " << amount << '\n';
	fin.close();
	fout.close();
	return 0;
}

