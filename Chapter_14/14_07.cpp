#include <iostream> // ’σκηση 14.7
#include <cstring>
using std::cout;
using std::cin;

struct Publisher
{
	char *name;
	char *addr; 
	char *phone; 
};

struct Book
{
	char *title;
	char *auth;
	char *code;
	Publisher *pub_ptr; 
	float prc; 
};

int main()
{
	Book *books_ptr;
	char str[100];
	int i, num, len;

	cout << "Enter number of books: ";
	cin >> num;
	cin.get();

	books_ptr = new Book[num]; 
	for(i = 0; i < num; i++)
	{
		cout << "\nTitle: ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
		books_ptr[i].title = new char[len+1];
		strcpy(books_ptr[i].title, str);

		cout << "Authors: ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
		books_ptr[i].auth = new char[len+1];
		strcpy(books_ptr[i].auth, str);

		cout << "Code: ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
		books_ptr[i].code = new char[len+1];
		strcpy(books_ptr[i].code, str);

		cout << "Price: ";
		cin >> books_ptr[i].prc;

		cin.get();
		/* Δέσμευση μνήμης για την αποθήκευση των στοιχείων του εκδοτικού οίκου. */
		books_ptr[i].pub_ptr = new Publisher;

		cout << "Name: ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
		(books_ptr[i].pub_ptr)->name = new char[len+1];
		strcpy((books_ptr[i].pub_ptr)->name, str);

		cout << "Address: ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
		(books_ptr[i].pub_ptr)->addr = new char[len+1];
		strcpy((books_ptr[i].pub_ptr)->addr, str);

		cout << "Phone: ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
		(books_ptr[i].pub_ptr)->phone = new char[len+1];
		strcpy((books_ptr[i].pub_ptr)->phone, str);
	}
	cout << "\nEnter code to search: ";
	cin.getline(str, sizeof(str));

	for(i = 0; i < num; i++)
	{
		if(strcmp(books_ptr[i].code, str) == 0)
		{
			cout << "\nTitle:" << books_ptr[i].title << "\tPublisher:" << (books_ptr[i].pub_ptr)->name << '\n';
			break;
		}
	}
	if(i == num)
		cout << "\nCode isn't registered\n";

	for(i = 0; i < num; i++)
	{
		delete[] (books_ptr[i].pub_ptr)->name;
		delete[] (books_ptr[i].pub_ptr)->addr;
		delete[] (books_ptr[i].pub_ptr)->phone;

		delete[] books_ptr[i].title;
		delete[] books_ptr[i].auth;
		delete[] books_ptr[i].code;
		delete books_ptr[i].pub_ptr;
	}
	delete[] books_ptr;
	return 0;
}

