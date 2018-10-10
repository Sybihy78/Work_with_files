#include <iostream>
#include <fstream>
#include <string>
#include <clocale>


void get_a_in_string(const std::string& path) {

	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File not found" << std::endl;
		return;
	}

	std::ofstream output;
	output.open("res_input_6.txt");
	if (!output.is_open()) {
		return;
	}

	std::string str;
	int number_string = 0;
				
	while (std::getline(input, str)) {
		
		++number_string;
		output << number_string << '\t';
		int sum = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == 'à') {
				++sum;
			}
		}
		output << sum << '\n';
	}
		
	output.close();
	input.close();
}


int main() {

	setlocale(LC_ALL, "Russian");

	std::string filename = "input_2.txt";
	get_a_in_string(filename);

	system("pause");
	return 0;
}