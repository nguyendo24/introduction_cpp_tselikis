#include <iostream> // ’σκηση 14.10
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

Node *head; /* Καθολική μεταβλητή που δείχνει πάντα στην αρχή της λίστας. */
Node *tail; /* Καθολική μεταβλητή που δείχνει πάντα στον τελευταίο κόμβο της λίστας. */

void add_list_end(const Node *p);
void add_list(const Node *p, int code);
void show_list();
Node *find_node(int code);
int del_node(int code);
void free_list();

int main()
{
	int k, sel, code; 
	float grd;
	Node *p, n;

	head = nullptr; 
	while(1) 
	{
		cout << "\nMenu selections\n";
		cout << "---------------\n";

		cout << "1. Add student at the end\n";
		cout << "2. Add student\n";
		cout << "3. View all students\n";
		cout << "4. View student\n";
		cout << "5. Modify student\n";
		cout << "6. Delete student\n";
		cout << "7. Exit\n";

		cout << "\nEnter choice: ";
		cin >> sel;

		switch(sel)
		{
			case 1: 
			case 2: /* Για να αποφύγουμε την επανάληψη του ίδιου κώδικα, η εισαγωγή δεδομένων γίνεται στο ίδιο case. Ανάλογα με την επιλογή του χρήστη, καλείται και η αντίστοιχη συνάρτηση. */
				cin.get();

				cout << "Name: ";
				getline(cin, n.name);
			
				cout << "Code: ";
				cin >> n.code;

				cout << "Grade: "; 
				cin >> n.grd;
		
				if(sel == 1)
					add_list_end(&n);
				else
				{
					cout << "\nEnter student code after which the new student will be added: ";  
					cin >> code;
					add_list(&n, code);
				}
			break;

			case 3:
				if(head == nullptr)
					cout << "\nThe list is empty\n";
				else
					show_list();
			break;

			case 4:
				if(head == nullptr)
					cout << "\nThe list is empty\n";
				else
				{
					cout << "\nEnter student code to search: "; 
					cin >> code; 
					p = find_node(code);
					if(p != nullptr) 
						cout << "\nN:" << p->name << " G:" << p->grd << '\n';	
					else
						cout << "\nStudent with code " << code << " does not exist\n";
				}
			break;

			case 5:
				if(head == nullptr)
					cout << "\nThe list is empty\n";
				else
				{
					cout << "\nEnter student code to modify: "; 
					cin >> code; 
					
					cout << "Enter new grade: "; 
					cin >> grd; 
					p = find_node(code);
					if(p != nullptr)
						p->grd = grd;
					else
						cout << "\nStudent with code " << code << " does not exist\n";
				}
			break;

			case 6:
				if(head == nullptr)
					cout << "\nThe list is empty\n";
				else
				{
					cout << "\nEnter student code to delete: "; 
					cin >> code; 
					k = del_node(code); 
					if(k == 0)
						cout << "\nStudent with code " << code << " is deleted\n";
					else
						cout << "\nStudent with code " << code << " does not exist\n";
				}
			break;

			case 7:
				if(head != nullptr)
					free_list();
			return 0; 

			default:
				cout << "\nWrong choice\n";
			break;
		}
	} 
	return 0;
}

/* Για την καλύτερη κατανόηση της add_list_end() δείτε τα σχόλια της add_queue() στην προηγούμενη άσκηση. */
void add_list_end(const Node *p)
{
	Node *new_node;

	new_node = new Node;
	*new_node = *p;
	new_node->next = nullptr; 

	if(head == nullptr)  
		head = tail = new_node; 
	else
	{
		tail->next = new_node; 
		tail = new_node; 
	}
}

