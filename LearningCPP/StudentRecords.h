#pragma once
#include <vector>
#include "Grade.h"
#include "Student.h"
#include "Course.h"
#include <string>


class StudentRecords {
private:
	std::vector<Student> students;
	std::vector<Grade> grades;
	std::vector<Course> courses;
public:
	float GPA(int);
	void add_Student(int, std::string);
	void add_Course(int, std::string, int);
	void add_Grade(int, int, char);
	std::string report_card(int);
	void find_student(int);
	int init(std::string, std::string, std::string);
	std::string get_student_name(int);
	float get_grade_value(char);
	std::string get_course_name(int id);
	std::string list_student_grades(int id);
	void write_rcards();

};
