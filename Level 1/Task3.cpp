#include <iostream>

int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    }
    else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    }
    else {
        std::cout << "The number is zero." << std::endl;
    }

    char grade;
    switch (number) {
    case 90 ... 100:
        grade = 'A';
        break;
    case 80 ... 89:
        grade = 'B';
        break;
    case 70 ... 79:
        grade = 'C';
        break;
    case 60 ... 69:
        grade = 'D';
        break;
    default:
        grade = 'F';
    }

    std::cout << "Grade: " << grade << std::endl;

    std::cout << "Numbers from 1 to 10:" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
