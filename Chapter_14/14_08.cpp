#include <iostream> // ’σκηση 14.8
#include <string>
using std::cout;
using std::cin;
using std::string;

struct Node
{
	string name; 
	int code;
	float grd; 
	Node *next; /* Δείκτης στον επόμενο κόμβο της στοίβας. Δείτε τη χρησιμότητα της ετικέτας, ώστε να μπορούμε να δηλώσουμε τον τύπο του δείκτη. */
};

Node *head; /* Καθολική μεταβλητή που δείχνει πάντα στην κεφαλή της στοίβας. */

void add_stack(const Node *p);
void show_stack();
void pop();
int size_stack();
void free_stack();

int main()
{
	int sel; 
	Node n;

	head = nullptr; /* Αρχική τιμή στον δείκτη head, η οποία δηλώνει ότι η στοίβα είναι άδεια. */
	while(1) 
	{
		cout << "\nMenu selections\n";
		cout << "---------------\n";

		cout << "1. Add student\n";
		cout << "2. View all students\n";
		cout << "3. View top student\n";
		cout << "4. Delete top student\n";
		cout << "5. Number of students\n";
		cout << "6. Exit\n";

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

				add_stack(&n);
			break;

			case 2:
				if(head != nullptr)
					show_stack();
				else
					cout << "\nThe stack is empty\n";
			break;

			case 3:
				if(head != nullptr)
					cout << "\nC:" << head->code << " N:" << head->name << " G:" << head->grd << '\n';
				else
					cout << "\nThe stack is empty\n";
			break;

			case 4:
				if(head != nullptr)
					pop();
				else
					cout << "\nThe stack is empty\n";
			break;

			case 5:
				if(head != nullptr)
					cout << size_stack() << " students exist in stack\n";
				else
					cout << "\nThe stack is empty\n";
			break;

			case 6:
				if(head != nullptr)
					free_stack();
			return 0; 

			default:
				cout << "\nWrong choice\n";
			break;
		}
	}
	return 0;
}

void add_stack(const Node *p)
{
	Node *new_node;

	new_node = new Node; /* Δέσμευση μνήμης για τη δημιουργία του νέου κόμβου. */
	*new_node = *p; /* Αντιγραφή των στοιχείων του φοιτητή στον νέο κόμβο. */
	new_node->next = head; /* Ο νέος κόμβος εισάγεται στην αρχή της στοίβας μέσω του δείκτη next. Για παράδειγμα, την πρώτη φορά που εισάγεται ένας φοιτητής η τιμή του new_node->next γίνεται ίση με την αρχική τιμή του head που είναι nullptr. */
	head = new_node; /* Ο νέος κόμβος γίνεται η νέα κεφαλή της στοίβας. */ 
}

void show_stack()
{
	Node *p;

	p = head; 
	cout << "\n***** Student Data *****\n\n";
	while(p != nullptr)
	{
		cout << "C:" << p->code << " N:" << p->name << " G:" << p->grd << '\n';
		p = p->next; /* Σε κάθε επανάληψη, ο p δείχνει στον επόμενο κόμβο. Όταν η τιμή του γίνει ίση με nullptr σημαίνει ότι δεν υπάρχει άλλος κόμβος και ο βρόχος τερματίζεται. */
	}
}

void pop()
{
	Node *p;

	p = head->next; /* Ο p δείχνει στον επόμενο κόμβο της στοίβας. Αυτός ο κόμβος θα γίνει η νέα κεφαλή. */
	cout << "\nStudent with code " << head->code << " is deleted\n";
	delete head; /* Αποδέσμευση μνήμης. Η πληροφορία για το ποιος είναι ο επόμενος κόμβος δεν χάθηκε, γιατί αποθηκεύτηκε προηγουμένως στον δείκτη p. */
	head = p; // Τώρα, ο head δείχνει στη νέα κεφαλή της στοίβας. 
}

int size_stack()
{
	Node *p;
	int num;

	num = 0; 
	p = head; 
	while(p != nullptr)
	{
		p = p->next;
		num++; /* Αυτή η μεταβλητή μετράει τους κόμβους, μέχρι να φτάσουμε στον τελευταίο κόμβο της στοίβας. */
	}
	return num;
}

void free_stack()
{
	Node *p, *next_node;

	p = head; 
	while(p != nullptr)
	{
		next_node = p->next; /* Ο next_node δείχνει στον κόμβο που είναι μετά από αυτόν που θα διαγραφεί. */
		delete p; /* Αποδέσμευση μνήμης. Η πληροφορία για το ποιος είναι ο επόμενος κόμβος δεν χάθηκε, γιατί αποθηκεύτηκε προηγουμένως στον δείκτη next_node. */
		p = next_node; // Τώρα, ο p δείχνει στον επόμενο κόμβο. 
	}
}

