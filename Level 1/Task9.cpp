#include <iostream>
void insertion_sort(int* arr, int size);
void selection_sort(int* arr, int size);

struct SortingOption
{
	enum sortingStrategy {
		INSERTION_SORT = 1,
		SELECTION_SORT
	};
	void (*fptr[2])(int* arr, int size);
};
int main() {
	SortingOption obj;
	obj.fptr[0] = insertion_sort;
	obj.fptr[1] = selection_sort;
	const int size = 10;
	int arr[size] = { 65,-89,95,45,78,5,3,0,2,4 };
	int variant = 0;
	std::cout << "enter sorting algorithm.\n 1)insertion\n 2)selection\n";
	std::cin >> variant;
	switch (variant)
	{
	case obj.INSERTION_SORT:
		obj.fptr[0](arr, size);
	case obj.SELECTION_SORT:
		obj.fptr[1](arr, size);
	default:
		break;
	}
	std::cout << "the sorted array\n";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
}
void insertion_sort(int* arr, int size) {
	for (int i = 1; i < size; ++i) {
		int k = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > k) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = k;
	}
}
void selection_sort(int* arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int index = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[index]) {
				index = j;
			}
		}
		std::swap(arr[i], arr[index]);
	}
}