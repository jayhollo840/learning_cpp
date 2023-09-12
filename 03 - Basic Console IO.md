C++ uses "streams", which are sequences of bytes.
The header file iostream defines four of these streams:
	`cout` - The C Output stream, corresponding to the screen by default.
	`cin` -  The C Input stream, corresponding to the keyboard by default.
	`cerr` - The C Error stream, used for unbuffered error output.
	`clog` - The C Log stream, used for buffered error output
`cout`, `cerr` and `clog` are all the instances of the ostream class (output).
`cin` is the instance of the istream class (input).

The overloaded stream insertion operator (<<, >>) is used to with streams to point in the direction the data is being sent.

```C++
#include <iostream>
using namespace std;

int main(void) {
	// A char array to hold the user's name
	char name[20];
	// Prompt for input
	cout << endl << "Hi, what is your name?";
	// Get the input
	cin >> name;
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
