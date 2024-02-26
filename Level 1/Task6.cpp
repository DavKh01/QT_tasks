#include <iostream>
int main() {
	int val = 6;
	int& ref = val;
	int* ptr = &val;
	ref = *ptr * val;
	std::cout << val << "\n";
}