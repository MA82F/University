#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Professor.h"
#include "Student.h"

class University{
private:
    int budget;
    int numOfProfessors;
    int numOfStudents;
    Professor* professors;
    Student* Students;
public:
    // University(std::string str1,std::string str2,std::string str3,double* w,std::string t);
    // bool validate(std::string str);
    // double Professor::calculateSalary();
    // friend std::ostream& operator<<(std::ostream&,const Professor&);
    // friend std::istream& operator>>(std::istream&,Professor&);
};

#endif //PROFESSOR_H