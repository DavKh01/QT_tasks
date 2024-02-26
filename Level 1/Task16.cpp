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
class Read {
public:
    Read(std::string filename) :read{ filename } 
    {
        if (!read.is_open()) {
            throw std::runtime_error("Couldn't open the file");
        }
        int num = 0;
        while (read >> num && !read.eof()) {
            array.push_back(num);
        }
    }
    std::vector<int> get_array() const {
        return array;
    }
    ~Read() {
        read.close();
    }
private:
    std::ifstream read;
    std::vector<int> array;
};
class Write {
public:
    Write(std::vector<int>& array) : write{ "sorted.txt" } {
        if (!write.is_open()) {
            throw std::runtime_error("Couldn't open the file");
        }
        for (int i : array) {
            write << i << " ";
        }
    }
    ~Write() {
        write.close();
    }
private:
    std::ofstream write;
};
class SortingAplication {
public:
    void execution(std::string input, int variant) {
        Read read(input);
        std::vector<int> arr = read.get_array();
        switch (variant) {
        case 1: {
            Insertion_sort ins;
            ins.sort(arr);
            Write write(arr);
            break;
        }
        case 2: {
            Bubble_sort bub;
            bub.sort(arr);
            Write write(arr);
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