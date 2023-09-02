#include <iostream> // Άσκηση 18.3
using std::cout;
using std::ostream;

class Time
{
private:
	int hrs;
	int mins;
	int secs;
public:
	Time(int hrs=0, int mins=0, int secs=0);
	bool operator==(const Time& t) const;
	void operator++();
	friend ostream& operator<<(ostream& out, const Time& t);
};
Time::Time(int hrs, int mins, int secs)
{
	this->hrs = hrs; /* Επειδή υπάρχει ο περιορισμός για ίδια ονόματα χρησιμοποιούμε τον δείκτη this. */
	this->mins = mins;
	this->secs = secs;
}

bool Time::operator==(const Time& t) const
{
	if((hrs == t.hrs) && (mins == t.mins) && (secs == t.secs))
		return true;
	else
		return false;
}

void Time::operator++()
{
	secs++;
	if(secs == 60)
	{
		secs = 0;
		mins++;
		if(mins == 60)
		{
			mins = 0;
			hrs++;
			if(hrs == 24)
				hrs = 0;
		}
	}
}

ostream& operator<<(ostream& out, const Time& t)
{
	out << t.hrs << ':' << t.mins << ':' << t.secs << '\n';
	return out;
}

