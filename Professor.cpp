#include <cmath>
#include "Professor.h"
using namespace std;
Professor::Professor(string str1,string str2,string str3,double* w,string t)
          :Person(str1,str2,str3,w),title(t){
    if(validate(str3)==0){
        cout<<"invalid id";
        exit(0);
    }
}
ostream& operator<<(std::ostream& out,const Professor& r){
    out<<"Firstname:"<<r.firstName<<endl;
    out<<"Lastname:"<<r.lastName<<endl;
    out<<"ID:"<<r.id<<endl;
    out<<"Workhours:"<<*(r.workHours)<<endl;
    out<<"Title:"<<r.title<<endl;
    return out;
}
istream& operator>>(std::istream& in,Professor& r){
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
    cout<<"Title:";
    in>>r.title;
    cout<<endl;
    return in;
}
bool Professor::validate(string str){
    if (!(str.length()>=8 && str.length()<=10))
        return 0;
    if (!(stoi(str.substr(0,1))>84 && stoi(str.substr(0,1))<=99)) //between 84 to 00
        return 0;
    if (str[2]!='#')
        return 0;
    for (int i = 3; i <= str.length(); i++)
        if (!(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' ||
            str[i]=='7' || str[i]=='8' || str[i]=='9'))
            return 0;
    return 1;  
}
double Professor::calculateSalary(){
    double salary=0;
    salary *=(*workHours)*50000;
    if (this->title=="Assistant Professor"){
        salary = salary + 10000;
    }
    if (this->title=="Associate Professor"){
        salary = salary + 20000;
    }
    if (this->title=="Professor"){
        salary = salary + 30000;
    }
    return salary;
}