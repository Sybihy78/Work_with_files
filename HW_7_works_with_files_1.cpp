#include <iostream>
#include <fstream>
#include <string>


void get_even_or_uneven(const std::string& path) {

	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "File not found" << std::endl;
		return;
	}
	
	int x;
	int sum_even = 0;
	int sum_uneven = 0;

	while (input >> x) { 
		if (x % 2 == 0) {
			++sum_even;
		}
		else {
			++sum_uneven;
		}
	}

	std::ofstream output;
	output.open("res_input_3.txt");
	if (!output.is_open()) {
		return;
	}

	if (sum_even > sum_uneven) {
		output << "Amount of even numbers is bigger uneven numbers:" << '\n';
		output << sum_even << " > " << sum_uneven;
	}
	else if (sum_even < sum_uneven) {
		output << "Amount of uneven numbers is bigger even numbers:" << '\n';
		output << sum_uneven << " > " << sum_even;
	}
	else {
		output << "Amount of even numbers is equal uneven numbers:" << '\n';
		output << sum_even << " = " << sum_uneven;
	}

	output.close();
	input.close();
}


int main() {

	std::string filename = "input_1.txt";
	get_even_or_uneven(filename);

	system("pause");
	return 0;
}