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