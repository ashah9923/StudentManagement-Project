#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include "../include/student.h"
#include "../include/teacher.h"

class personManager 
{
    private:
    student studentList[50]; // studentList array that holds 50 students
    int curStudent = 0;  //current student

    teacher teacherList[10];
    int curTeacher = 0;


    public:
    void addStudent();
    void showStudentList();
    void searchStudentList();
    void updateStudentList();
    void deleteStudentData();

    void addTeacher();
    void showTeacherList();
    void searchTeacherList();
    void updateTeacherList();
    void deleteTeacherData();

    int findIndexofStudent(int);
    int findIndexofTeacher(int);

    void setGrade();
};


#endif