void find_min(Node *p) // ’σκηση 14.13
{
	if(p == nullptr) 
		return;
	if(p->left == nullptr)
	{
		cout << "Min:" << p->key << '\n';
		return;
	}
	find_min(p->left);
}

