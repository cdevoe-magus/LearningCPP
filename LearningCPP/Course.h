#pragma once

#include <string>
class Course {
private:
	int id;
	std::string name;
	int credit;

public:
	Course(int id_i, std::string name_i, int cred_i);
	void set_id(int id_n);
	int get_id();
	void set_name(std::string name_n);
	std::string get_name();
	void set_cred(int cred_n);
	int get_cred();
};