

#include<iostream>
#include"student.h"
#include"student_class.h"

using namespace std;

bool ascending(int a, int b);
bool descending(int a, int b);

int main()
{
	string courses[3] = { "Robotics","C++","Math" };

	Student a(211, "Bob", courses);			//构造函数
	Student b(212, "John", courses);
	Student c(213, "Alice", courses);

	a.get_id();								//id读取函数
	a.set_id(214);							//id写入函数

	a.get_name();							//name读取函数
	a.set_name("Jack");						//name写入函数

	if (a.AddCourse("NewCourse", 90))		//课程添加函数，并检测是否满课
		cout << "add successfully"<<endl;
	else	
		cout << "no vacancy"<<endl;

	b.SetGrade("C++", 100);					//成绩写入函数

	b.GetGrade("C++");						//成绩读取函数

	b.GetAverageGrade();					//平均分读取函数

	b.ShowGrades();							//成绩展示函数（个人）

	StudentClass ClassA;

	if (ClassA.AddStudent(&a))				//调用学生加入函数，并检测是否有空位
		cout << "add successfully"<<endl;
	else
		cout << "no vacancy"<<endl;

	if (ClassA.AddStudent(&b))
		cout << "add successfully"<<endl;
	else
		cout << "no vacancy"<<endl;

	if (ClassA.AddStudent(&c))
		cout << "add successfully"<<endl;
	else
		cout << "no vacancy"<<endl;

	ClassA.get_code();						//班号读取函数

	ClassA.set_code("ise201902");			//班号设置函数

	ClassA.ShowStudent(212);				//学生读取函数

	//读取用户指令，决定是升序排列还是降序排列

	int order=0;//ascending==1,descendin==2

	cout << "pleas input the order(ascending==1,descendin==2)" << endl;

	cin >> order;

	if (order == 1)
		ClassA.ShowStudentsByIdOrder(ascending);
	else
		if (order == 2)
			ClassA.ShowStudentsByIdOrder(descending);
		else
			cout << "function wrong";

	ClassA.showStudentCount();				//学生总数读取函数

	return 0;

}