`cin` only gets data up to the first blank space. To get the entire line, you need to use the `getline` element of the `cin` function.

```shell
# Input
Hi, what is your name? John Doe

# Ouput
Hi, John
This is an error...
The contents of the name variable: John
```

```C++
#include <iostream>
using namespace std;

int main(void) {
	// A char array to hold the user's name
	char name[20];
	// Prompt for input
	cout << endl << "Hi, what is your name?";
	// Get the input
	cin.getline(name, 256);
	// Greet the user by name
	cout << "Hi, " << name << endl;

	// Unbuffered output to cerr will alway occur immediately.
	// It should be used for error messages.
	cerr << "This is an error..." << endl;

	// Buffered output to clog might not be displayed without flushing the buffer first.
	// It should be used for logging messages (such as logs for debugging).
	clog << "The contents of the name variable: " << name << endl;

	return 0;
}
```

```shell
# Input
Hi, what is your name?

# Output
Hi, John Doe
This is an error...
The contents of the name variable: John Doe
```