#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string.h>

class Course{
private:
    std::string name;
    int unit;
    double* mark;
public:
    Course(std::string str,int u,double* m);
    Course();
    Course(const Course& r);
    ~Course();
    std::string getName();
    int getUnit();
    double* getMark();
    void setName(std::string str);
    void setUnit(int u);
    void setMark(double* m);
    friend std::ostream& operator<<(std::ostream&,const Course&);
    friend std::istream& operator>>(std::istream&,Course&);
};

#endif //COURSE_H