#include <iostream>
#include <fstream>
#include <string>


void get_size(const std::string& path) {

	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File not found" << std::endl;
		return;
	}

	int x;
	int sum = 0;

	while (input >> x) {
		++sum;
	}
	std::cout << "SIZE = " << sum << std::endl;

	input.close();
}


void get_sort_numbers(const std::string& path) {

	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File not found" << std::endl;
		return;
	}

	const int SIZE = 1000;
	int arr[SIZE] = {};
		
	for (int i = 0; i < SIZE; ++i) {
		input >> arr[i];
	}
	
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	
	std::ofstream output;
	output.open("res_input_1.txt");
	if (!output.is_open()) {
		return;
	}
	
	for (int i = 0; i < SIZE; ++i) {
		output << arr[i] << '\n';
	}
	
	output.close();
	input.close();
}


int main() {

	std::string filename = "input_1.txt";
	get_size(filename);
	get_sort_numbers(filename);

	system("pause");
	return 0;
}