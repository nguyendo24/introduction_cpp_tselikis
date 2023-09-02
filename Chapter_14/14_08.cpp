#include <iostream> // ������ 14.8
#include <string>
using std::cout;
using std::cin;
using std::string;

struct Node
{
	string name; 
	int code;
	float grd; 
	Node *next; /* ������� ���� ������� ����� ��� �������. ����� �� ����������� ��� ��������, ���� �� �������� �� ��������� ��� ���� ��� ������. */
};

Node *head; /* �������� ��������� ��� ������� ����� ���� ������ ��� �������. */

void add_stack(const Node *p);
void show_stack();
void pop();
int size_stack();
void free_stack();

int main()
{
	int sel; 
	Node n;

	head = nullptr; /* ������ ���� ���� ������ head, � ����� ������� ��� � ������ ����� �����. */
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

	new_node = new Node; /* �������� ������ ��� �� ���������� ��� ���� ������. */
	*new_node = *p; /* ��������� ��� ��������� ��� ������� ���� ��� �����. */
	new_node->next = head; /* � ���� ������ ��������� ���� ���� ��� ������� ���� ��� ������ next. ��� ����������, ��� ����� ���� ��� ��������� ���� �������� � ���� ��� new_node->next ������� ��� �� ��� ������ ���� ��� head ��� ����� nullptr. */
	head = new_node; /* � ���� ������ ������� � ��� ������ ��� �������. */ 
}

void show_stack()
{
	Node *p;

	p = head; 
	cout << "\n***** Student Data *****\n\n";
	while(p != nullptr)
	{
		cout << "C:" << p->code << " N:" << p->name << " G:" << p->grd << '\n';
		p = p->next; /* �� ���� ���������, � p ������� ���� ������� �����. ���� � ���� ��� ����� ��� �� nullptr �������� ��� ��� ������� ����� ������ ��� � ������ ������������. */
	}
}

void pop()
{
	Node *p;

	p = head->next; /* � p ������� ���� ������� ����� ��� �������. ����� � ������ �� ����� � ��� ������. */
	cout << "\nStudent with code " << head->code << " is deleted\n";
	delete head; /* ����������� ������. � ���������� ��� �� ����� ����� � �������� ������ ��� ������, ����� ������������ ������������ ���� ������ p. */
	head = p; // ����, � head ������� ��� ��� ������ ��� �������. 
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
		num++; /* ���� � ��������� ������� ���� �������, ����� �� �������� ���� ��������� ����� ��� �������. */
	}
	return num;
}

void free_stack()
{
	Node *p, *next_node;

	p = head; 
	while(p != nullptr)
	{
		next_node = p->next; /* � next_node ������� ���� ����� ��� ����� ���� ��� ����� ��� �� ���������. */
		delete p; /* ����������� ������. � ���������� ��� �� ����� ����� � �������� ������ ��� ������, ����� ������������ ������������ ���� ������ next_node. */
		p = next_node; // ����, � p ������� ���� ������� �����. 
	}
}

