#include <cmath>
#include "Student.h"
using namespace std;
Student::Student(std::string str1,std::string str2,std::string str3,double* w,
            Course* c,std::string str4,int n):Person(str1,str2,str3,w){
                courses = new Course("none",0,new double);
                *courses = *c;
                fieldOfStudy = str4;
                numOfCourses = n;
}
Student::Student(const Student& r):Person(*this){
    fieldOfStudy = r.fieldOfStudy;
    numOfCourses = r.numOfCourses;
    courses = new Course("none",0,new double);
    *courses = *(r.courses);
}
Student::~Student(){courses->~Course();}
ostream& operator<<(std::ostream& out,const Student& r){
    out<<"Firstname:"<<r.firstName<<endl;
    out<<"Lastname:"<<r.lastName<<endl;
    out<<"ID:"<<r.id<<endl;
    out<<"Workhours:"<<*(r.workHours)<<endl;
    out<<"Field Of Study:"<<r.fieldOfStudy<<endl;
    out<<"Number Of Courses:"<<r.numOfCourses<<endl;
    out<<"Courses:"<<endl;
    for (int i = 0; i < r.numOfCourses; i++)
        out<<"          "<<r.courses[i]<<endl;
    return out;
}
istream& operator>>(std::istream& in,Student& r){
    cout<<"Firstname:";
    in>>r.firstName;
    cout<<endl;
    cout<<"Lastname:";
    in>>r.lastName;
    cout<<endl;
    cout<<"ID:";
    in>>r.id;
    cout<<endl;
    cout<<"Workhours:";
    in>>*(r.workHours);
    cout<<endl;
    cout<<"Field Of Study:";
    in>>r.fieldOfStudy;
    cout<<endl;
    cout<<"Number Of Courses:";
    in>>r.numOfCourses;
    cout<<endl;
    for (int i = 0; i < r.numOfCourses; i++){
        cout<<"Course"<<1+i<<":";
        in>>r.courses[i];
    }
    cout<<endl;
    return in;
}