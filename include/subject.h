#ifndef SUBJECTS_H
#define SUBJECTS_H
#include <iostream>

class subject
{
    protected:
    std::string subName;
   // std::string teacherName;
    public:
    subject(std::string subName) {                       // constructor is like a function that is called upon creating the obejct
        this->subName = subName;                        // this-> gets the class's member, put subName from constructor parameter into class's subName var
    }                                                  // points to base variable and sets to parameter

    std::string getSubjectName();
    void setSubjectName(std::string);
};

#endif

