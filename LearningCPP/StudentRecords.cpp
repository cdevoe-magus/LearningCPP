//A GPA calculator, formula: total(score*hours)/total hours
#include <string>
#include "Course.h"
#include "Student.h"
#include "Grade.h"
#include <vector>
#include <iostream>
#include "StudentRecords.h"

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

void StudentRecords::list_student_grades(int id) {
	for (Grade& g: grades) {
		if (g.get_student_id() == id) {
			std::cout << StudentRecords::get_course_name(g.get_course_id()) << ": " << g.get_grade() << std::endl;
		}
	}
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
	}
	//return gpa;
}

void StudentRecords::report_card(int id) {
	std::string st_name = StudentRecords::get_student_name(id);
	if (st_name.compare("none") != 0) {
		std::cout << st_name << std::endl;
		StudentRecords::list_student_grades(id);
		std::cout << "GPA: " << StudentRecords::GPA(id) << std::endl;
	}
	else {
		std::cout << "Student not found.";
	}
	
}
void StudentRecords::init() {
	add_Student( 1, "George P. Burdell");
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

}