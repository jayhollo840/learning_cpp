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

```
```C
#include <stdint.h>

uint32_t packData(unsigned char oneByte, uint64_t threeBytes) {
    // Mask the lower 3 bytes of the threeBytes data
    uint32_t maskedThreeBytes = (uint32_t)(threeBytes & 0xFFFFFF);

    // Shift the oneByte to the left by 24 bits to make room for the 3-byte data
    uint32_t shiftedOneByte = ((uint32_t)oneByte) << 24;

    // Combine the two parts together
    uint32_t result = shiftedOneByte | maskedThreeBytes;

    return result;
}

#include <stdint.h>

uint32_t insertThreeBytes(uint32_t originalValue, uint64_t lowerThreeBytes) {
    // Mask out the lower 3 bytes from the uint64_t value
    uint32_t maskedLowerThreeBytes = (uint32_t)(lowerThreeBytes & 0xFFFFFF);

    // Clear the lower 3 bytes of the original uint32_t value
    originalValue &= 0xFF000000;

    // Combine the two values
    originalValue |= maskedLowerThreeBytes;

    return originalValue;
}

```
