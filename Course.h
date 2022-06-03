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
    Course(const Course& r);
    ~Course();
    std::string getName();
    int getUnit();
    double* getMark();
    friend std::ostream& operator<<(std::ostream&,const Course&);
    friend std::istream& operator>>(std::istream&,Course&);
    virtual void fall();
    void setPosition(double x, double y);
    void move(const double& x,const double& y);
    double getX() const;
    double getY() const;
    bool isInPit(double x, double y , double r) const;
};


#endif //COURSE_H