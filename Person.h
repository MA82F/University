#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string.h>

class Person{
protected:
    std::string firstName;
    std::string lastName;
    std::string id;
    double* workHours;
public:
    Person(std::string str1,std::string str2,std::string str3,double* w);
    Person();
    Person(const Person& r);
    ~Person();
    std::string getFirstName();
    std::string getLastName();
    std::string getId();
    double* getWorkHours();
    void setFirstName(std::string str);
    void setLastName(std::string str);
    void setId(std::string str);
    void setWorkHours(double* w);
    Person& operator =(const Person&);
    friend std::ostream& operator<<(std::ostream&,const Person&);
    friend std::istream& operator>>(std::istream&,Person&);
};

#endif //PERSON_H