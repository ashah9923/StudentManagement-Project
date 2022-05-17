#ifndef TEACHER_H
#define TEACHER_H
#include "../include/person.h"
//#include "../include/subject.h"

#include <vector>

class teacher : public person
{
    public:
    teacher();
    bool hasSubject(std::string subject_name);
};

#endif