#include <cmath>
#include "University.h"
using namespace std;
University::University(int b,int np,int ns,Professor* p,Student* s){
    budget = b;
    numOfProfessors = np;
    numOfStudents = ns;
    profs= new Professor[np];
    stus= new Student[ns];
    for (int i = 0; i < np; i++){
        profs[i] = p[i];
    }
    for (int i = 0; i < ns; i++){
        stus[i] = s[i];
    }
}
University::University(const University& r){
    budget = r.budget;
    numOfProfessors = r.numOfProfessors;
    numOfStudents = r.numOfStudents;
    profs= new Professor[numOfProfessors];
    stus= new Student[numOfStudents];
    for (int i = 0; i < numOfProfessors; i++){
        profs[i] = r.profs[i];
    }
    for (int i = 0; i < numOfStudents; i++){
        stus[i] = r.stus[i];
    }
}
University::~University(){
    delete [] stus;
    delete [] profs;
}
double University::averageGpa(){
    double aveGpa=0;
    for (int i = 0; i < numOfStudents; i++){
        aveGpa=stus->gpa();
    }
    aveGpa= aveGpa/numOfStudents;
    return aveGpa;
}
double University::averageGpaOfField(std::string str){
    if(stus->getFieldOfStudy() == str){
        
    }
}
double University::averageMarkOfCourse(std::string str){

}
double University::printCourses(std::string str){

}
bool University::isEnoughBudget(){

}
void University::saveToFile(){

}
ostream& operator<<(ostream&,const University&){

}
istream& operator>>(istream&,University&){

}