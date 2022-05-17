#include <iostream>
#include "../include/teacher.h"

teacher::teacher()
{

};


bool teacher::hasSubject(std::string subject_name) {                // checks if teacher teaches the subject
  for (subject sub : subjects) {                                    // range based for loop that goes through the subjects in the subject list
    if (sub.getSubjectName() == subject_name)
      return true;
  }

  return false;
};
