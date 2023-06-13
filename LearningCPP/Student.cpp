//a class representing a student
#include <string>
#include "Student.h"

	Student::Student(int id_i, std::string name_i) {
		id = id_i;
		name = name_i;
	}
	void Student::set_id(int id_n) {
		id = id_n;
	}
	int Student::get_id() {
		return id;
	}
	void Student::set_name(std::string name_n) {
		name = name_n;
	}
	std::string Student::get_name() {
		return name;
	}
	