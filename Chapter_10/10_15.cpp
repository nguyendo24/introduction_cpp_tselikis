#include <iostream> // Άσκηση 10.15
#include <cstring> 
int main()
{
	char str[] = "csfbl", *p = str;

	while(*p)
	{
		--*p; /* Για μεγαλύτερη δυσκολία, θα μπορούσα να ενώσω τις δύο εντολές σε --*p++;. */
		p++;
	}
	std::cout << p-strlen(str) << '\n';
	return 0;
}

