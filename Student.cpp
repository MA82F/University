#include <cmath>
#include "Student.h"
using namespace std;
Student::Student(string str1,string str2,string str3,double* w,Course* c,
                 string str4,int n):Person(str1,str2,str3,w){
    if (validate(str3)==0){
        cout<<"invalid id";
        exit(0);
    }
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
bool validate(string str){
    if (!(str.length()>=8 && str.length()<=10))
        return 0;
    if (!(stoi(str.substr(0,1))>84 && stoi(str.substr(0,1))<=99)) //between 84 to 00
        return 0;
    if (str[2]!='*')
        return 0;
    if (str.length()==10){
        for (int i = 3; i <= 4; i++)
            if (isdigit(str[i]))
                return 0;
        for (int i = 5; i <= str.length(); i++)
            if (!(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' ||
                str[i]=='7' || str[i]=='8' || str[i]=='9'))
                return 0;
    }
    if (str.length()==9){
        if (isdigit(str[3]))
            return 0;
        for (int i = 4; i <= str.length(); i++)
            if (!(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' ||
                str[i]=='7' || str[i]=='8' || str[i]=='9'))
                return 0;
        
    }
    if (str.length()==8){
        for (int i = 3; i <= str.length(); i++)
            if (!(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' ||
                str[i]=='7' || str[i]=='8' || str[i]=='9'))
                return 0;
    }
    return 1;  
}