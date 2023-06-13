//a class representing a Grade
#include <string>
#include "Grade.h"

	Grade::Grade(int s_id, int c_id, char grade_n) {
		student_id = s_id;
		course_id = c_id;
		grade = grade_n;
	}
	void Grade::set_student_id(int s_id_n) {
		student_id = s_id_n;
	}
	int Grade::get_student_id() {
		return student_id;
	}
	void Grade::set_grade(char grade_n) {
		grade = grade_n;
	}
	char Grade::get_grade() {
		return grade;
	}
	void Grade::set_course_id(int course_id_n) {
		course_id = course_id_n;
	}
	int Grade::get_course_id() {
		return course_id;
	}