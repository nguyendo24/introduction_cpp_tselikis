#include <iostream> // ������ 6.13 
using std::cout;
using std::cin;

int main()
{
	const int LESSONS = 3;
	const int STUDENTS = 5;
	int i, j;
	float grd, stud_grd, sum_grd;

	sum_grd = 0;
	for(i = 0; i < STUDENTS; i++)
	{
		cout << "***** Student_" << i+1 << '\n';
		stud_grd = 0; /* ���� � ��������� ������� �� �������� ��� ������ ��� ���� ������� �� ��� �� ��������. ����������� ��� ���� �������. */
		for(j = 0; j < LESSONS; j++)
		{
			cout << "Enter grade for lesson " << j+1 << ": ";
			cin >> grd;
			stud_grd += grd;
			sum_grd += grd; /* ���� � ��������� ������� �� �������� �������� ���� ��� ������. */
		}
		cout << "Average grade for student_" << i+1 << " is " << stud_grd/LESSONS << '\n';
	}
	cout << '\n' << "Total average grade is " << sum_grd/(STUDENTS*LESSONS) << '\n';
	return 0;
}

