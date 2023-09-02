#include <iostream> // ’σκηση 17.11

class Time
{
private:
	int hr;
	int min;
	int sec;
public:
	Time(int h, int m, int s);
	Time& inc_hour();
	Time& inc_min();
	Time& inc_sec();
	void show() const; 
};

Time::Time(int h, int m, int s)
{
	hr = h;
	min = m;
	sec = s;
}

Time& Time::inc_hour()
{
	hr++;
	return *this;
}

Time& Time::inc_min()
{
	min++;
	if(min == 60)
	{
		min = 0;
		hr++;
	}
	return *this;
}

Time& Time::inc_sec()
{
	sec++;
	if(sec == 60)
	{
		sec = 0;
		inc_min();
	}
	return *this;
}

void Time::show() const
{
	std::cout << "Time " << hr << ':' << min << ':' << sec << '\n';
}