void add_list(const Node *p, int code)
{
	Node *new_node, *ptr;

	ptr = head; 
	/* Διατρέχουμε τη λίστα μέχρι να βρούμε τον κόμβο με τον συγκεκριμένο αριθμό μητρώου. Αν βρεθεί, ο νέος κόμβος προστίθεται μετά από αυτόν και η συνάρτηση τερματίζει. */
	while(ptr != nullptr)
	{
		if(ptr->code == code)
		{
			new_node = new Node;
			*new_node = *p; /* Αντιγραφή των στοιχείων του φοιτητή. */  
			new_node->next = ptr->next; /* Τώρα, ο νέος κόμβος δείχνει στον κόμβο που δείχνει ο τρέχων κόμβος. */
			ptr->next = new_node; /* Τώρα, ο τρέχων κόμβος δείχνει στον νέο κόμβο, ο οποίος έτσι προστίθεται στη λίστα. */
			if(ptr == tail) /* Ελέγχουμε αν ο νέος κόμβος προστέθηκε στο τέλος της λίστας. Αν ναι, αποτελεί τη νέα ουρά της λίστας. */
				tail = new_node;
			return;
		}
		ptr = ptr->next; // Ελέγχουμε τον επόμενο κόμβο. 
	}
	/* Αν ο κώδικας φτάσει σε αυτό το σημείο σημαίνει ότι δεν υπάρχει κόμβος στη λίστα που να έχει ίδιο αριθμό μητρώου με αυτό που εισήγαγε ο χρήστης. */
	cout << "\nStudent with code " << code << " does not exist\n";
}

void show_list()
{
	Node *p;

	p = head; 
	cout << "\n***** Student Data *****\n\n";
	while(p != nullptr)
	{
		cout << "Code:" << p->code << " Name:" << p->name << " Grade:" << p->grd << '\n';
		p = p->next; 
	}
}

Node *find_node(int code)
{
	Node *p;

	p = head; 
	while(p != nullptr)
	{
		if(p->code == code)
			return p;
		p = p->next; 
	}
	return nullptr;
}

int del_node(int code)
{
	Node *p, *prev_node; /* Ο δείκτης prev_node θα δείχνει στον προηγούμενο κόμβο από αυτόν που θα διαγράψουμε. */

	p = prev_node = head;
	while(p != nullptr)
	{
		if(p->code == code)
		{
			if(p == head) 
				head = p->next; /* Αν ο κόμβος είναι η κεφαλή της λίστας, τότε ο επόμενος κόμβος γίνεται η νέα κεφαλή. Αν δεν υπάρχει επόμενος κόμβος, δηλαδή η λίστα περιέχει μόνο την κεφαλή, τότε η τιμή του δείκτη head θα γίνει ίση με nullptr. */
			else
			{
				/* Τώρα, ο p δείχνει στον κόμβο που θα διαγραφεί και ο δείκτης prev_node στον προηγούμενο. Η επόμενη εντολή συνδέει τον προηγούμενο κόμβο με τον επόμενο από αυτόν που θα διαγραφεί. */
				prev_node->next = p->next;
				if(p == tail) /* Ελέγχουμε αν ο κόμβος που θα διαγράψουμε είναι η ουρά της λίστας. Αν είναι, ο προηγούμενός του γίνεται η νέα ουρά της λίστας. */
					tail = prev_node;
			}
			delete p; // Διαγραφή κόμβου. 
			return 0;
		}
		prev_node = p; /* Τώρα, ο prev_node δείχνει στον κόμβο που μόλις ελέγξαμε και διαπιστώσαμε ότι δεν έχει τον επιθυμητό αριθμό μητρώου. */
		p = p->next; /* Τώρα, ο p δείχνει στον επόμενο κόμβο. Σημειώστε ότι ο prev_node δείχνει πάντα στον προηγούμενο κόμβο από αυτόν που ελέγχουμε. */
	}
	return -1;
}

void free_list()
{
	Node *p, *next_node;

	p = head; 
	while(p != nullptr)
	{
		next_node = p->next; 
		delete p;
		p = next_node; 
	}
}

