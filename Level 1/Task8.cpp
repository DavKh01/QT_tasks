#include <iostream>
#include <iomanip>
enum Days {
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};
struct Date  {
	std::string day = "24";
	std::string month = "02";
	std::string year = "2024";
};
int main() {
	Date date;
	Days day;
    int weekday = 4;
	std::cout <<"Today is:\n" << date.day << "/" << date.month << "/" << date.year << ' ';
    switch (weekday) {
    case Monday:
        std::cout << "Monday";
        break;
    case Tuesday:
        std::cout << "Tuesday";
        break;
    case Wednesday:
        std::cout << "Wednesday";
        break;
    case Thursday:
        std::cout << "Thursday";
        break;
    case Friday:
        std::cout << "Friday";
        break;
    case Saturday:
        std::cout << "Saturday";
        break;
    case Sunday:
        std::cout << "Sunday";
        break;
    default:
        std::cout << "Invalid day";
        break;
    }
    std::cout << std::endl;
}