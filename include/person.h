#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "../include/subject.h"
#include <vector>

class person
{
    protected:
    std::string personName, personAddress;
    int personAge, personID = 0;
    char personGender;
    std::vector<subject> subjects;      // initialised vector of subjects  layout - 'vector<type> name'

    public:
    void setpersonName(std::string);
    void setpersonAddress(std::string);
    void setpersonAge(int);
    void setpersonID(int);
    void setpersonGender(char);

    std::string getpersonAddress();
    std::string getName();
    int getpersonAge();
    int getpersonID();
    char getpersonGender();

    void addSubject(subject sub);
    subject getSubject(int);
    int getSubjectsSize();
    void clearSubjects();
    
};
#endif
