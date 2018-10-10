#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>


void get_different_words(const std::string& path) {

	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File not found" << std::endl;
		return;
	}

	std::string tmp;
	std::vector<std::string> vec;

	while (input >> tmp) {
		vec.push_back(tmp);
	}

	std::ofstream output;
	output.open("res_input_4.txt");
	if (!output.is_open()) {
		return;
	}
		
	for (int i = 0; i < vec.size(); ++i) {
		int sum = 0;
		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[i] != vec[j]) {
				++sum;
			}
			else {
				break;
			}
		}
		if (sum == vec.size() - (i + 1)) {
			output << vec[i] << '\n';
		}
	}
	
	output.close();
	input.close();
}


int main() {

	setlocale(LC_ALL, "Russian");

	std::string filename = "input_2.txt";
	get_different_words(filename);

	system("pause");
	return 0;
}