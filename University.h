#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Professor.h"
#include "Student.h"

class University{
private:
    int budget;
    int numOfProfessors;
    int numOfStudents;
    Professor* professor;
    Student* Students;
public:
    University(int b,int np,int ns,Professor* p,Student* s);
    University(const University& r);
    ~University();
    double averageGpa();
    double averageGpaOfField(std::string str);
    double averageMarkOfCourse(std::string str);
    double printCourses(std::string str);
    bool isEnoughBudget();
    void saveToFile();
    friend std::ostream& operator<<(std::ostream&,const University&);
    friend std::istream& operator>>(std::istream&,University&);
};

#endif //PROFESSOR_H