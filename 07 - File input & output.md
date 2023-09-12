```C++
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void) {
	// This declares and opens the input file stream
	ifstream inFile("test.txt");

	// This separates declaration and opening
	ofstream outFile;
	outFile.open("out.txt");

	// Copy the inFile to the outFile
	string line;
	while (getline(inFile, line)) {
		outFile << line << endl;
	}
	cout << "text.txt copied to out.txt" << endl;

	// Always close the files after use
	inFile.close();
	outFile.close();
	return 0;
}
```

```C++
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void) {
	ifstream numberFile("numbers.txt");

	float currentNumber;
	float average;

	int count = 0;

	while (numberFile >> currentNumber) {
		count++;
		average += currentNumber;
	}
	average /= count;

	cout << "The average of the " << count << " numbers in numbers.txt is" <<
		average << endl;

	numberFile.close();
	return 0;
}
```