#include "../include/student.h"
#include "../include/person.h"
#include <iostream>

student::student()   // set defaults within constuctors
{

};

void student::setgrade(std::string subName,  int grade)
{
    grade_map[subName] = grade;
}

int student::getgrade(std::string subName) {        
    return grade_map[subName];
}

bool student::has_grade(std::string subName) {                  //checks to see whether subName is in the grademap
    return grade_map.count(subName);
}

// ADDING SUBJECTS
/*void student::addSubject(subject sub)
{
    subjects.push_back(sub);    //adds subject
};

void student::clearSubjects()
{
    subjects.clear();
}

subject student::getSubject(int index)
{
    return subjects[index];
};

    // taking index of vector
int student::getSubjectsSize()
{
    return subjects.size();   //returns size of vector
};*/

// ADDING CLUBS

void student::addClub(club act)
{
    clubs.push_back(act);
}; 

void student::clearClubs()
{
    clubs.clear();
}

club student::getClub(int index)
{
    return clubs[index];
};

int student::getClubSize()
{
    return clubs.size();
};