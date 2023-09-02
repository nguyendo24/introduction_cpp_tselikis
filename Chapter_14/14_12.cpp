#include <iostream> // ’σκηση 14.12

struct Node
{
	int i;
	Node *next; 
	Node *prev; 
};

int main()
{
	Node a = {10}, b = {20}, c = {30}, d = {40};

	a.next = &b;
	a.prev = &d;

	b.next = &c;
	b.prev = &a;

	c.next = &d;
	c.prev = &b;

	d.next = &a;
	d.prev = &c;
	std::cout << a.prev->prev->prev->next->i << '\n';
	return 0;
}

