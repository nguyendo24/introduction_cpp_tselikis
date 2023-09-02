#include <iostream> // ������ 14.10
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

Node *head; /* �������� ��������� ��� ������� ����� ���� ���� ��� ������. */
Node *tail; /* �������� ��������� ��� ������� ����� ���� ��������� ����� ��� ������. */

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
			case 2: /* ��� �� ���������� ��� ��������� ��� ����� ������, � �������� ��������� ������� ��� ���� case. ������� �� ��� ������� ��� ������, �������� ��� � ���������� ���������. */
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

/* ��� ��� �������� ��������� ��� add_list_end() ����� �� ������ ��� add_queue() ���� ����������� ������. */
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
	/* ����������� �� ����� ����� �� ������ ��� ����� �� ��� ������������ ������ �������. �� ������, � ���� ������ ����������� ���� ��� ����� ��� � ��������� ����������. */
	while(ptr != nullptr)
	{
		if(ptr->code == code)
		{
			new_node = new Node;
			*new_node = *p; /* ��������� ��� ��������� ��� �������. */  
			new_node->next = ptr->next; /* ����, � ���� ������ ������� ���� ����� ��� ������� � ������ ������. */
			ptr->next = new_node; /* ����, � ������ ������ ������� ���� ��� �����, � ������ ���� ����������� ��� �����. */
			if(ptr == tail) /* ��������� �� � ���� ������ ���������� ��� ����� ��� ������. �� ���, �������� �� ��� ���� ��� ������. */
				tail = new_node;
			return;
		}
		ptr = ptr->next; // ��������� ��� ������� �����. 
	}
	/* �� � ������� ������ �� ���� �� ������ �������� ��� ��� ������� ������ ��� ����� ��� �� ���� ���� ������ ������� �� ���� ��� �������� � �������. */
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
	Node *p, *prev_node; /* � ������� prev_node �� ������� ���� ����������� ����� ��� ����� ��� �� �����������. */

	p = prev_node = head;
	while(p != nullptr)
	{
		if(p->code == code)
		{
			if(p == head) 
				head = p->next; /* �� � ������ ����� � ������ ��� ������, ���� � �������� ������ ������� � ��� ������. �� ��� ������� �������� ������, ������ � ����� �������� ���� ��� ������, ���� � ���� ��� ������ head �� ����� ��� �� nullptr. */
			else
			{
				/* ����, � p ������� ���� ����� ��� �� ��������� ��� � ������� prev_node ���� �����������. � ������� ������ ������� ��� ����������� ����� �� ��� ������� ��� ����� ��� �� ���������. */
				prev_node->next = p->next;
				if(p == tail) /* ��������� �� � ������ ��� �� ����������� ����� � ���� ��� ������. �� �����, � ������������ ��� ������� � ��� ���� ��� ������. */
					tail = prev_node;
			}
			delete p; // �������� ������. 
			return 0;
		}
		prev_node = p; /* ����, � prev_node ������� ���� ����� ��� ����� �������� ��� ������������ ��� ��� ���� ��� ��������� ������ �������. */
		p = p->next; /* ����, � p ������� ���� ������� �����. ��������� ��� � prev_node ������� ����� ���� ����������� ����� ��� ����� ��� ���������. */
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

