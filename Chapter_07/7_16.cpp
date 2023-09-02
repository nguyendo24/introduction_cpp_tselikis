#include <iostream> // ’σκηση 7.16
#include <vector> 
using std::cout;
using std::cin;
using std::vector;

int main()
{
	int studs, courses, i, j, min_pos, max_pos;
	float sum, min_grd, max_grd, avg_grd, min_avg_grd, max_avg_grd;

	do
	{
		cout << "Enter number of students: ";
		cin >> studs;

		cout << "Enter number of courses: ";
		cin >> courses;
	} while(studs <= 0 || courses <= 0);

	vector<vector<float>> grd(studs, vector<float>(courses)); /* Διάνυσμα δύο διαστάσεων. */
	max_avg_grd = -1;
	min_avg_grd = 11; 
	for(i = 0; i < studs; i++)
	{
		sum = 0;
		max_grd = -1; 
		min_grd = 11; 
		for(j = 0; j < courses; j++)
		{
			do
			{
				cout << "Enter grade of student_" << i+1 << " for lesson_" << j+1 << ": ";
				cin >> grd[i][j];
			} while(grd[i][j] < 0 || grd[i][j] > 10);
			
			sum += grd[i][j];
			if(grd[i][j] > max_grd)
				max_grd = grd[i][j];
			if(grd[i][j] < min_grd)
				min_grd = grd[i][j];
		}
		avg_grd = sum/courses;
		if(avg_grd > max_avg_grd)
		{
			max_avg_grd = avg_grd;
			max_pos = i;
		}
		if(avg_grd < min_avg_grd)
		{
			min_avg_grd = avg_grd;
			min_pos = i;
		}
		cout << "Student_" << i+1 << "(Avg:" << avg_grd << " Max:" << max_grd << " Min:" << min_grd << ")\n";
	}
	cout << "Student_" << max_pos << " has the higher average " << max_avg_grd << " and student_" << min_pos << " has the lower average " << min_avg_grd << ".\n";
	return 0;
}

