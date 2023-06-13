//A GPA calculator, formula: total(score*hours)/total hours
#include <string>
#include "Course.h"
#include "Student.h"
#include "Grade.h"
#include <vector>
#include <iostream>
#include "StudentRecords.h"
#include <fstream>

std::vector<Student> students;
std::vector<Course> courses;
std::vector<Grade> grades;



float StudentRecords::get_grade_value(char grade) {
	switch (grade) {
	case 'A':
		return 4.0f;
		break;
	case 'B':
		return 3.0f;
		break;
	case 'C':
		return 2.0f;
		break;
	case 'D':
		return 1.0f;
		break;
	default:
		return 0.0f;
		break;
	}
}
std::string StudentRecords::get_student_name(int id) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].get_id() == id) {
			//sd_id = students[i].get_id();
			return students[i].get_name();
		}
	}
	return "none";
}
void StudentRecords::add_Student(int id, std::string name) {
	students.push_back(Student(id, name));
}

void StudentRecords::add_Course(int id, std::string name, int credits) {
	courses.push_back(Course(id, name, credits));
}

void StudentRecords::add_Grade(int s_id, int c_id, char letter) {
	grades.push_back(Grade(s_id,c_id,letter));
}

std::string StudentRecords::list_student_grades(int id) {
	std::string out = "";
	for (Grade& g: grades) {
		if (g.get_student_id() == id) {
			out.append( StudentRecords::get_course_name(g.get_course_id()) + ": " + g.get_grade() + "\n");
		}
	}
	return out;
}

std::string StudentRecords::get_course_name(int id) {
	for (Course c : courses) {
		if (c.get_id() == id) {
			return c.get_name();
		}
	}
}
float StudentRecords::GPA(int id) {
	float gpa = 0.0f;
	int creds = 0;
	//int sd_id = -1;
	std::string sd_name;
	sd_name = get_student_name(id);
	if (sd_name.compare("none") != 0) {
		for (Grade& g : grades) {
			if (g.get_student_id() == id) {
				for (Course& c : courses) {
					if (g.get_course_id() == c.get_id()) {
						gpa += StudentRecords::get_grade_value(g.get_grade()) * c.get_cred();
						creds += c.get_cred();
					}
					//std::cout << gpa << std::endl;
				}
			}
		}
		if (creds > 0) {
			//std::cout << creds << std::endl;
			gpa = gpa / creds;
			//std::cout << sd_name << "'s gpa is: " << gpa << std::endl;
			return gpa;
		}
		else {
			return 0.0f;
		}
		//std::cout << sd_name << "'s gpa is: " << gpa << std::endl;
		//return gpa;
	}
	else {
		std::cout << "Student not found.";
		return gpa;
	}
	//return gpa;
}

std::string StudentRecords::report_card(int id) {
	std::string out = StudentRecords::get_student_name(id);
	//std::cout << out;
	float gpa = 0.0f;
	if (out.compare("none") != 0) {
		/*std::cout << st_name << std::endl;
		StudentRecords::list_student_grades(id);
		std::cout << "GPA: " << StudentRecords::GPA(id) << std::endl;
		*/
		gpa = StudentRecords::GPA(id);
		out += "\n" + StudentRecords::list_student_grades(id);
		out += "GPA: ";
		//std::cout << gpa;
		out += std::to_string(gpa);
		out += "\n";
		return out;
	}
	else {
		//std::cout << "Student not found.";
		return "Student not found.";
	}
	
}

void StudentRecords::write_rcards() {
	std::ofstream writer;
	writer.open("reportcards.txt");
	if (writer.fail()) {
		std::cout << "Could not write to reportcards.txt" << std::endl;
	}
	else {
		for (Student s : students) {
			writer << StudentRecords::report_card(s.get_id());
		}
		writer.close();
	}
}

int StudentRecords::init(std::string st_file, std::string cour_file, std::string grad_file) {
	std::ifstream reader;
	reader.open(st_file);
	if (reader.fail()) {
		std::cout << "Failed to read student file.";
		return 1;
	}
	else {
		while (!reader.eof()) {
			std::string in;
			std::getline(reader, in);
			int id = std::stoi(in);
			std::getline(reader, in);
			add_Student(id, in);
		}
		reader.close();
	}
	reader.open(grad_file);
	if (reader.fail()) {
		std::cout << "Failed to read grade file.";
		return 1;
	}
	else {
		while (!reader.eof()) {
			std::string in;
			std::getline(reader, in);
			int s_id = std::stoi(in);
			std::getline(reader, in);
			int c_id = std::stoi(in);
			std::getline(reader, in);
			add_Grade(s_id, c_id, in[0]);
		}
		reader.close();
	}
	reader.open(cour_file);
	if (reader.fail()) {
		std::cout << "Failed to read course file.";
		return 1;
	}
	else {
		while (!reader.eof()) {
			std::string in;
			std::string name;
			std::getline(reader, in);
			int id = std::stoi(in);
			std::getline(reader, name);
			std::getline(reader, in);
			int creds = std::stoi(in);
			add_Course(id, name, creds);
		}
		reader.close();
	}
	return 0;
	/*add_Student( 1, "George P. Burdell");
	add_Student(2, "Nancy Rhodes");
	add_Course(1, "Algebra", 5);
	add_Course(2, "Physics", 4);
	add_Course(3, "English", 3);
	add_Course(4, "Economics", 4);
	add_Grade(1, 1, 'B');
	add_Grade(1, 2, 'A');
	add_Grade(1, 3, 'C');
	add_Grade(2, 1, 'A');
	add_Grade(2, 2, 'A');
	add_Grade(2, 4, 'B');
	*/
}