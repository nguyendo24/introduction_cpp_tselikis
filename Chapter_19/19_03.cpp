#include <iostream> // ’σκηση 19.3
#include <cstring>
#include <cstdlib> // Για την exit().
using std::cout;
using std::ostream;

class T
{
private:
	char *s;
public:
	explicit T(const char str[]);
	T() {s = nullptr;}
	~T();
	T(const T& t);
	T operator+(const T& t);
	T& operator=(const T& t);
	char& operator[](int i);
};

T::T(const char str[])
{
	s = new char[strlen(str)+1];
	strcpy(s, str);
}

T::~T()
{
	delete[] s;
}

T T::operator+(const T& t) /* Υπερφόρτωση του τελεστή +. Θα κληθεί με την εντολή t1+t2; Το s είναι το πεδίο του t1, ενώ το t αναφέρεται στο t2. */
{
	T tmp; 

	tmp.s = new char[strlen(s)+strlen(t.s)+1];
	tmp.s[0] = '\0';
	strcpy(tmp.s, s);
	strcat(tmp.s, t.s);
	return tmp;
}

T& T::operator=(const T& t) /* Υπερφόρτωση του τελεστή =. Πρώτα Θα κληθεί με την εντολή t3 = t1+t2; Το s είναι το πεδίο του t3, ενώ το t αναφέρεται στο αντικείμενο που επιστρέφει η συνάρτηση operator+. */
{
	if(this == &t) /* Έλεγχος αυτοανάθεσης για τη γενική περίπτωση, για το συγκεκριμένο πρόγραμμα δεν χρειάζεται. */
		return *this;

	delete[] s;
	s = new char[strlen(t.s)+1];
	strcpy(s, t.s);
	return *this;
}

T::T(const T& t) /* Ο κατασκευαστής αντιγράφου θα κληθεί με την εντολή Τ t5(t4); Το s είναι το πεδίο του t5, ενώ το t αναφέρεται στο t4. */ 
{
	s = new char[strlen(t.s)+1];
	strcpy(s, t.s);
}

char& T::operator[](int i) 
{
	if(i < 0 || i >= strlen(s)) /* Έλεγχος ορίων για τη γενική περίπτωση, για το συγκεκριμένο πρόγραμμα δεν χρειάζεται. */
		exit(EXIT_FAILURE); 
	return s[i];
}

