#include <iostream>
#include "../include/person.h"

//SETS//
void person::setpersonName(std::string pN)
{
    personName = pN;
};
void person::setpersonAddress(std::string add)
{
    personAddress = add;
};
void person::setpersonAge(int age)
{
    personAge = age;
};
void person::setpersonID(int id)
{
    personID = id;
};
void person::setpersonGender(char gend)
{
    personGender = gend;
}

//GETS//

std::string person::getpersonAddress()
{
    return personAddress;
}

std::string person::getName()
{
    return personName;
}

int person::getpersonAge()
{
    return personAge;
}

int person::getpersonID()
{
    return personID;
}

char person::getpersonGender()
{
    return personGender;
}

// ADDING SUBJECTS

void person::addSubject(subject sub)
{
    subjects.push_back(sub);    //adds subject
};

void person::clearSubjects()
{
    subjects.clear();
}

subject person::getSubject(int index)
{
    return subjects[index];
};

    // taking index of vector
int person::getSubjectsSize()
{
    return subjects.size();   //returns size of vector
};