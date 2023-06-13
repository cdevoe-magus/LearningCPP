//A GPA calculator, formula: total(score*hours)/total hours
#include <string>
#include "Course.h"
#include "Student.h"
#include "Grade.h"
#include <vector>
#include <iostream>
#include "GPA.h"

std::vector<Student> students = {Student(1, "George P. Burdell"), Student(2, "Nancy Rhodes")};
std::vector<Grade> grades = {Grade(1,1,'B'),Grade(1,2,'A'),Grade(1,3,'C'),Grade(2,1,'A'),Grade(2,2,'A'), Grade(2,4,'B')};
std::vector<Course> courses = {Course(1,"Algebra",5),Course(2,"Physics",4),Course(3,"English",3),Course(4,"Economics",4)};


void GPA(int id ) {
	float gpa = 0.0f;
	int creds = 0;
	int sd_id = -1;
	std::string sd_name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].get_id() == id) {
			sd_id = students[i].get_id();
			sd_name = students[i].get_name();
		}
	}
	if (sd_id >= 0) {
		for (Grade& g : grades) {
			if (g.get_student_id() == sd_id) {
				for (Course& c : courses) {
					if (g.get_course_id() == c.get_id()) {
						switch (g.get_grade()) {
						case 'A':
							gpa += 4.0f * c.get_cred();
							break;
						case 'B':
							gpa += 3.0f * c.get_cred();
							break;
						case 'C':
							gpa += 2.0f * c.get_cred();
							break;
						case 'D':
							gpa += 1.0f * c.get_cred();
							break;
						default:
							break;
						}
						creds += c.get_cred();
					}
				}
			}
		}
		if (creds > 0) {
			gpa = gpa / creds;
		}
		std::cout << sd_name << "'s gpa is: " << gpa << std::endl;
	}
	else {
		std::cout << "Student not found.";
	}
	//return gpa;
}