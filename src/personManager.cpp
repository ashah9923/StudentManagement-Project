#include "../include/personManager.h"
#include "../include/subject.h"
#include "../include/club.h"
#include <iostream>
#include <limits>
#include <stdexcept>

void ignoreCin()  //function to ignore buffers
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void personManager::addStudent()
{
    
    student newStudent = student();
   
    std::string userInput;   

    std::cout << "Enter student details: " << std::endl;
   
    std::cout << "Address: " << std::endl;
    std::getline(std::cin, userInput);
    newStudent.setpersonAddress(userInput);  // sets new users address with the user input
    
    std::cout << "Name: " << std::endl;
    std::getline(std::cin, userInput);
    newStudent.setpersonName(userInput);
    
    int age;
    while (true)
    {
        std::cout << "Age:" << std::endl;
        std::cin >> userInput;
        ignoreCin();

        try 
        {
            age = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter your age.." << std::endl;
        }
    }
    newStudent.setpersonAge(age);

    std::cout << "Gender: " << std::endl;
    std::cin >> userInput;
    ignoreCin();
    newStudent.setpersonGender(userInput[0]);   // takes first element of string which is essentially an array of chars

    newStudent.setpersonID(curStudent + 100);  //automates ID to student

    int n;
    while(true)
    {
    std::cout << "How many Subjects are you enrolled on? : " << std::endl;
    std::cin >> userInput;

    ignoreCin();
    try 
        {
            n = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the number of subjects.." << std::endl;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        std::string userInput;
        teacher t;
        bool exit_loop = false;

        while (true) {
            std::cout << "Please input the teacher of the subject  " << i << " (or type 'skip'): " << std::endl;   
            //std::cout << "please input subject " << i << ": " << std::endl;
            std::getline(std::cin, userInput);
            
            if (userInput == "skip") {
                exit_loop = true;
                break;
            }

            bool teacher_found = false;
        
            for (int i = 0; i <= curTeacher; i++) {
                if (teacherList[i].getName() == userInput) {
                    t = teacherList[i];
                    teacher_found = true;
                    break;
                }
            }

            if (!teacher_found)
                std::cout << "teacher not found" << std::endl;
            else
                break;
        }

        if (exit_loop)
            break;

        while (true) {
            std::cout << "Please input subject name " << i << ": " << std::endl;
            std::getline(std::cin, userInput);

            if (userInput == "skip") {
                exit_loop = true;
                break;
            }
            
            if (t.hasSubject(userInput))
                break;

            std::cout << "subject under this teacher not found" << std::endl;
        }

        if (exit_loop)
            break;

        newStudent.addSubject(subject(userInput));
    }

    while(true)
    {
    std::cout << "How many Clubs are you in? : " << std::endl;
    std::cin >> userInput;
    ignoreCin();
    try 
        {
            n = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the number of clubs.." << std::endl;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::string userInput;        
        std::cout << "please input club " << i << ": " << std::endl;
        std::getline(std::cin, userInput);
        newStudent.addClub(club(userInput));
    }

    for(int studentIndex = 0; studentIndex < 50; studentIndex++)
    {
        if(studentList[studentIndex].getpersonID() == 0)  // This shows that as long as this slot aint been used, set the index to a student
        {
            studentList[studentIndex] = newStudent;    // studentIndex = 0 , thus 1st element is set to newstudent
            curStudent++;                           // updates curStudent
            return;
        }
    }

    std::cout << "No more spaces left for student.. " << std::endl;
};

void personManager::showStudentList()
{
    //system("cls");
    if(curStudent == 0)
    {
        std::cout << "There are no students." << std::endl;
        return;   // returns and exits function
    }


    for (int student = 0; student < 50; student++)
    {
        if(studentList[student].getpersonID() != 0)   
        {
            std::cout << "============================================================" << std::endl;
            std::cout << "Students Address: " << studentList[student].getpersonAddress() << std::endl;
            std::cout << "Students Name: " << studentList[student].getName() << std::endl; 
            std::cout << "Students Age: " << studentList[student].getpersonAge() << std::endl;
            std::cout << "Students Gender: " << studentList[student].getpersonGender() << std::endl;
            std::cout << "Students ID: " << studentList[student].getpersonID() << std::endl;

            for (int i = 0; i < studentList[student].getSubjectsSize(); i++) {
                std::string subName = studentList[student].getSubject(i).getSubjectName();

                std::cout << "Subject " << i + 1 << ": " << subName;

                if (studentList[student].has_grade(subName))
                    std::cout << " | Marks: " << studentList[student].getgrade(subName);

                std::cout << std::endl;
            }

            for (int i = 0; i < studentList[student].getClubSize(); i++) {
                std::cout << "Club " << i + 1 << ": " <<
                    studentList[student].getClub(i).getActivity() << std::endl;
            }

            std::cout << "============================================================" << std::endl;
        }
    }
};

void personManager::searchStudentList()
{
    std::string userInput;
    int studentID;
    while(true)
    {
    std::cout << "Enter Student ID: " << std::endl;
    std::cin >>  userInput;
    ignoreCin();
    try 
        {
            studentID = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the numerical ID.." << std::endl;
        }
    }    
    int studentIndex = findIndexofStudent(studentID);
    if(studentIndex >=0)
    {
        std::cout << "============================================================" << std::endl;
        std::cout<< "Student Name: " << studentList[studentIndex].getName() << std::endl;
        std::cout<< "Student Age: " << studentList[studentIndex].getpersonAge() << std::endl;
        std::cout<< "Student Gender: " << studentList[studentIndex].getpersonGender() << std::endl;
        std::cout<< "Student Address: " << studentList[studentIndex].getpersonAddress() << std::endl;
        std::cout<< "Student ID: " << studentList[studentIndex].getpersonID() << std::endl;
        for (int i = 0; i < studentList[studentIndex].getSubjectsSize(); i++) {
                std::string subName = studentList[studentIndex].getSubject(i).getSubjectName();

                std::cout << "Subject " << i + 1 << ": " << subName;

                if (studentList[studentIndex].has_grade(subName))
                    std::cout << " | Marks: " << studentList[studentIndex].getgrade(subName);

                std::cout << std::endl;
            }
            for (int i = 0; i < studentList[studentIndex].getClubSize(); i++) {
                std::cout << "Club " << i + 1 << ": " <<
                    studentList[studentIndex].getClub(i).getActivity() << std::endl;
            }

            std::cout << "============================================================" << std::endl;
        
    }
    else
    {
        std::cout << "Student with ID does not exist" << std::endl;
    }
};

void personManager::updateStudentList()
{
    std::string userInput;
    std::cout << "Enter the ID of the Student you wish to update: " << std::endl;
    int studentID;
    while(true)
    {
        std::cout << "Enter Student ID: " << std::endl;
        std::cin >>  userInput;
        ignoreCin();
        try 
        {
            studentID = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the numerical ID.." << std::endl;
        }
    }

    int studentIndex = findIndexofStudent(studentID);
    
    if(studentIndex >=0)
    {
        std::cout << "Enter Name: " << std::endl;
        std::getline(std::cin, userInput);
        studentList[studentIndex].setpersonName(userInput);
        
        std::cout << "Enter Address: " << std::endl;
        std::getline(std::cin, userInput);
        studentList[studentIndex].setpersonAddress(userInput);

        int age;
        while (true)
        {
            std::cout << "Enter Age:" << std::endl;
            std::cin >> userInput;
            ignoreCin();

            try 
            {
                age = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
                break;
            }

            catch (std::invalid_argument e) 
            {
                std::cout << "Input not recognised, please enter your age.." << std::endl;
            }
        }
        studentList[studentIndex].setpersonAge(age);

        std::cout << "Enter Gender: " << std::endl;
        std::cin >> userInput;
        ignoreCin();
        studentList[studentIndex].setpersonGender(userInput[0]);

        int n;
        while(true)
        {
        std::cout << "How many Subjects are you enrolled on? : " << std::endl;
        std::cin >> userInput;
        ignoreCin();
        try 
            {
                n = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
                break;
            }

            catch (std::invalid_argument e) 
            {
                std::cout << "Input not recognised, please enter the number of subjects.." << std::endl;
            }
        }
        studentList[studentIndex].clearSubjects();
        for(int i = 1; i <= n; i++)
        {
            std::string userInput;
            teacher t;
            bool exit_loop = false;

            while (true) {
                std::cout << "please input teacher of subject " << i << ": " << std::endl;   
                //std::cout << "please input subject " << i << ": " << std::endl;
                std::getline(std::cin, userInput);
                
                if (userInput == "skip") {
                    exit_loop = true;
                    break;
                }

                bool teacher_found = false;
            
                for (int i = 0; i <= curTeacher; i++) {
                    if (teacherList[i].getName() == userInput) {
                        t = teacherList[i];
                        teacher_found = true;
                        break;
                    }
                }

                if (!teacher_found)
                    std::cout << "teacher not found" << std::endl;
                else
                    break;
            }

            if (exit_loop)
                break;

            while (true) {
                std::cout << "please input subject name" << i << ": " << std::endl;
                std::getline(std::cin, userInput);

                if (userInput == "skip") {
                    exit_loop = true;
                    break;
                }
                
                if (t.hasSubject(userInput))
                    break;

                std::cout << "subject under this teacher not found" << std::endl;
            }

            if (exit_loop)
                break;
            
            studentList[studentIndex].addSubject(subject(userInput));
        }
        while(true)
        {
            std::cout << "How many Clubs are you in? : " << std::endl;
            std::cin >> userInput;
            ignoreCin();
            try 
                {
                    n = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
                    break;
                }

                catch (std::invalid_argument e) 
                {
                    std::cout << "Input not recognised, please enter the number of clubs.." << std::endl;
                }
        }
        studentList[studentIndex].clearClubs();
        for(int i = 1; i <= n; i++)
        {
            std::string userInput;        
            std::cout << "please input club " << i << ": " << std::endl;
            std::getline(std::cin, userInput);
            studentList[studentIndex].addClub(club(userInput));
        }
    }
    else
    {
        std::cout << "Student with ID does not exist" << std::endl;
    }
};

void personManager::deleteStudentData()    // deletes fine but id needs to be changed as you delete
{
    std::string userInput;
    int studentID;
    while(true)
    {
        std::cout << "Enter Student ID: " << std::endl;
        std::cin >>  userInput;
        ignoreCin();
        try 
        {
            studentID = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the numerical ID.." << std::endl;
        }

    }
    int studentIndex = findIndexofStudent(studentID);
    if(studentIndex >=0)
    {
        char press;
        std::cout << "Are you sure you want to delete this persons data? All information will be lost." << std::endl;
        std::cout << "Student Name: " << studentList[studentIndex].getName() << std::endl;
        std::cout << "(Y)es/(N)o" << std::endl;
        std::cin >> press;
        ignoreCin();
        if(press == 'y' || press == 'Y')
        {
            for(studentIndex; studentIndex < 49; studentIndex++)  // studenIndex<49 as it is the index in array
            {
                studentList[studentIndex] = studentList[studentIndex + 1];  //i.e position 3 takes position 4s info etc...
            }
            studentList[49] = student(); // sets last element, i.e 50th student, to blank
        }
    }
    else
    {
        std::cout << "No such ID found" << std::endl;
    }
};

//TEACHER //
//=================================================================================//

void personManager::addTeacher()
{
    
    teacher newTeacher = teacher();
   
    std::string userInput;   

    std::cout << "Enter teacher details: " << std::endl;
    //std::cin.ignore();
    std::cout << "Address: " << std::endl;
    std::getline(std::cin, userInput);
    newTeacher.setpersonAddress(userInput);  // sets new users address with the user input
    // getline(std::cin, personAddress);
    //std::cin.ignore();  // when more than 1 word entered for address name gets skipped
    std::cout << "Name: " << std::endl;
    std::getline(std::cin, userInput);
    newTeacher.setpersonName(userInput);
    // getline(std::cin, personName);
    int age;
    while (true) {
        std::cout << "Age:" << std::endl;
        std::cin >> userInput;
        ignoreCin();

        try {
            age = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) {
            std::cout << "Input not recognised, please enter your age.." << std::endl;
        }
    }

    newTeacher.setpersonAge(age);
    std::cout << "Gender: " << std::endl;
    std::cin >> userInput;
    ignoreCin();
    newTeacher.setpersonGender(userInput[0]);   // takes first element of string which is essentially an array of chars

    int n;
    while(true)
    {
        std::cout << "Enter the number of subjects you teach: " << std::endl;
        std::cin >> userInput;
        ignoreCin();

        try 
        {
            n = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the number of subjects you teach.." << std::endl;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        std::string userInput;        
        std::cout << "please input subject " << i << ": " << std::endl;
        std::getline(std::cin, userInput);
        newTeacher.addSubject(subject(userInput));
    }

    newTeacher.setpersonID(curTeacher + 10);  //automates ID to student

    // student newStudent2 = student(age);   creates student and sets age to age input above

    for(int teacherIndex = 0; teacherIndex < 10; teacherIndex++)
    {
        if(teacherList[teacherIndex].getpersonID() == 0)  // This shows that as long as this slot aint been used, set the index to a student
        {
            teacherList[teacherIndex] = newTeacher;    // studentIndex = 0 , thus 1st element is set to newstudent
            curTeacher++;                           // updates curStudent
            return;
        }
    }

    std::cout << "No space left for additional teacher.. " << std::endl;

};

void personManager::showTeacherList()
{
    system("cls");
    if(curTeacher == 0)
    {
        std::cout << "There are no teachers." << std::endl;
        return;   // returns and exits function
    }


    for (int teacher = 0; teacher < 10; teacher++)
    {
        if(teacherList[teacher].getpersonID() != 0)
        {
            std::cout << "============================================================" << std::endl;
            std::cout << "Teachers Address: " << teacherList[teacher].getpersonAddress() << std::endl;
            std::cout << "Teachers Name: " << teacherList[teacher].getName() << std::endl; 
            std::cout << "Teachers Age: " << teacherList[teacher].getpersonAge() << std::endl;
            std::cout << "Teachers Gender: " << teacherList[teacher].getpersonGender() << std::endl;
            std::cout << "Teachers email: " << teacherList[teacher].getName() << teacherList[teacher].getpersonID() << "@gmail.com" << std::endl;
            std::cout << "Teachers ID: " << teacherList[teacher].getpersonID() << std::endl;
            for (int i = 0; i < teacherList[teacher].getSubjectsSize(); i++)
            {
                std::string subName = teacherList[teacher].getSubject(i).getSubjectName();

                std::cout << "Subject " << i + 1 << ": " << subName;

                std::cout << std::endl;
            }
            std::cout << "============================================================" << std::endl;
        }
    }
};

void personManager::searchTeacherList()
{
    std::string userInput;
    int teacherID;
    while(true)
    {
    std::cout << "Enter Teacher ID: " << std::endl;
    std::cin >>  userInput;
    ignoreCin();
    try 
        {
            teacherID = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the numerical ID.." << std::endl;
        }
    }
    int teacherIndex = findIndexofTeacher(teacherID);
    if(teacherIndex >=0)
    {
        std::cout << "============================================================" << std::endl;
            std::cout << "Teachers Address: " << teacherList[teacherIndex].getpersonAddress() << std::endl;
            std::cout << "Teachers Name: " << teacherList[teacherIndex].getName() << std::endl; 
            std::cout << "Teachers Age: " << teacherList[teacherIndex].getpersonAge() << std::endl;
            std::cout << "Teachers Gender: " << teacherList[teacherIndex].getpersonGender() << std::endl;
            std::cout << "Teachers email: " << teacherList[teacherIndex].getName() << teacherList[teacherIndex].getpersonID() << "@gmail.com" << std::endl;
            std::cout << "Teachers ID: " << teacherList[teacherIndex].getpersonID() << std::endl;
            for (int i = 0; i < teacherList[teacherIndex].getSubjectsSize(); i++)
            {
                std::string subName = teacherList[teacherIndex].getSubject(i).getSubjectName();

                std::cout << "Subject " << i + 1 << ": " << subName;

                std::cout << std::endl;
            }
            std::cout << "============================================================" << std::endl;
    }
    else
    {
        std::cout << "Teacher with ID does not exist" << std::endl;
    }
};


void personManager::updateTeacherList()
{
    std::string userInput;
    std::cout << "Enter the ID of the Teacher you wish to update: " << std::endl;
    int teacherID;
    while(true)
    {
    std::cout << "Enter Teacher ID: " << std::endl;
    std::cin >>  userInput;
    ignoreCin();
    try 
        {
            teacherID = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the numerical ID.." << std::endl;
        }
    }
    int teacherIndex = findIndexofTeacher(teacherID);
    if(teacherIndex >=0)
    {
        std::cout << "Enter Name: " << std::endl;
        std::getline(std::cin, userInput);
        teacherList[teacherIndex].setpersonName(userInput);

        std::cout << "Enter Address: " << std::endl;
        std::getline(std::cin, userInput);
        teacherList[teacherIndex].setpersonAddress(userInput);

        int age;
        while (true) {
            std::cout << "Enter Age:" << std::endl;
            std::cin >> userInput;
            ignoreCin();

            try {
                age = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
                break;
            }

            catch (std::invalid_argument e) {
                std::cout << "Input not recognised, please enter your age.." << std::endl;
            }
        }
        teacherList[teacherIndex].setpersonAge(age);

        std::cout << "Gender: " << std::endl;
        std::cin >> userInput;
        ignoreCin();
        teacherList[teacherIndex].setpersonGender(userInput[0]);

        int n;
        while(true)
        {
            std::cout << "Enter the number of subjects you teach: " << std::endl;
            std::cin >> userInput;
            ignoreCin();

            try 
            {
                n = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
                break;
            }

            catch (std::invalid_argument e) 
            {
                std::cout << "Input not recognised, please enter the number of subjects you teach.." << std::endl;
            }
        }
        teacherList[teacherIndex].clearSubjects();
        for(int i = 1; i <= n; i++)
        {
            std::string userInput;        
            std::cout << "please input subject " << i << ": " << std::endl;
            std::getline(std::cin, userInput);
            teacherList[teacherIndex].addSubject(subject(userInput));
        }
    }
    else
    {
        std::cout << "Teacher with ID does not exist" << std::endl;
    }
};

void personManager::deleteTeacherData()    // deletes fine but id needs to be changed as you delete
{
    std::string userInput;
    std::cout << "Enter the ID of the Teacher you wish to delete: " << std::endl;
    int teacherID;
    while(true)
    {
    std::cout << "Enter Teacher ID: " << std::endl;
    std::cin >>  userInput;
    ignoreCin();
    try 
        {
            teacherID = stoi(userInput);  //string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e) 
        {
            std::cout << "Input not recognised, please enter the numerical ID.." << std::endl;
        }
    }
    int teacherIndex = findIndexofTeacher(teacherID);
    if(teacherIndex >=0)
    {
        char press;
        std::cout << "Are you sure you want to delete this Teachers data? All information will be lost." << std::endl;
        std::cout << "Teachers Name: "<< teacherList[teacherIndex].getName() << std::endl;
        std::cout << "(Y)es/(N)o" << std::endl;
        std::cin >> press;
        ignoreCin();
        if(press == 'y' || press == 'Y')
        {
            for(teacherIndex; teacherIndex < 9; teacherIndex++)  // teacherIndex<9 as it is the index in array
            {
                teacherList[teacherIndex] = teacherList[teacherIndex + 1];  //i.e position 3 takes position 4s info etc...
            }
            teacherList[9] = teacher(); // sets last element, i.e 50th student, to blank
        }
    }
    else
    {
        std::cout << "No such ID found" << std::endl;
    }
};

int personManager::findIndexofStudent(int studentID)
{
    for(int student = 0; student < 50; student++)  //loop through students and return student index in array
        {
        if(studentList[student].getpersonID() == studentID)
        {
            return student;
        }
    }
    return -1 ;  //didnt find student (-1 is out of array)
};
int personManager::findIndexofTeacher(int teacherID)
{
    for(int teacher = 0; teacher < 10; teacher++)  //loop through teachers and return teacher index in array
        {
        if(teacherList[teacher].getpersonID() == teacherID)
        {
            return teacher;
        }
    }
    return -1 ;  //didnt find teacher (-1 is out of array)
};

//--------------------------------------------------------------------
void personManager::setGrade()
{
    std::string student_id;
    std::string teacher_id;
    int student_index = 0;
    int teacher_index = 0;

    int studentID;
    while (true)
    {
        std::cout << "Enter Student ID: " << std::endl;
        std::getline(std::cin, student_id);
        if (student_id == "back")
            return;
        try
        {
            studentID = stoi(student_id); // string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e)
        {
            std::cout << "Input not recognised, please enter the numerical ID.." << std::endl;
        }
    }
        int studentIndex = findIndexofStudent(studentID);

    
    if(studentIndex>=0){
    int teacherID;
    while (true)
    {
        std::cout << "Enter Teacher ID: " << std::endl;
        std::getline(std::cin, teacher_id);
        if (teacher_id == "back")
            return;
        try
        {
            teacherID = stoi(teacher_id); // string has been converted to int type --  try-catch for error handling
            break;
        }

        catch (std::invalid_argument e)
        {
            std::cout << "Input not recognised, please enter the numerical ID.." << std::endl;
        }
    }
        int teacherIndex = findIndexofTeacher(teacherID);

        

       

        if(teacherIndex>=0){
        std::string subject_name;

        while (true)
        {
            std::cout << "Enter subject name" << std::endl;

            std::getline(std::cin, subject_name);

            if (subject_name == "back")
                return;

            if (teacherList[teacherIndex].hasSubject(subject_name))
                break;

            std::cout << "Subject not found" << std::endl;
        }
        
        std::string userInput;
        int grade;
        while (true)
        {
            system("cls");
            std::cout << "Enter Marks" << std::endl;
            std::cin >> userInput;
            ignoreCin();
            try
            {
                grade = stoi(userInput);
                if (grade >= 0 && grade <= 100)
                {
                    break;
                }
                else
                {
                    std::cout << "Marks must be out of 100" << std::endl;
                    system("pause");
                };
            }
            catch (std::invalid_argument e)
            {
                std::cout << "Input not recognised, please try again.." << '\n';
                system("pause");
            }
        }
        studentList[studentIndex].setgrade(subject_name, grade);
        }
        else{
            std::cout << "no such teacher id" << std::endl;
            system("pause");
        }
        }
        else{
            std::cout << "no such student id"<< std::endl;
            system("pause");
        }
    }