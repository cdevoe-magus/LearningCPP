#pragma once

#include <string>
class Student {
private:
	int id;
	std::string name;

public:
	Student(int id_i, std::string name_i);
	void set_id(int id_n);
	int get_id();
	void set_name(std::string name_n);
	std::string get_name();
};