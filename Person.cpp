#include <cmath>
#include "Person.h"
using namespace std;
Person::Person(string str1,string str2,string str3,double* w)
    :firstName(str1),lastName(str2),id(str3),workHours(w){
        workHours = new double;
        if (validate(id)==0){
            cout<<"invalid id";
            exit(0);
        }
}
Person::Person(const Person& r){
    firstName = r.firstName;
    lastName = r.lastName;
    id = r.id;
    *workHours = *(r.workHours);
}
Person::~Person(){delete workHours;}
string Person::getFirstName(){return firstName;}
string Person::getLastName(){return lastName;}
string Person::getId(){return id;}
double* Person::getWorkHours(){return workHours;}
void Person::setFirstName(string str){firstName = str;}
void Person::setLastName(string str){lastName = str;}
void Person::setId(string str){id = str;}
void Person::setWorkHours(double* w){*workHours = *w;}
Person& Person::operator =(const Person& r){    // a = b: a=this  b=r
    this->firstName = r.firstName;
    this->lastName = r.lastName;
    this->id = r.id;
    *(this->workHours) = *(r.workHours);
}
ostream& operator<<(std::ostream& out,const Person& r){
    out<<"Firstname:"<<r.firstName<<endl;
    out<<"Lastname:"<<r.lastName<<endl;
    out<<"ID:"<<r.id<<endl;
    out<<"Workhours:"<<*(r.workHours)<<endl;
    return out;
}
istream& operator>>(std::istream& in,Person& r){
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
    return in;
}
bool validate(string str){
    if (!(str.length()>=8 && str.length()<=10))
        return 0;
    if (!(stoi(str.substr(0,1))>84 && stoi(str.substr(0,1))<=99)) //between 84 to 00
        return 0;
    if (str.length()==10){
        for (int i = 2; i <= 4; i++)
            if (isdigit(str[i]))
                return 0;
        for (int i = 5; i <= str.length(); i++)
            if (!(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' ||
                str[i]=='7' || str[i]=='8' || str[i]=='9'))
                return 0;
    }
    if (str.length()==9){
        for (int i = 2; i <= 3; i++)
            if (isdigit(str[i]))
                return 0;
        for (int i = 4; i <= str.length(); i++)
            if (!(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' ||
                str[i]=='7' || str[i]=='8' || str[i]=='9'))
                return 0;
        
    }
    if (str.length()==8){
        if(isdigit(str[2]))
                return 0;
        for (int i = 3; i <= str.length(); i++)
            if (!(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' ||
                str[i]=='7' || str[i]=='8' || str[i]=='9'))
                return 0;
    }
    return 1;  
}
double calculateSalary(double salaryHours){
    salaryHours *=10000;
    return salaryHours;
}