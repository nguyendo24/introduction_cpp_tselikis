#include <iostream> // ������ 6.9
using std::cout;
using std::cin;

int main()
{
	int i, studs_num, suc, fail, times;
	float grd, sum_suc, sum_fail, min_grd, max_grd;

	cout << "Enter number of students: ";
	cin >> studs_num;
	if(studs_num <= 0)
	{
		cout << "Wrong number of students\n";
		return 0; // ����������� ������������. 
	}
	suc = fail = 0;
	sum_suc = sum_fail = 0;
	min_grd = 11;
	max_grd = -1; 
	for(i = 0; i < studs_num; i++)
	{
		cout << "Enter grade: ";
		cin >> grd;

		if(grd == -1)
			break;
		if(grd > 10 || grd < 0)
		{
			cout << "Wrong grade, try again ...\n";
			i--; /* �� � ������ ��� ������ ��� [0, 10], � ������������ �������� ���������������, ���� ����� ������� � �������� ����������� i ���� ���. */
			continue;
		}
		if(grd >= 5)
		{
			suc++;
			sum_suc += grd;
		}
		else
		{
			fail++;
			sum_fail += grd;
		}
		if(grd < min_grd)
			min_grd = grd;
		if(grd > max_grd)
		{
			max_grd = grd;
			times = 1; /* ����� �������� ��� ���� �������� ������. */
		}
		else if(max_grd == grd)
			times++;
	}
	if(i) // �������� ��� ���� �������� ���� ����������� ������. 
	{
		if(suc)
			cout << "Avg(+): " << sum_suc/suc << '\n';
		else
			cout << "Everybody failed\n";
	
		if(fail)
			cout << "Avg(-): " << sum_fail/fail << '\n';
		else
			cout << "None failed\n";

		cout << "Min: " << min_grd << " Max: " << max_grd << " (appeared " << times << " times)\n";
	}
	return 0;
}

