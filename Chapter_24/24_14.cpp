#include <iostream> // ’σκηση 23.14 
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int SIZE = 100;

struct Band
{
      char name[SIZE];
      char category[SIZE];
      char singer[SIZE];
      int records;
}; 

int main()
{
	bool found;
	int i, band_num;
	char name[SIZE], singer[SIZE];
	Band *band_arr;

	fstream fstr("test.bin", ios_base::in | ios_base::out | ios_base::binary); 
	if(fstr.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	fstr.read((char*)&band_num, sizeof(int)); 
	if(!fstr) 
	{
		fstr.close();
		cout << "Error: read() failed\n";
		exit(EXIT_FAILURE);
	}
	band_arr = new Band[band_num];
	fstr.read((char*)band_arr, band_num * sizeof(Band)); 
	if(!fstr)
		cout << "Error: read() failed to read bands\n";
	else 
	{
		cout << "Enter band name: ";
		cin.getline(name, sizeof(name));
		
		cout << "Enter new singer: ";
		cin.getline(singer, sizeof(singer));

		found = 0;
		for(i = 0; i < band_num; i++)
			if(strcmp(band_arr[i].name, name) == 0)
			{
				fstr.seekp(i*sizeof(Band)+sizeof(int)); /* Αν βρεθεί η εγγραφή μετακινούμε τον δείκτη θέσης στην αρχή της εγγραφής, προσθέτοντας το μέγεθος της ακέραιας εγγραφής που δηλώνει το πλήθος των συγκροτημάτων και το μέγεθος των υπολοίπων δομών. */
				strcpy(band_arr[i].singer, singer); /* Αλλάζουμε το πεδίο της εγγραφής με τη νέα τιμή και την αποθηκεύουμε πάλι στο αρχείο. */
				fstr.write((char*)&band_arr[i], sizeof(Band)) << flush; // Έβαλα και το flush απλά για να το δείτε.
				cout << "\nSinger of band " << name << " is changed to " << singer << '\n';
				found = 1;
				break;
			}
	}
	if(found == 0)
		cout << name << " band isn't found\n\n";

	delete[] band_arr;
	fstr.close(); 
	return 0;
}

