//the main point of interaction with the grade system

#include <iostream>
#include "StudentRecords.h"
#include <fstream>

StudentRecords SR;
int main() {
	int strt_code = SR.init("students.txt","courses.txt","grades.txt");
	if (strt_code != 0) {
		return strt_code;
	}
	std::string input;
	std::cout << "Select a report card mode: single or all." << std::endl;
	//std::getline(std::cin, input);
	std::getline(std::cin, input);
	if (input.compare("all") == 0) {
		std::cout << "Writing report cards to reportcards.txt.";
		SR.write_rcards();
	}
	else if (input.compare("single") == 0) {
		int id;
		std::cout << "Who's report card do you want? Please give their ID." << std::endl;
		std::cin >> id;
		std::cout << SR.report_card(id);
	}
	else {
		std::wcout << "Invalid mode.";
	}
	
	return 0;
}