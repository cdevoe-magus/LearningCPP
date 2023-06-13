#pragma once

class Grade{

private:
	int student_id;
	char grade;
	int course_id;

public:
	Grade(int s_id, int c_id, char grade_n);
	void set_student_id(int s_id_n);
	int get_student_id();
	void set_grade(char grade_n);
	char get_grade();
	void set_course_id(int course_id_n);
	int get_course_id();
};
