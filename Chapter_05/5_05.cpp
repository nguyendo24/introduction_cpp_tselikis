#include <iostream> // ’σκηση 5.5
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
	else if(bmi < 25) /* Αφού με το προηγούμενο if ελέγξαμε τις τιμές μέχρι το 20, αυτή η συνθήκη είναι ισοδύναμη με else if(bmi >= 20 && bmi <= 25). */
		cout << "Normal weight\n";
	else if(bmi < 30)
		cout << "Overweight\n";
	else if(bmi < 40)
		cout << "Obese\n";
	else 
		cout << "Serious obesity\n";

	cout << "According to your height the bounds of normal weight are " << 18.5*height*height << " and " << 25*height*height << '\n'; /* Σύμφωνα με τον πίνακα τα όρια του BMI για φυσιολογικό βάρος είναι από 18.5 μέχρι 25. */
	return 0;
}

