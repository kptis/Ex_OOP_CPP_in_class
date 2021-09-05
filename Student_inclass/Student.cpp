#include "student.h"
#include <iostream>
using namespace std;

void Student::displayStudentData()
{
	cout<<"idnum="<<idNum<<endl;
	cout<<"lastName="<<lastName<<endl;
	cout<<"gradePointAverage="<<gradePointAverage<<endl;
}

void Student::setIdNum(int idNum)
{
	this->idNum = idNum;
}
void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}
void Student::setGradePointAverage(double gpa)
{
	this->gradePointAverage = gpa;
}

Student::Student(int idNum, string lastName, double gradePointAverage){
	this->idNum= idNum;
	this->lastName= lastName;
	this->gradePointAverage= gradePointAverage;
}

Student::Student(){
	this->idNum=-1;
	this->lastName="";
	this->gradePointAverage=-1;
}
