#ifndef TEACHER_H
#define TEACHER_H
#include "../include/person.h"
//#include "../include/subject.h"

#include <vector>

class teacher : public person
{
    protected:
    //std::vector<subject> subjects;
    public:
    teacher();
   // void addSubject(subject sub);
    bool hasSubject(std::string subject_name);
   // std::vector<subject> getSubjects();
   // subject getSubject(int);
    //int getSubjectsSize();
   // void clearSubjects();
};

#endif