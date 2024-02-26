#include <iostream>
#include <vector>
#include <fstream>
void insertion_sort(std::vector<int>);
void selection_sort(std::vector<int>);

struct SortingOption
{
	enum sortingStrategy {
		INSERTION_SORT = 1,
		SELECTION_SORT
	};
	void (*fptr[2])(std::vector<int>);
};
std::vector<int> read_from_file() {
	std::ifstream read("array.txt");
	if (!read) {
		std::cerr << "couldn't open the file";
		exit(1);
	}
	int num = 0;
	std::vector<int> array;
	while (read >> num && !read.eof()) {
		array.push_back(num);
	}
	read.close();
	return array;
}
void write_to_file(std::vector<int> array) {
	std::ofstream write("array.txt");
	if (!write) {
		std::cerr << "couldn't open the file";
		exit(1);
	}
	for (int i : array) {
		write << i << " ";
	}
	write.close();
}
int main() {
	SortingOption obj;
	obj.fptr[0] = insertion_sort;
	obj.fptr[1] = selection_sort;
	std::vector<int> array = read_from_file();
	int variant = 0;
	std::cout << "enter sorting algorithm.\n 1)insertion\n 2)selection\n";
	std::cin >> variant;
	switch (variant)
	{
	case obj.INSERTION_SORT:
		obj.fptr[0](array);
	case obj.SELECTION_SORT:
		obj.fptr[1](array);
	default:
		break;
	}
	std::cout << "the sorted array\n";
	for (int i = 0; i < array.size(); ++i) {
		std::cout << array[i] << " ";
	}
}
void insertion_sort(std::vector<int> arr) {
	for (int i = 1; i < arr.size(); ++i) {
		int k = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > k) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = k;
	}
}
void selection_sort(std::vector<int> arr) {
	for (int i = 0; i < arr.size() - 1; ++i) {
		int index = i;
		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[j] < arr[index]) {
				index = j;
			}
		}
		std::swap(arr[i], arr[index]);
	}
}