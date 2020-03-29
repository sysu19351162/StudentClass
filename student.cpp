#include<iostream>
#include<iomanip>
#include<string>
#include"student.h"

using namespace std;

Student::Student():id_(111),name_("空")//无参构造函数
{
	cout << "callling the constructer" << endl;

	int i;
	for (i = 0; i < maxCourses_; i++)
	{
		*(courseNames_ + i) = "空";
	}

	for (i = 0; i < maxCourses_; i++)
	{
		grade_[i] = 0;
	}

}


Student::Student(const Student& s):id_(s.id_),name_(s.name_)//复制构造函数
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


Student::Student( int id,  std::string name, std::string courseNames[maxCourses_]):id_(id),name_(name)//含参构造函数
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


Student::~Student()//析构函数
{
	cout << "calling the destructer" << endl;
}


void Student::set_id(int id)//id写入函数	
{
	cout << "calling the set_id function" << endl;
	
	id_ = id;

	cout << "id:" << id_<<endl;

}


void Student::get_id()const//id读取函数
{
	cout << "id:" << id_ << endl;
}


void Student::set_name(std::string name)//name写入函数
{
	name_ = name;
}


void Student::get_name()const//name读取函数
{
	cout << "name:" << name_ << endl;
}


bool Student::AddCourse(const std::string& courseName, double grade)//课程加入函数
{
	if (flag_courseNames_ < 3)
	{
		*(courseNames_ + flag_courseNames_) = courseName;
		return true;
	}
	else
		return false;
}


void Student::SetGrade(const std::string& courseName, double grade)//成绩写入函数
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


double Student::GetGrade( const std::string& courseName)const//成绩读取函数
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


double Student::GetAverageGrade()const//平均分读取函数
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


void Student::ShowGrades()const//成绩（全部）读取函数
{
	int i;
	for (i = 0; i < maxCourses_; i++)
	{
		cout << "courseName:" << *(courseNames_ + i) << endl;
		
		cout << "grade:" << *(grade_ + i) << endl;
	}

}
