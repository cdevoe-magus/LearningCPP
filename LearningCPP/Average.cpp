//Calculates the average of an array of numbers

#include <iostream>

int main() {
	const int cap = 5;
	int numbers[] = { 4,20,37,43,10 };
	float ave = (float)(numbers[0] + numbers[1] + numbers[2] + numbers[3] + numbers[4]) / cap;
	std::cout << "Your array is: " << numbers;
	std::cout << "The average is: " << ave;
	return 0;
}