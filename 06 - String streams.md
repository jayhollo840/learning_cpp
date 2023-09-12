```C++
#include <iostream>
#include <sstream>
using namespace std;

int main(void) {
	stringstream stream;
	char anme[10];
	cout << "What is your name?";
	cin >> name;
	stream << "Hello, " << name << endl;
	// Or getting the same by using .str()
	cout << stream.str();

	// Get 5 intergers from the user
	int numArray[5];
	stringstream numStream;
	cout << "Enter five ints, separated by spaces: ";
	for (int i = 0; i < 5; i++) {
		cin >> numArray[i];
		cumSteam << numArray[i] << " ";
	}
	cout << "You entered " << numStream.str() << endl;
}
```