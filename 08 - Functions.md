```C++
#include <iostream>
#include <string>
using namespace std;

// No parameters, no return
void f(void) {
	cout << "function f()" << endl;
}
// Parameters, no return
void g(int i, int j) {
	cout << "function g(" << i << j << "). sum of parameters is " << i + j << endl;
}
// No parameters, retunr value
float k(void) {
	cout << "function k()" << endl;
	return 42.42;
}
// Parameter, a return value
int l(float a) {
	cout << "function l(" << a << ")" << ednl;
	return (int) a;
}

// Reference parameters (note C++ uses the address of instead of pointing to)
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = teamp;
}

string add(string& a, string& b) {
	return a + b;
}

// The above references could be altered. The below, will not change the variables.
string first(const string& a, const string& b) {
	if (a > b) return b;
	else return a;
}

int main(void) {
	f();
	g(1, 2);
	cout << k() << endl;
	cout << l(4.2) << endl << endl;

	int i = 5, j = 9;
	cout << "Before swap, i = " << i << ", j = " << j << endl;
	swap(i, j);
	cout << "After swap, i = " << i << ", j = " << j << endl;

	string one("This is the first string ");
	string two("and this is the second string.");
	cout << add(one, two) << endl << endl;

	cout << "First of (one, two) is: " << first(one, two) << endl;
}
```

#### Without function templates (Bad coding)

```C++
#include <iostream>
#include <string>
using namespace std;

int addi(int a, int b) {
	return a + b;
}

int addf(float a, float b) {
	return a + b;
}

string adds(string a, string b) {
	return a + b;
}

int main(void) {
	string str1("abcde");
	string str2("fghijk");
	cout << adds(str1, str2) << endl;
	cout << addf(4.3, 2,57) << "\n";
	cout << addi(5, 9) << "\n";

	return 0;
}
```

#### With function templates (Good coding)

```C++
#include <iostream>
#include <string>
using namespace std;

// Function templates can be declared so that it can be used by different data types.
template <typename T>
T add(T a, T b) {
	return a + b;
}

// Templates must be instantiated, either explicitly or implicitly (implied by the compiler in the same code).
int main(void) {
	// Call on different types, using implicit instantiation.
	// Add two ints
	cout << "1 + 2 = " << add(1, 2) << endl;
	// Add two floats
	cout << "4.3 + 3.9" << add(4.3, 3.9) << endl;
	// Add two bools
	cout << "true + false = " << add(true, false) << endl;
	// Add two strings
	string str1("Hello");
	string str2("World");
	cout << "\"" << str1 << "\" + \"" < str2 << "\"" << add(str1, str2) << endl;

	return 0;
}
```

#### Explicit function template instantiation

C++ Header file (Can have either be a .h, .hpp or no extension)
```C++
// multiply.hpp
// Defines a function for multiplication

template <typename T>
T mult(T a, T b) {
	return a * b;
}
// Explicitly define mult over int and float
template int mult<int> (int, int);
template float mult<> (float, float);
// You can use empty angle brackets if the comipler could implicitly determine the type

```

```C++
#include <iostream>
#include <string>
#include "multiply.hpp"
using namespace std;

int main(void) {
	// Explicitly defined functions in "multiply.hpp"
	cout << "3 * 2 = " << mult(3, 2) << "\n";
	cout << "3.2 * 7.68 = " << mult(3.2, 7.68) << "\n";
	
	// Implicitly defined during compilation
	cout << "true * false = " << mult(true, false) << "\n";

	return 0;
}