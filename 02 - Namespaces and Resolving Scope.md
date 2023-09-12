This is how C++ should be written to access libraries or functions:
```C++
#include <iostream>

namespace I {
	int add(int a, int b) {
		return a + b;
	}
}
namespace F {
	float add(float a, float b) {
		return a + b;
	}
}
int main(void) {
	std::cout << "Hello World!" << std::endl;
	std::cout << "3 + 2 = " << I::add(3, 2) << std::endl;
	std::cout << "3.2 + 2.3 = " << F::add(3.2, 2.3) << std::endl;
	return 0;
}
```

Scope is defined with a double colon (::).  In this case, the `cout` and `endl` is using the std scope and I/F is using the function scope:
	`std::cout`
	`std::endl`
	`I::add`
	`F::add`

If you are going to re-use scope throughout your code, you can define the namespace at the head of the script.

```C++
#include <iostream>
using namespace std;

namespace I {
	int add(int a, int b) {
		return a + b;
	}
}
namespace F {
	float add(float a, float b) {
		return a + b;
	}
}
int main(void) {
	cout << "Hello World!" << endl;
	cout << "3 + 2 = " << I::add(3, 2) << endl;
	cout << "3.2 + 2.3 = " << F::add(3.2, 2.3) << endl;
	return 0;
}
```

Now that std has been defined/used as a namespace, there is no requirement to write `std::`
However, you can only define one namespace at a time.  So you can't name std and I or F together.  If you wanted to do that, you will need to continuously reassign the namespace.

```C++
#include <iostream>
using namespace std;

namespace I {
	int add(int a, int b) {
		return a + b;
	}
}
namespace F {
	float add(float a, float b) {
		return a + b;
	}
}
int main(void) {
	std::cout << "Hello World!" << std::endl;
	using namespace I;
	int result = add(3, 2);
	using namespace std;
	cout << "3 + 2 = " << result << endl;
	cout << "3.2 + 2.3 = " << F::add(3.2, 2.3) << endl;
	return 0;
}
```