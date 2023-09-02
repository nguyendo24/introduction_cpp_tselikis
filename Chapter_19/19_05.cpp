#include <iostream> // ’σκηση 19.5
#include <cstring>
using std::cout;
using std::ostream;

class T
{
private:
	double *arr;
public:
	int size;
	explicit T(int n);
	~T();
	T(const T& t);
	T& operator=(const T& t);
	friend ostream& operator<<(ostream& out, const T& t);
};

T::T(int n)
{
	int i;

	size = n;
	arr = new double[size];
	for(i = 0; i < size; i++) // Απλά, αποθηκεύουμε κάποιες τιμές. 
		arr[i] = i+1; 
}

T::~T()
{
	delete[] arr;
}

T::T(const T& t) /* Ο κατασκευαστής αντιγράφου θα κληθεί με την εντολή Τ t3 = t1; Τα size και arr είναι τα πεδία του t3, ενώ το t αναφέρεται στο t1. */ 
{
	size = t.size;
	arr = new double[size];
	memcpy(arr, t.arr, size * sizeof(double));
}

T& T::operator=(const T& t) /* Υπερφόρτωση του τελεστή =. Θα κληθεί με τις εντολές t2 = t1; και t2 = t2; Τα size και arr είναι τα πεδία του t2, ενώ το t αναφέρεται στον δεξιό τελεστέο. Για το συγκεκριμένο παράδειγμα, ο τύπος επιστροφής της συνάρτησης θα μπορούσε να είναι και void, απλά επιλέγω την αναφορά για γενικότητα. */ 
{
	if(this == &t) /* Ελέγχουμε αν αναφερόμαστε στο ίδιο το αντικείμενο, όπως με την εντολή t2 = t2; */ 
		return *this;
	delete[] arr; // Αποδεσμεύουμε την παλιά μνήμη. 
	size = t.size;
	arr = new double[size];
	memcpy(arr, t.arr, size * sizeof(double));
	return *this;
}

ostream& operator<<(ostream& out, const T& t) /* Υπερφόρτωση του τελεστή << με τη χρήση φιλικής συνάρτησης. */ 
{
	for(int i = 0; i < t.size; i++) 
		out << t.arr[i] << ' '; 
	out << "\n\n";
	return out;
}

