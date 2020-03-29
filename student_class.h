#pragma once
#include"student.h"

class Student;

class StudentClass
{
private:
	static const int  maxStudents_=20 ;//班级最大人数为20

	static  int studentCount_;//学生总数计数器

	int student_flag = 0;//班级学生人数计数器

	std::string code_;//班号

	Student* students_[maxStudents_];

public:
	StudentClass();//无参构造函数

	StudentClass(std::string code, Student* students[maxStudents_]);//有参构造函数

	StudentClass(const StudentClass& c);//复制构造函数

	~StudentClass();//析构函数

	void set_code(const std::string code);//班号设置函数

	void get_code();//班号读取函数

	bool AddStudent(const Student* student);//学生添加函数

	void ShowStudent(int id)const;//学生读取函数

	void ShowStudentsByIdOrder(bool(*compare)(int, int));//学生排序函数
	
	static void showStudentCount();//学生总数展示函数

};

