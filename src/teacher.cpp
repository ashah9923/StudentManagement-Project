#include <iostream>
#include "../include/teacher.h"

teacher::teacher()
{

};

/*void teacher::addSubject(subject sub) {
  subjects.push_back(sub);
};

void teacher::clearSubjects()
{
    subjects.clear();
}*/

bool teacher::hasSubject(std::string subject_name) {                // checks if teacher teaches the subject
  for (subject sub : subjects) {                                    // range based for loop that goes through the subjects in the subject list
    if (sub.getSubjectName() == subject_name)
      return true;
  }

  return false;
};

/*std::vector<subject> teacher::getSubjects() {
  return subjects;
};

int teacher::getSubjectsSize()
{
  return subjects.size(); // returns size of vector
};

subject teacher::getSubject(int index)
{
  return subjects[index];
};*/