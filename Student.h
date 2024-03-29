#ifndef STUDENT_H
#define STUDENT_H

#include <string.h>
#include "Person.h"
#include "Course.h"

class Student: public Person{
private:
    Course* courses;
    std::string fieldOfStudy;
    int numOfCourses;
public:
    Student(std::string str1,std::string str2,std::string str3,double* w,
            Course* c,std::string str4,int n);
    Student();
    Student(const Student& r);
    ~Student();
    std::string getFieldOfStudy();
    std::string getCourseName(int);
    double getCourseMark(int);
    int getNumOfCourse();
    double calculateSalary();
    double gpa();
    bool validate(std::string str);
    friend std::ostream& operator<<(std::ostream&,const Student&);
    friend std::istream& operator>>(std::istream&,Student&);
};

#endif //STUDENT_H