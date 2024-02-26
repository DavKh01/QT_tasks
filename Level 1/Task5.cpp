#include <iostream>
int min(int arr[], int size);
int max(int arr[], int size);
double average(int arr[], int size);
int strlen(char* str) {
	int i = 0;
	while (str[i]) { ++i; }
	return i;
}
void strcat(char* str1, char* str2) {
	char* ptr = str1 + strlen(str1);
	int i = 0;
	while (str2[i]) {
		ptr[i] = str2[i];
		++i;
	}
}

int main() {
	int size = 0;
	int arr[20];
	do {
		std::cout << "enter the size(max size is 20): ";
		std::cin >> size;
	} while (size < 1 || size > 20);
	for (int i = 0; i < size; ++i) {
		std::cout << "enter element: ";
		std::cin >> arr[i];
	}
	std::cout << "minimum - " << min(arr, size)<< '\n';
	std::cout << "maximum - " << max(arr, size) << '\n';
	std::cout << "average - " << average(arr, size) << '\n';

	char str1[20] = "Hello";
	char str2[20] = "World";
	strcat(str1, str2);
	std::cout << str1;
}
int min(int arr[], int size) {
	int min = arr[0];
	for (int i = 1; i < size; ++i) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}
int max(int arr[], int size) {
	int max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}
double average(int arr[], int size) {
	double sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum / size;
}