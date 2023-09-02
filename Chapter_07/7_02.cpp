#include <iostream> // ’σκηση 7.2
#include <vector> 
using std::cout;
using std::cin;
using std::vector;

int main()
{
	int size;
	float grd, sum_suc, sum_fail, min_fail, max_fail, min_suc, max_suc;
	vector<float> suc, fail;

	sum_suc = sum_fail = 0;
	min_fail = min_suc = 11; // Αρχικοποίηση με μεγάλη τιμή.  
	max_fail = max_suc = -1; // Αρχικοποίηση με μικρή τιμή.
	while(1)
	{
		cout << "Enter grade: ";
		cin >> grd;
		/* Θα μπορούσαμε να ελέγξουμε την τιμή με πολλούς τρόπους. Σε επόμενες ασκήσεις χρησιμοποιώ do-while. */
		while(1)
		{
			if((grd >= 0 && grd <= 10) || (grd == -1))
				break;
			cout << "Error - Enter grade: ";
			cin >> grd; 
		}
		if(grd == -1)
			break;
		if(grd >= 5 && grd <= 10) /* Ελέγχουμε τον βαθμό και τον αποθηκεύουμε στο αντίστοιχο διανυσμα. */
		{
			sum_suc += grd;
			suc.push_back(grd);
			if(grd > max_suc)
				max_suc = grd;
			if(grd < min_suc)
				min_suc = grd;
		}
		else 
		{
			sum_fail += grd;
			fail.push_back(grd);
			if(grd > max_fail)
				max_fail = grd;
			if(grd < min_fail)
				min_fail = grd;
		}
	}
	size = suc.size();
	if(size != 0)
		cout << "\nSuccess_Avg: " << sum_suc/size << " Best: " << max_suc << " Worst: " << min_suc << '\n'; 
	else
		cout << "\nAll students failed";

	size = fail.size();
	if(size != 0)
		cout << "\nFail_Avg: " << sum_fail/size << " Best: " << max_fail << " Worst: " << min_fail << '\n';
	else
		cout << "All students passed\n";
	return 0;
}

