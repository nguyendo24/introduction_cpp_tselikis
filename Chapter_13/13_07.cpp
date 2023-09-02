#include <iostream> // ’σκηση 13.7
using std::cout;
using std::cin;

struct Coord 
{
	double x; // Τετμημένη σημείου. 
	double y; // Τεταγμένη σημείου. 
};

struct Rectangle 
{
	Coord point_A; // Πρώτο σημείο διαγωνίου. 
	Coord point_B; // Δεύτερο σημείο διαγωνίου. 
};

double rect_area(const Coord *c1, const Coord *c2); 

int main()
{
	Rectangle rect; 

	cout << "Enter the x and y coords of the first point: ";
	cin >> rect.point_A.x >> rect.point_A.y;

	cout << "Enter the x and y coords of the second point: ";
	cin >> rect.point_B.x >> rect.point_B.y;

	cout << "Area:" << rect_area(&rect.point_A, &rect.point_B) << '\n';
	return 0;
}

double rect_area(const Coord *c1, const Coord *c2)
{
	double base, height;

	if(c1->x > c2->x)
		base = c1->x - c2->x;
	else
		base = c2->x - c1->x;

	if(c1->y > c2->y)
		height = c1->y - c2->y;
	else
		height = c2->y - c1->y;

	return base*height; // Επιστροφή εμβαδού παρ/μου. 
}

