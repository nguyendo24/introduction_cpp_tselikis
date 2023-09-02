#include <iostream> // ’σκηση 24.5 
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	int ch, lines;
	string fname;

	cout << "Enter file name: ";
	cin >> fname;
	ifstream fin(fname.c_str());
	if(fin.is_open() == false)
	{
		cout << "Error: is_open() failed\n";
		exit(EXIT_FAILURE); 
	}
	cout << "Line contents: ";
	lines = 1;
	while(1)
	{
		ch = fin.get(); 
		if((!fin) || (lines > 2))
			break;
		if(lines == 2) /* Μόνο οι χαρακτήρες της δεύτερης γραμμής εμφανίζονται στην οθόνη. */
			cout << (char)ch;
		if(ch == '\n') /* Όταν διαβαστεί ο χαρακτήρας νέας γραμμής αυξάνεται η μεταβλητή που μετράει τις γραμμές του αρχείου. */
			lines++;
	}
	fin.close();
	return 0;
}

