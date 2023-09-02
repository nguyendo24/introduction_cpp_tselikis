#include <iostream> // ’σκηση 6.24
#include <iomanip>
using namespace std;

int main()
{

	const int TEST_TIME = 30;
	int test, age, max_t2_age, max_t2_pos, max_t1_seq, tot_tests, t1_seq, t2_tests, hr, min, time, new_time;

	tot_tests = t1_seq = t2_tests = max_t2_age = max_t1_seq = 0;
	do
	{
		cout << "\nEnter arrival time: ";
		cin >> time;

		if(time != -1)
		{
			cout << "Enter test type: ";
			cin >> test;

			cout << "Enter age: ";
			cin >> age;

			tot_tests++;
			if(test == 1)
			{
				t1_seq++;
				if(t1_seq > max_t1_seq)
					max_t1_seq = t1_seq;
			}
			else
			{
				t1_seq = 0;
				t2_tests++;
				if(age > max_t2_age)
				{
					max_t2_age = age;
					max_t2_pos = tot_tests;
				}
			}
			hr = time/100;
			min = time%100;
			if((min + TEST_TIME) >= 60)
				hr++;
			if(hr == 24)
				hr = 0;
			min = (min + TEST_TIME) % 60;
			new_time = hr*100 + min;
			cout << "\nDeparture time: " << setw(4) << setfill('0') << new_time << '\n';
		}
	} while(time != -1);

	if(tot_tests)
	{
		cout << "\nMax_T1_Seq: " << max_t1_seq << '\n';
		if(t2_tests)
			cout << "Max_T2_Age: " << max_t2_age << " Pos: " << max_t2_pos << " Ratio: " << 100.0*t2_tests/tot_tests << "%\n";
		else
			cout << "No T2 tests were performed\n";
	}
	return 0;
}

