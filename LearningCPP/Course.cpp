//a class representing a course
#include <string>
#include "Course.h"
	
	Course::Course(int id_i, std::string name_i, int cred_i) {
		id = id_i;
		name = name_i;
		credit = cred_i;
	}
	void Course::set_id(int id_n) {
		id = id_n;
	}
	int Course::get_id() {
		return id;
	}
	void Course::set_name(std::string name_n) {
		name = name_n;
	}
	std::string Course::get_name() {
		return name;
	}
	void Course::set_cred(int cred_n) {
		credit = cred_n;
	}
	int Course::get_cred() {
		return credit;
	}