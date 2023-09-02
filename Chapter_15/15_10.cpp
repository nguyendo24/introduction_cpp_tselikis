#include <iostream> // ’σκηση 15.10

#define no_main(type, name, text, num) type name() \
{std::cout << text; return num;}

no_main(int, main, "No main()", 0)

