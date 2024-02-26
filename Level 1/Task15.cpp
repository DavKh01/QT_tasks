#include <iostream>
#include <vector>
#include <fstream>
class SortingStrategy {
public:
	virtual void sort(std::vector<int>& arr) = 0;
};

class Bubble_sort :public SortingStrategy {
public:
    void sort(std::vector<int>& arr) {
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

class Insertion_sort :public SortingStrategy {
public:
    void sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
};
class FileHandler {
public:
    std::vector<int> read_from_file(std::string input) {
        std::ifstream read(input);
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
    void write_to_file(std::vector<int>& array) {
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
};

class SortingAplication {
private:
    SortingStrategy* sorting;
    FileHandler obj;
    std::vector<int> arr;
public:
    void execution(std::string input, int variant) {
        switch (variant) {
        case 1: {
            Insertion_sort ins;
            arr = obj.read_from_file(input);
            ins.sort(arr);
            obj.write_to_file(arr);
            break;
        }
        case 2: {
            Bubble_sort bub;
            arr = obj.read_from_file(input);
            bub.sort(arr);
            obj.write_to_file(arr);
            break;
        }
        default:
            std::cerr << "Invalid choice!";
            break;
        }
    }
};
class UserChoice {
private:
    SortingAplication app;
public:
    void user_choice() {
        std::cout << "enter the filename(filename.txt): ";
        std::string input;
        std::cin >> input;
        int variant = 0;
        std::cout << "enter sorting algorithm.\n 1)insertion\n 2)bubble\n";
        std::cin >> variant;
        app.execution(input, variant);
    }

};
int main() {
    UserChoice ask;
    ask.user_choice();
}