#include<iostream>
#include"student_class.h"

class Student;

class StudentClass;

int StudentClass::studentCount_ = 0;//ѧ������

StudentClass::StudentClass():code_("ise201901")//�޲ι��캯��
{
	const Student s;

	for (int i = 0; i < maxStudents_; i++)
	{
		students_[i] = const_cast<Student*>(&s);
	}
}


StudentClass::StudentClass(std::string code, Student* students[maxStudents_]) : code_(code)//���ι��캯��
{
	int i;
	
	for (i = 0; i < maxStudents_; i++)
	{
		*(students_ + i) = *(students + i);
	}


}


StudentClass::StudentClass(const StudentClass& c):code_(c.code_)//���ƹ��캯��
{
	int i;

	for (i = 0; i < maxStudents_; i++)
	{
		*(students_ + i) = *(c.students_ + i);
	}
}


StudentClass::~StudentClass()//��������
{
	std::cout << "calling the StudentClass distructer";
}


void StudentClass::set_code(const std::string code)//���д�뺯��
{
	code_ = code;

	std::cout << "code:" << code_ << std::endl;
}


void StudentClass::get_code()//��Ŷ�ȡ����
{
	std::cout << "code:" << code_ << std::endl;
}


bool StudentClass::AddStudent(const Student* student)//ѧ����Ӻ���
{
	if (student_flag < maxStudents_)
	{
		*(students_ + student_flag) = const_cast<Student*>(student);

		studentCount_++;

		student_flag++;

		return 1;
	}

	else return 0;
}


void StudentClass::ShowStudent(int id)const//ѧ����ȡ����
{
	int i;

	for (i = 0; i < maxStudents_; i++)
	{
		if (students_[i]->id_ == id)
		{
		std::cout << "name:" << students_[i]->name_ << std::endl;

		std::cout << "id:" << students_[i]->id_ << std::endl;

		students_ [i]->ShowGrades();

		break;
		}
	}
}


void StudentClass::ShowStudentsByIdOrder(bool(*compare)(int, int))//ѧ��������������Ϊid��
{
	void swap(int* const e1ptr, int* const e2ptr);

	int smallestorlargest;

	for (int i = 0; i < maxStudents_ - 1; i++)
	{
		smallestorlargest = i;

		for (int index = i + 1; index < maxStudents_; index++)
		{
			if(!(*compare)(students_[smallestorlargest]->id_,students_[index]->id_))
				smallestorlargest = index;

				swap(&(students_[smallestorlargest]->id_),&(students_[i]->id_));
		}
	}

	for (int i = 0; i < student_flag; i++)
		std::cout << students_[i]->name_ << std::endl;

}


void StudentClass::showStudentCount()//ѧ��������ȡ����
{
	std::cout << "StudentCount:" << studentCount_<<std::endl;
}


void swap(int* const e1ptr, int* const e2ptr)//��������
{
	int hold = *e1ptr;

	*e1ptr = *e2ptr;

	*e2ptr = hold;
}

bool ascending(int a, int b)
{
	return a < b;
}


bool descending(int a, int b)
{
	return a > b;
}
