#include <iostream> // ’σκηση 14.9
#include <string>
using std::cout;
using std::cin;
using std::string;

struct Node 
{
	string name;
	int code;
	float grd; 
	Node *next; 
};

Node *head; /* Καθολική μεταβλητή που δείχνει πάντα στην αρχή της ουράς. */
Node *tail; /* Καθολική μεταβλητή που δείχνει πάντα στον τελευταίο κόμβο της ουράς. */

void add_queue(const Node *p);
void show_queue();
void pop();
void free_queue();

int main()
{
	int sel; 
	Node n;

	head = nullptr; 
	while(1) 
	{
		cout << "\nMenu selections\n";
		cout << "---------------\n";
		cout << "1. Add student\n";
		cout << "2. View all students\n";
		cout << "3. View last student\n";
		cout << "4. Delete top student\n";
		cout << "5. Exit\n";

		cout << "\nEnter choice: ";
		cin >> sel;

		switch(sel)
		{
			case 1:
				cin.get();

				cout << "Name: ";
				getline(cin, n.name);
				
				cout << "Code: ";
				cin >> n.code;

				cout << "Grade: "; 
				cin >> n.grd;

				add_queue(&n);
			break;

			case 2:
				if(head != nullptr)
					show_queue();
				else
					cout << "\nThe queue is empty\n";
			break;

			case 3:
				if(head != nullptr)
					cout << "\nC:" << tail->code << " N:" << tail->name << " G:" << tail->grd << '\n';
				else
					cout << "\nThe queue is empty\n";
			break;

			case 4:
				if(head != nullptr)
					pop();
				else
					cout << "\nThe queue is empty\n";
			break;

			case 5:
				if(head != nullptr)
					free_queue();
			return 0; 


			default:
				cout << "\nWrong choice\n";
			break;
		}
	}
	return 0;
}

void add_queue(const Node *p)
{
	Node *new_node;

	new_node = new Node;
	*new_node = *p;
	new_node->next = nullptr; 

	if(head == nullptr)  
		head = tail = new_node; /* Αν η ουρά είναι άδεια, οι δείκτες head και tail θα δείχνουν στον νέο κόμβο. */
	else
	{
		tail->next = new_node; /* Ο νέος κόμβος εισάγεται στο τέλος της ουράς μέσω του δείκτη next. */
		tail = new_node; /* Τώρα, ο δείκτης tail δείχνει στον νέο τελευταίο κόμβο. */
	}
}

