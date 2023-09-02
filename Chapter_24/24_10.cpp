#include <iostream> // ’σκηση 24.10 
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	int i, grd_num;
	float *grd_arr, grd;

	ifstream fin("test.bin", ios_base::in | ios_base::binary); 
	if(fin.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	fin.read((char*)&grd_num, sizeof(int));
	if(!fin) 
	{
		fin.close();
		cout << "Error: read() failed\n";
		exit(EXIT_FAILURE);
	}
	grd_arr = new float[grd_num]; /* Δέσμευση μνήμης για την αποθήκευση των βαθμών. */
	fin.read((char*)grd_arr, grd_num * sizeof(float)); /* Διάβασμα των βαθμών και έλεγχος ότι δεν συνέβη κάποιο λάθος. */
	if(fin) 
	{
		cout << "Enter grade: ";
		cin >> grd;
		for(i = 0; i < grd_num; i++)
			if(grd_arr[i] > grd)
				cout << grd_arr[i] << '\n';
	}
	else 
		cout << "Error: read() failed to read grades\n";

	delete[] grd_arr;
	fin.close(); 
	return 0;
}

