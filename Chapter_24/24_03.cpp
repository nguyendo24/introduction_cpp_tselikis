#include <iostream> // ’σκηση 24.3
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	string fnm, lnm;
	int suc_stud, fail_stud;
	double grd1, grd2;

	ifstream fin("students.txt");
	if(fin.is_open() == false)
	{
		cout << "Error: students.txt can't be loaded\n";
		exit(EXIT_FAILURE); 
	}
	ofstream fout_suc("suc.txt");
	if(fout_suc.is_open() == false)
	{
		fin.close();
		cout << "Error: suc.txt can't be created\n";
		exit(EXIT_FAILURE); 
	}
	ofstream fout_fail("fail.txt");
	if(fout_fail.is_open() == false)
	{
		fin.close();
		fout_suc.close();
		cout << "Error: fail.txt can't be created\n";
		exit(EXIT_FAILURE); 
	}
	suc_stud = fail_stud = 0;
	while(1)
	{
		fin >> fnm >> lnm >> grd1 >> grd2;
		if(!fin)
			break;
		if((grd1+grd2)/2 >= 5)
		{
			fout_suc << fnm << ' ' << lnm << ' ' << grd1 << ' ' << grd2 << '\n';
			suc_stud++;
		}
		else
		{
			fout_fail << fnm << ' ' << lnm << ' ' << grd1 << ' ' << grd2 << '\n';
			fail_stud++;
		}
	}
	cout << "Fail: " << fail_stud << " Success: " << suc_stud << '\n';
	fin.close();
	fout_suc.close();
	fout_fail.close();
	return 0;
}

