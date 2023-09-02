Node* add_node(Node *p, char key[]) // ’σκηση 14.15
{
	int tmp;

	if(p == nullptr)
	{
		p = new Node;
		p->key = new char[strlen(key)+1];
		strcpy(p->key, key);
		p->left = p->right = nullptr;
	}
	else	
	{
		tmp = strcmp(key, p->key); /* Σύγκριση με το κλειδί του κόμβου. */
		if(tmp < 0)
			p->left = add_node(p->left, key);
		else if(tmp > 0)
			p->right = add_node(p->right, key);
		else
			cout << "Error: Key(" << key << ") exists\n";
	}
	return p;
}

void delete_tree(Node *p)
{
	if(p == nullptr)
		return;
	delete_tree(p->left);
	delete_tree(p->right);
	cout << p->key << '\n';
	delete p->key;
	delete p;
}

