#include <iostream> // ’σκηση 25.3
#include <string> 
using std::ostream;
using std::string;

namespace Metric
{
	class Bad_Value
	{
		private:
			string msg;
		public:
			Bad_Value(const char *m);
			void show() const;
	};
	class Time
	{
		private:
			int hrs, mins, secs;
		public:
			Time(int h, int m, int s);
			bool operator==(const Time& t) const;
			friend ostream& operator<<(ostream& out, const Time& t);
	};
} 

// Αρχείο κώδικα.
namespace Metric 
{ 
	Bad_Value::Bad_Value(const char *m)
	{
		msg = m;
	}
	void Bad_Value::show() const 
	{
		std::cout << msg;
	}
}

namespace Metric 
{ 
	Time::Time(int h, int m, int s)
	{
		if(h < 0 || h > 24)
			throw Bad_Value("Wrong hours\n");
		if(m < 0 || m > 59)
			throw Bad_Value("Wrong minutes\n");
		if(s < 0 || s > 59)
			throw Bad_Value("Wrong seconds\n");
		if(h == 24)
		{
			if((m != 0) || (s != 0))
				throw Bad_Value("Wrong time\n");
		}
		hrs = h;
		mins = m;
		secs = s;
	}
	bool Time::operator==(const Time& t) const
	{
		return ((hrs == t.hrs) && (mins == t.mins) && (secs == t.secs));
	}
}

namespace Metric 
{
	ostream& operator<<(ostream& out, const Time& t)
	{
		out << "H:" << t.hrs << " M:" << t.mins << " S:" << t.secs;
		return out;
	} 
}

int main()
{
	using Metric::Bad_Value; 
	using Metric::Time;

	try
	{
		Time t1(1, 2, 3), t2(4, 5, 6);

		std::cout << (t1 == t2) << '\n';
		std::cout << t1;
	}
	catch(const Bad_Value& err)
	{
		err.show();
	}
	return 0;
}

