#include <string>
using namespace std;

class Student
{
private:
	int idNum;
	string lastName;
	double gradePointAverage;
public:
	Student();
	Student(int idNum, string lastName, double gradePointAverage);
	void displayStudentData();
	void setIdNum(int idNum);
	void setLastName(string lastName);
	void setGradePointAverage(double gpa);
};
