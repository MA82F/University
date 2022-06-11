#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"

class Professor : public Person{
private:
    std::string title;
public:
    Professor(std::string str1,std::string str2,std::string str3,double* w,std::string t);
    Professor();
    bool validate(std::string str);
    double calculateSalary();
    friend std::ostream& operator<<(std::ostream&,const Professor&);
    friend std::istream& operator>>(std::istream&,Professor&);
};

#endif //PROFESSOR_H