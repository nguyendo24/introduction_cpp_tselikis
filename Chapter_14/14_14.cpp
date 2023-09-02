void tree_nodes(Node *p) // ’σκηση 14.14
{
	if(p == nullptr) 
		return;
	cnt++;
	tree_nodes(p->left);
	tree_nodes(p->right);
}

