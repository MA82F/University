#include <cmath>
#include <fstream>
#include "University.h"
using namespace std;
University::University(int b,int np,int ns,Professor* pr,Student* st){
    budget = b;
    numOfProfessors = np;
    numOfStudents = ns;
    profs= pr;
    stus=  st;
    // profs= new Professor[np];
    // stus= new Student[ns];
    // for (int i = 0; i < np; i++){
    //     profs[i] = p[i];
    // }
    // for (int i = 0; i < ns; i++){
    //     stus[i] = s[i];
    // }
}
University::University(const University& r){
    budget = r.budget;
    numOfProfessors = r.numOfProfessors;
    numOfStudents = r.numOfStudents;
    profs= new Professor[numOfProfessors];
    stus= new Student[numOfStudents];
    // for (int i = 0; i < numOfProfessors; i++){
    //     profs[i] = r.profs[i];
    // }
    // for (int i = 0; i < numOfStudents; i++){
    //     stus[i] = r.stus[i];
    // }
}
University::~University(){
    delete [] stus;
    delete [] profs;
}
double University::averageGpa(){
    double aveGpa=0;
    for (int i = 0; i < numOfStudents; i++){
        aveGpa+=stus[i].gpa();
    }
    aveGpa= aveGpa/numOfStudents;
    return aveGpa;
}
double University::averageGpaOfField(std::string str){
    double aveGpaField=0;
    int num=0;
    for (int i = 0; i < numOfStudents; i++){       
        if((stus[i]).getFieldOfStudy() == str){
            aveGpaField += (stus[i]).gpa();
            num++;
        }
    }
    return (aveGpaField/num);
}
double University::averageMarkOfCourse(std::string str){
    double aveGpaCourse=0;
    int num=0;
    for (int i = 0; i < numOfStudents; i++){
        for (int j = 0; j < stus[i].getNumOfCourse(); j++){
            if(stus[i].getCourseName(j) == str){
                aveGpaCourse += stus[i].getCourseMark(j);
                num++;
            }
        }
    }
    return (aveGpaCourse/num);
}
// double University::printCourses(std::string str){
//     for (int i = 0; i < num; i++)////////////////
//     {////////////////////////////
//         /* code *//////////////////
//     }////////////
//     ///////////////////////////////
// }//////////////////////////
bool University::isEnoughBudget(){
    int salaries = 0;
    for (int i = 0; i < numOfStudents; i++){
        salaries += stus[i].calculateSalary();
    }
    for (int i = 0; i < numOfProfessors; i++){
        salaries += profs[i].calculateSalary();
    }
    if (budget>=salaries)
        return true;
    else
        return false;
}
void University::saveToFile(){
    ofstream myfile;
    myfile.open ("save.txt");
    int array[numOfStudents]={0};
    int n=0;
    for (int i = 0; i < numOfStudents; i++){
        for (int j = i+1; j < numOfStudents; j++){
            if (stus[i].getFieldOfStudy()==stus[j].getFieldOfStudy()){
                if (stus[i].gpa()>stus[j].gpa()){
                    array[n] = i;
                }
                else{
                    array[n]= j;
                }
            }
            n++;
        }
    }
    for (int i = 0; i < n; i++){
        myfile << stus[array[i]].getFirstName()<<" "<< stus[array[i]].getLastName()
               <<"    "<<stus[array[i]].getId()<<"   "<<stus[array[i]].gpa()
               <<"   "<<stus[array[i]].getFieldOfStudy()<<endl;
    }
    myfile.close();
}
ostream& operator<<(ostream& out,const University& r){
    //sorting
    for(int i=0; i<r.numOfProfessors; i++){
        for(int j=i+1; j<r.numOfProfessors; j++){
            //If there is a smaller element found on right of the array then swap it.
            string str1= r.profs[j].getId();
            string str2= r.profs[i].getId();
            if(str1.substr(0,1) < str2.substr(0,1)){
                Professor temp = r.profs[i];
                r.profs[i] = r.profs[j];
                r.profs[j] = temp;
            }
            else if(str1.substr(0,1) == str2.substr(0,1)){
                if (r.profs[j].getLastName() < r.profs[i].getLastName()){
                    Professor temp = r.profs[i];
                    r.profs[i] = r.profs[j];
                    r.profs[j] = temp;
                }
            }
        }
    }
    for(int i=0; i<r.numOfStudents; i++){
        for(int j=i+1; j<r.numOfStudents; j++){
            //If there is a smaller element found on right of the array then swap it.
            string str1= r.stus[j].getId();
            string str2= r.stus[i].getId();
            if(str1.substr(0,1) < str2.substr(0,1)){
                Student temp = r.stus[i];
                r.stus[i] = r.stus[j];
                r.stus[j] = temp;
            }
        }
    }
    for (int i = 0; i < r.numOfProfessors; i++){
        out<<r.profs[i]<<endl;
    }
    for (int i = 0; i < r.numOfStudents; i++){
        out<<r.stus[i]<<endl;
    }
    return out;
}
// istream& operator>>(istream& in,University& r){

// }