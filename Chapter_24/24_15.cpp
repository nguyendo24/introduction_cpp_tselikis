#include <iostream> // ������ 23.15 
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	const int LESSONS = 5;
	int i, j, stud_num;
	float **grd_arr, sum_grd;

	ifstream fin("test.bin", ios_base::in | ios_base::binary); 
	if(fin.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	fin.read((char*)&stud_num, sizeof(int)); 
	if(!fin) 
	{
		fin.close();
		cout << "Error: read() failed to read number\n";
		exit(EXIT_FAILURE);
	}
	/* �� ������������� ���� ������� �� ���� ���������� ������ �� stud_num ������� ��� LESSONS ������. ������, ���������� ����� ��� ��� ������� ��� ������ ��� ��� �������� ���������� ����� ��� ���� ������. ����, �� ���� ������ ������������� �� ������ ��� ������� �� LESSONS ��������. */
	grd_arr = new float*[stud_num];
	for(i = 0; i < stud_num; i++)
		grd_arr[i] = new float[LESSONS];

	for(i = 0; i < stud_num; i++)
	{
		sum_grd = 0;
		fin.read((char*)grd_arr[i], LESSONS * sizeof(float)); 
		if(fin) 
		{
			for(j = 0; j < LESSONS; j++)
				sum_grd += grd_arr[i][j];

			cout << i+1 << ". " << ' ' << sum_grd/LESSONS << '\n';
		}
		else 
		{
			cout << "Error: read() failed\n";
			break; /* ��� ������� ����� �� ����������� �� ��������. */
		}
	}
	for(i = 0; i < stud_num; i++)
		delete[] grd_arr[i]; 
	delete[] grd_arr;
	fin.close(); 
	return 0;
}

