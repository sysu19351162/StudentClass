#include<iostream>
#include<iomanip>
#include<string>
#include"student.h"

using namespace std;

Student::Student():id_(111),name_("��")//�޲ι��캯��
{
	cout << "callling the constructer" << endl;

	int i;
	for (i = 0; i < maxCourses_; i++)
	{
		*(courseNames_ + i) = "��";
	}

	for (i = 0; i < maxCourses_; i++)
	{
		grade_[i] = 0;
	}

}


Student::Student(const Student& s):id_(s.id_),name_(s.name_)//���ƹ��캯��
{
	int i;
	for (i = 0; i < maxCourses_; i++)
	{
		*(courseNames_ + i) = *(s.courseNames_ + i);
	}

	for (i = 0; i < maxCourses_; i++)
	{
		*(grade_ + i) = *(s.grade_ + i);
	}
}


Student::Student( int id,  std::string name, std::string courseNames[maxCourses_]):id_(id),name_(name)//���ι��캯��
{
	int i;
	for (i = 0; i < maxCourses_; i++)
	{
		*(courseNames_ + i) = *(courseNames + i);
	}

	for (i = 0; i < maxCourses_; i++)
	{
		grade_[i] = 0;
	}
}


Student::~Student()//��������
{
	cout << "calling the destructer" << endl;
}


void Student::set_id(int id)//idд�뺯��	
{
	cout << "calling the set_id function" << endl;
	
	id_ = id;

	cout << "id:" << id_<<endl;

}


void Student::get_id()const//id��ȡ����
{
	cout << "id:" << id_ << endl;
}


void Student::set_name(std::string name)//nameд�뺯��
{
	name_ = name;
}


void Student::get_name()const//name��ȡ����
{
	cout << "name:" << name_ << endl;
}


bool Student::AddCourse(const std::string& courseName, double grade)//�γ̼��뺯��
{
	if (flag_courseNames_ < 3)
	{
		*(courseNames_ + flag_courseNames_) = courseName;
		return true;
	}
	else
		return false;
}


void Student::SetGrade(const std::string& courseName, double grade)//�ɼ�д�뺯��
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (*(courseNames_+i) == courseName)
		{
			grade_[i] = grade;
			break;
		}

		if (i == 2)
			cout << "There is no such course"<<endl;
	}
}


double Student::GetGrade( const std::string& courseName)const//�ɼ���ȡ����
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (*(courseNames_ + i) == courseName)
		{
			cout << "courseName:" << *(courseNames_ + i) << endl;

			cout << "grade:" << *(grade_ + i) << endl;	

			return *(grade_ + i);

			break;
		}
		
	}
}


double Student::GetAverageGrade()const//ƽ���ֶ�ȡ����
{
	float sum = 0, aver = 0;

	int i;
	for (i = 0; i < flag_courseNames_; i++)
	{
		sum = sum + *(grade_ + i);
	}

	aver = sum / flag_courseNames_;

	return aver;
}


void Student::ShowGrades()const//�ɼ���ȫ������ȡ����
{
	int i;
	for (i = 0; i < maxCourses_; i++)
	{
		cout << "courseName:" << *(courseNames_ + i) << endl;
		
		cout << "grade:" << *(grade_ + i) << endl;
	}

}
