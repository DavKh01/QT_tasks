#include <iostream>
#include <fstream>
#include<vector>
#include <string>
int main() {
	std::string filename;
	std::cout << "enter the file name: ";
	std::cin >> filename;
	std::ofstream write(filename);
	if (!write) {
		std::cerr << "couldn't open the file";
		return 1;
	}
	std::vector<std::string> names = { "Tom","Andrey","Gago","Cesar","Antonio" };
	for (std::string s : names) {
		write << s << "\n";
	}
	write.close();
	std::ifstream read(filename);
	if (!read) {
		std::cerr << "couldn'topen the file";
		return 1;
	}
	std::string nm;
	while (std::getline(read, nm)) {
		std::cout << nm << "\n";
	}
	read.close();
}