#include <iostream> // ’σκηση 13.4

struct Time
{
	int hours; 
	int mins;
	int secs;
};

Time mk_time(const int *s);

int main()
{
	int secs;
	Time t; 

	std::cout << "Enter seconds: ";
	std::cin >> secs;

	t = mk_time(&secs);
	std::cout << "\nH:" << t.hours << " M:" << t.mins << " S:" << t.secs << '\n';
	return 0;
}

Time mk_time(const int *s)
{
	Time tmp;

	tmp.hours = *s/3600;
	tmp.mins = (*s%3600)/60;
	tmp.secs = *s%60;
	return tmp;
}

