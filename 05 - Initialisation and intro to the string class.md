```C++
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	// In C++, variables are strongly typed and must be initialised.
	// Three methods of initialising a variable

	// 1. C-like
	int x = 4;

	// 2. Contructor
	int y (4);

	// 3. Uniform initialisation
	int z {4};

	cout << "x is " << x << endl;
	cout << "y is " << y << endl;
	cout << "z is " << z << endl;

	// The string class is a wrapper of char* that adds functionality
	string str1 = "Hello";
	string str2 ("Hi there");
	string str3 {"What's up?"};

	// ::size() returns the length if the string
	cout << "str1 is \"" << str1 << "\" and is " << str1.size() 
		<< " chars long" << endl;
		
	// ::find() returns the position of its argument in the string as an int
	cout << "str2 is \"" << str2 << "\" and the word \"there\" is found at index"
		<< str2.find("there") << endl;

	// The addition operator (and all comparison operators) are overloaded for strings
	cout << "str2 + str3 = " << str2 + str3 << endl;

	if(str1 == "Hello") {
		cout << "str1 is Hello" << endl;
		}
		else {
		cout << "str1 is not Hello" << endl;
		}

	// Swapping two strings
	cout << "swapping str2 and str3:" << endl;
	str2.swap(str3);
	cout << "str2: " << str2 << endl;
	cout << "str3: " << str3 << endl;

	// You can also index into a string
	for (int i = 0; i < str2.size(); i++) {
		cout << "[" << str2[i] << "] ";
	}
	cout << endl;
}
```

