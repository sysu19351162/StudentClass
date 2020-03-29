#pragma once
#include"student.h"

class Student;

class StudentClass
{
private:
	static const int  maxStudents_=20 ;//�༶�������Ϊ20

	static  int studentCount_;//ѧ������������

	int student_flag = 0;//�༶ѧ������������

	std::string code_;//���

	Student* students_[maxStudents_];

public:
	StudentClass();//�޲ι��캯��

	StudentClass(std::string code, Student* students[maxStudents_]);//�вι��캯��

	StudentClass(const StudentClass& c);//���ƹ��캯��

	~StudentClass();//��������

	void set_code(const std::string code);//������ú���

	void get_code();//��Ŷ�ȡ����

	bool AddStudent(const Student* student);//ѧ����Ӻ���

	void ShowStudent(int id)const;//ѧ����ȡ����

	void ShowStudentsByIdOrder(bool(*compare)(int, int));//ѧ��������
	
	static void showStudentCount();//ѧ������չʾ����

};

