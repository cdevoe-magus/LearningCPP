//the main point of interaction with the grade system

#include <iostream>
#include "StudentRecords.h"

StudentRecords SR;
int main() {
	SR.init();
	int id;
	std::cout << "Who's report card do you want? Please give their ID."<< std::endl;
	std::cin >> id;
	SR.report_card(id);
	return 0;
}