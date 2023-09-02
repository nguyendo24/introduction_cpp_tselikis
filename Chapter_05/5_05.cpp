#include <iostream> // ������ 5.5
using std::cout;
using std::cin;

int main()
{
	float bmi, height, weight;
	
	cout << "Enter height (in meters): ";
	cin >> height;

	cout << "Enter weight (in kgrs): ";
	cin >> weight;

	bmi = weight/(height*height);
	cout << "BMI:" << bmi << '\n';

	if(bmi < 18.5)
		cout << "Under normal weight\n";
	else if(bmi < 25) /* ���� �� �� ����������� if �������� ��� ����� ����� �� 20, ���� � ������� ����� ��������� �� else if(bmi >= 20 && bmi <= 25). */
		cout << "Normal weight\n";
	else if(bmi < 30)
		cout << "Overweight\n";
	else if(bmi < 40)
		cout << "Obese\n";
	else 
		cout << "Serious obesity\n";

	cout << "According to your height the bounds of normal weight are " << 18.5*height*height << " and " << 25*height*height << '\n'; /* ������� �� ��� ������ �� ���� ��� BMI ��� ����������� ����� ����� ��� 18.5 ����� 25. */
	return 0;
}

