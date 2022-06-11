#include <cmath>
#include "Course.h"
using namespace std;
Course::Course(string str,int u):name(str),unit(u){mark=new double;}
Course::Course(){mark=new double;}
Course::Course(const Course& r){
    name = r.name;
    unit = r.unit;
    mark = new double;
    *mark = *(r.mark);
}
Course::~Course(){delete mark;}
string Course::getName(){return this->name;}
int Course::getUnit(){return this->unit;}
double* Course::getMark(){return this->mark;}
void Course::setName(string str){name=str;}
void Course::setUnit(int u){unit=u;}
void Course::setMark(double* m){*mark=*m;}
ostream& operator<<(ostream& out,const Course& r){
    out<<"Name:"<<r.name<<endl;
    out<<"Unit:"<<r.unit<<endl;
    out<<"Mark:"<<*(r.mark)<<endl;
    return out;
}
istream& operator>>(istream& in,Course& r){
    cout<<"Name:";
    in>>r.name;
    cout<<endl;
    cout<<"Unit:";
    in>>r.unit;
    cout<<endl;
    cout<<"Mark:";
    in>>*(r.mark);
    cout<<endl;
    return in;
}
