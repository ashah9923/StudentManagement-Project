#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include <map>
#include "../include/person.h"
#include "../include/club.h"

class student : public person
{   protected:
    std::map<std::string, int> grade_map;  // string is a key to the grade, each string will map to a int

    std::vector<club> clubs;
    public:
    student();  
    
    void setgrade(std::string, int);  //create these in student.cpp
    int getgrade(std::string subName);
    bool has_grade(std::string subName);

    void addClub(club act);
    void clearClubs();
    club getClub(int);
    int getClubSize();
};

#endif