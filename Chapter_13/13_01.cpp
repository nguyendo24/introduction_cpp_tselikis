#include <iostream> // ’σκηση 13.1

struct Student
{
	char name[50];
	int code;
	float grd;
};

Student *test(), st; 

int main()
{
	Student stud = {"somebody", 1111, 7.5}, *ptr = &stud;

	*ptr = *test();
 std::cout << ptr->name << ' ' << ptr->code << ' ' << ptr->grd << '\n';
	return 0;
}

Student *test()
{
	return &st;
}

