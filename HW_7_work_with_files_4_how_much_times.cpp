#include <iostream>
#include <fstream>
#include <string>
#include <clocale>


void get_count_a(const std::string& path) {

	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File not found" << std::endl;
		return;
	}

	char tmp;
	int sum = 0;

	while (input.get(tmp)) {
		if (tmp == 'à') {
			++sum;
		}
	}
	
	std::ofstream output;
	output.open("res_input_5.txt");
	if (!output.is_open()) {
		return;
	}

	output << sum;
	output.close();
	input.close();
}


int main() {

	setlocale(LC_ALL, "Russian");

	std::string filename = "input_2.txt";
	get_count_a(filename);

	system("pause");
	return 0;
}