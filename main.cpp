#include <iostream>
#include <string.h>
#include "University.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
using namespace std;
int main(){
    // Student s[12];
    // Professor p[3];
    Student* s=new Student[12];
    // Course** c=new Course*[7];
    for (int i = 0; i < 12; i++){
        cin>> s[i];
    }
    Professor* p=new Professor[3];
    for (int i = 0; i < 3; i++){
        cin>> p[i];
    }
    // University myUniversity(10000,3,12,p,s);
    
    // delete[] s;
    // // delete[] c;
    // delete[] p;
    
}