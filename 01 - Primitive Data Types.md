```c++
#include <iostream>

int main(void) {
	// Print data types and their sizes
	std::cout << "Primative data types and sizes in bytes:" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "char: " << sizeof(char) << std::endl;
	std::cout << "wchar_t: " << sizeof(wchar_t) << std::endl;
	std::cout << "short int" << sizeof(short int) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "long int: " << sizeof(long int) << std::endl;
	std::cout << "bool: " << sizeof(bool) << std::endl;
	std::cout << "float: " << sizeof(float) << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "long double: " << sizeof(long double) << std::endl;
	
	return 0;
}
```
