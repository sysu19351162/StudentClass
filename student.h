#pragma once


class Student
{
	friend class StudentClass;
private:
	static const int  maxCourses_=3;

	int id_;

	std::string name_;

	std::string courseNames_[maxCourses_];

	int flag_courseNames_ = 0;

	double grade_[maxCourses_];
	

public:
	Student();//无参构造函数

	Student(const Student& s);//复制构造函数

	Student(int id, std::string name, std::string courseNames[maxCourses_]);//有参构造函数

	~Student();//析构函数

	void set_id(int id);//id存取函数
	void get_id()const;

	void set_name(std::string name);//name存取函数
	void get_name()const;

	bool AddCourse(const std::string& courseNme, double grade);//课程添加函数

	void SetGrade(const std::string& courseName, double grade);//成绩设置函数

	double GetGrade(const std::string& courseName)const;//成绩读取函数

	double GetAverageGrade()const;//平均分计算函数

	void ShowGrades()const;//成绩（全部）展示函数
};

