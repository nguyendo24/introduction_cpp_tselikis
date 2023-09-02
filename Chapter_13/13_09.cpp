#include <iostream> // ������ 13.9
#include <string> 
using namespace std;

struct Student
{
	string name;
	int code;
	float grd;
};

void sort_by_grade(Student studs[], int num_studs);
void show_students(const Student studs[], int num_studs, float avg_grd);

int main()
{
	const int SIZE = 100;
	int i;
	float sum_grd;
	Student studs[SIZE];

	sum_grd = 0;
	for(i = 0; i < SIZE; i++)
	{
		cout << "\nGrade [0-10]: ";
		cin >> studs[i].grd;
		if(studs[i].grd == -1)
			break;

		sum_grd += studs[i].grd;
		cin.get();

		cout << "Name: ";
		getline(cin, studs[i].name);

		cout << "Code: ";
		cin >> studs[i].code;
	}
	if(i == 0)
		return 0;
	sort_by_grade(studs, i); /* ���������� ����� ������� �� ��� ���� ��� ������ grd. � ��������� i ������� ����� �������� ����������. */
	show_students(studs, i, sum_grd/i); /* �� ��������� ������ ����� � ����� ���� ��� ������. */
	return 0;
}

void sort_by_grade(Student studs[], int num_studs)
{
	int i, j;
	Student s;

	for(i = 0; i < num_studs-1; i++)
	{
		/* ������� �������� ��� ������ grd ���� ����� �� �� ���������� ����� ��� ��������� ����� ��� �� ������ ������ �� ���������� ����, ���� �� ����� ����������������. */ 
		for(j = i+1; j < num_studs; j++)
		{
			if(studs[i].grd < studs[j].grd)
			{
				s = studs[i];
				studs[i] = studs[j];
				studs[j] = s;
			}
		}
	}
}

void show_students(const Student studs[], int num_studs, float avg_grd)
{
	int i;

	for(i = 0; i < num_studs; i++)
	{
		if(studs[i].grd > avg_grd)
			cout << "\nN:" << studs[i].name << " C:" << studs[i].code << " G:" << studs[i].grd << '\n';
		else
			return; /* ���� �� ����� ����� ����������� �� �������� ����� ��� ������� ������� ������� �� ����� ��������� � ��� ��� ��� ���� ���, ��� ���������� �� ����������� ��� ���������. */
	}
}

