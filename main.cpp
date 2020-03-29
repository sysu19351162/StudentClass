

#include<iostream>
#include"student.h"
#include"student_class.h"

using namespace std;

bool ascending(int a, int b);
bool descending(int a, int b);

int main()
{
	string courses[3] = { "Robotics","C++","Math" };

	Student a(211, "Bob", courses);			//���캯��
	Student b(212, "John", courses);
	Student c(213, "Alice", courses);

	a.get_id();								//id��ȡ����
	a.set_id(214);							//idд�뺯��

	a.get_name();							//name��ȡ����
	a.set_name("Jack");						//nameд�뺯��

	if (a.AddCourse("NewCourse", 90))		//�γ���Ӻ�����������Ƿ�����
		cout << "add successfully"<<endl;
	else	
		cout << "no vacancy"<<endl;

	b.SetGrade("C++", 100);					//�ɼ�д�뺯��

	b.GetGrade("C++");						//�ɼ���ȡ����

	b.GetAverageGrade();					//ƽ���ֶ�ȡ����

	b.ShowGrades();							//�ɼ�չʾ���������ˣ�

	StudentClass ClassA;

	if (ClassA.AddStudent(&a))				//����ѧ�����뺯����������Ƿ��п�λ
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

	ClassA.get_code();						//��Ŷ�ȡ����

	ClassA.set_code("ise201902");			//������ú���

	ClassA.ShowStudent(212);				//ѧ����ȡ����

	//��ȡ�û�ָ��������������л��ǽ�������

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

	ClassA.showStudentCount();				//ѧ��������ȡ����

	return 0;

}