int swap(int code_a, int code_b) // ’σκηση 14.11 
{
	Node *p, *tmp1, *tmp2;
	float grd;

	p = head; 
	tmp1 = tmp2 = nullptr;
	while(p != nullptr)
	{
		if(p->code == code_a)
			tmp1 = p;
		else if(p->code == code_b)
			tmp2 = p;
 
		if(tmp1 && tmp2)
		{
			grd = tmp1->grd;
			tmp1->grd = tmp2->grd;
			tmp2->grd = grd;
			return 0;
		}
		p = p->next;
	}
	return -1;
}

