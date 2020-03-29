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
	Student();//�޲ι��캯��

	Student(const Student& s);//���ƹ��캯��

	Student(int id, std::string name, std::string courseNames[maxCourses_]);//�вι��캯��

	~Student();//��������

	void set_id(int id);//id��ȡ����
	void get_id()const;

	void set_name(std::string name);//name��ȡ����
	void get_name()const;

	bool AddCourse(const std::string& courseNme, double grade);//�γ���Ӻ���

	void SetGrade(const std::string& courseName, double grade);//�ɼ����ú���

	double GetGrade(const std::string& courseName)const;//�ɼ���ȡ����

	double GetAverageGrade()const;//ƽ���ּ��㺯��

	void ShowGrades()const;//�ɼ���ȫ����չʾ����
};

