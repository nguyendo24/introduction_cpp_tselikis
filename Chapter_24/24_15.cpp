#include <iostream> // ’σκηση 23.15 
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
	/* Θα αποθηκεύσουμε τους βαθμούς σε έναν διδιάστατο πίνακα με stud_num γραμμές και LESSONS στήλες. Αρχικά, δεσμεύουμε μνήμη για τις γραμμές του πίνακα και στη συνέχεια δεσμεύουμε μνήμη για κάθε γραμμή. Έτσι, σε κάθε γραμμή αποθηκεύονται οι βαθμοί του φοιτητή σε LESSONS μαθήματα. */
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
			break; /* Δεν υπάρχει λόγος να συνεχίσουμε το διάβασμα. */
		}
	}
	for(i = 0; i < stud_num; i++)
		delete[] grd_arr[i]; 
	delete[] grd_arr;
	fin.close(); 
	return 0;
}

