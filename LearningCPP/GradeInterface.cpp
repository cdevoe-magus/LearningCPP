//the main point of interaction with the grade system

#include <iostream>
#include "GPA.h"

int main() {
	int id;
	std::cout << "Who's GPA do you want to calculate. Please give their ID."<< std::endl;
	std::cin >> id;
	GPA(id);
	return 0;
}