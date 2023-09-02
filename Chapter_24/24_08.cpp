#include <iostream> // ’σκηση 24.8
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	int i, arr[5] = {10, 20, 30, 40, 50};
	fstream fstr("test.bin", ios_base::in | ios_base::out | ios_base::trunc | ios_base::binary); /* ’νοιγμα δυαδικού αρχείου για εγγραφή και ανάγνωση. */
	if(fstr.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	fstr.write((char*)arr, sizeof(arr)); 

	cout << "Enter new value: ";
	cin >> i;
	fstr.seekp(2*sizeof(int)); /* Αν ο int τύπος καταλαμβάνει 4 οκτάδες, η fseek() μετατοπίζει τον δείκτη θέσης του αρχείου 2*sizeof(int) = 8 οκτάδες από την αρχή του αρχείου, ώστε να μεταφερθεί στη θέση που βρίσκεται ο τρίτος ακέραιος. */
	fstr.write((char*)&i, sizeof(int)); 

	fstr.seekg(0);
	fstr.read((char*)arr, sizeof(arr));
	if(!fstr)
	{
		fstr.close();
		cout << "Error: read() failed\n";
		exit(EXIT_FAILURE);
	}
	cout << "\n***** File contents *****\n";
	for(i = 0; i < 5; i++)
		cout << arr[i] << '\n';

	fstr.close();
	return 0;
}

