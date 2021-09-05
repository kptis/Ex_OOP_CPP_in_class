#include "student.h"
int main()
{
	Student a;
//	a.setIdNum(1);
//	a.setLastName("Khong");
//	a.setGradePointAverage(4.0);
//	a.displayStudentData();
	Student *p;
	p=&a;
	p->displayStudentData();
	
//	dung ham tao trong cap phat bo nho 
	system("pause");
	return 0;
}
