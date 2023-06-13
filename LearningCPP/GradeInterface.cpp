//the main point of interaction with the grade system

#include <iostream>
#include "StudentRecords.h"

StudentRecords SR;
int main() {
	SR.init();
	int id;
	std::cout << "Who's GPA do you want to calculate. Please give their ID."<< std::endl;
	std::cin >> id;
	SR.GPA(id);
	return 0;
}