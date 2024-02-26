#include <iostream>
#include <string>
class Book {
public:
	void set_name(std::string name) {
		m_name = name;
	}
	void set_author(std::string author) {
		m_author = author;
	}
	void set_ISBN(std::string ISBN) {
		m_ISBN = ISBN;
	}
	std::string get_name() const {
		return m_name;
	}
	std::string get_author() const {
		return m_author;
	}
	std::string get_ISBN() const {
		return m_ISBN;
	}
private:
	std::string m_name;
	std::string m_author;
	std::string m_ISBN;
};
int main() {

	Book my_book;

	my_book.set_name("1984");
	my_book.set_author("George Orwell");
	my_book.set_ISBN("978-0451524935");

	std::cout << "Book Name: " << my_book.get_name() << std::endl;
	std::cout << "Author: " << my_book.get_author() << std::endl;
	std::cout << "ISBN: " << my_book.get_ISBN() << std::endl;

	return 0;
}