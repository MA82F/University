#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Professor.h"
#include "Student.h"

class University{
private:
    int budget;
    int numOfProfessors;
    int numOfStudents;
    Professor* profs;
    Student* stus;
public:
    University(int b,int np,int ns,Professor* pr,Student* st);
    University(const University& r);
    ~University();
    double averageGpa();
    double averageGpaOfField(std::string str);
    double averageMarkOfCourse(std::string str);
    double printCourses(std::string str);
    bool isEnoughBudget();
    void saveToFile();
    friend std::ostream& operator<<(std::ostream&,const University&);
    // friend std::istream& operator>>(std::istream&,University&);
};

#endif //UNIVERSITY_H