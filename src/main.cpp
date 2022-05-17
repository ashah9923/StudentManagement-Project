#include <iostream>
#include <string>
#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/person.h"
#include "../include/personManager.h"

extern void ignoreCin();  // this finds the function that is anywhere in the project


int main() 
{
personManager pM;
char option;
do {
    system("cls");
    std::cout << "#########################" << std::endl;
    std::cout << "#   SCHOOL MANAGEMENT   #" <<std::endl;
    std::cout << "#########################" << '\n' << std::endl;
    std::cout << "1. Enter details" << std::endl;
    std::cout << "2. Show details" << std::endl;
    std::cout << "3. Search Record" << std::endl;
    std::cout << "4. Update Record" << std::endl;
    std::cout << "5. Delete Record" << std::endl;
    std::cout << "6. Set Grades" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "#########################" << std::endl;

    std::cin >> option;
    //std::cin.ignore();
    ignoreCin();

    switch(option)
    {
        case '1':{
            system("cls");
            char option;
            std::cout << "Would you like to enter (S)tudent or (T)eacher details?: " << std::endl;
            std::cin >> option;
            ignoreCin();
            system("cls");
            if(option == 'S' || option == 's')
            {
                pM.addStudent();    // This will add the student to the list of students which is within the student manager
            }
            else if(option == 'T' || option == 't')
            {
                pM.addTeacher();
            }
            else
            {
                std::cout << "No valid input.. please try again" << std::endl;
            }
            system("pause");
            break;
        }
        
        case '2':{
            system("cls");
            char option;
            std::cout << "Show (S)tudent, (T)eacher or (A)ll details?: " << std::endl;
            std::cin >> option;
            ignoreCin();
            system("cls");
            if(option == 'S' || option == 's')
            {
                pM.showStudentList();    // This will add the student to the list of students which is within the student manager
            }
            else if(option == 'T' || option == 't')
            {
                pM.showTeacherList();
            }
            else if(option == 'A' || option == 'a')
            {
                pM.showTeacherList();
                pM.showStudentList();
            }
            else
            {
                std::cout << "No valid input.. please try again" << std::endl;
            }
            system("pause");
            break;
        }
        
        case '3':{
            system("cls");
            char option;
            std::cout << "Would you like to search (S)tudent or (T)eacher details?: " << std::endl;
            std::cin >> option;
            ignoreCin();
            system("cls");
            if(option == 'S' || option == 's')
            {
                pM.searchStudentList();    // This will add the student to the list of students which is within the student manager
            }
            else if(option == 'T' || option == 't')
            {
                pM.searchTeacherList();
            }
            else
            {
                std::cout << "No valid input.. please try again" << std::endl;
            }
            system("pause");
            break;
        }
        
        case '4':{
            system("cls");
            char option;
            std::cout << "Would you like to update (S)tudent or (T)eacher details?: " << std::endl;
            std::cin >> option;
            ignoreCin();
            system("cls");
            if(option == 'S' || option == 's')
            {
                pM.updateStudentList();    // This will add the student to the list of students which is within the student manager
            }
            else if(option == 'T' || option == 't')
            {
                pM.updateTeacherList();
            }
            else
            {
                std::cout << "No valid input.. please try again" << std::endl;
            }
            system("pause");
            break;
        }
        
        case '5':{
            system("cls");
            char option;
            std::cout << "Would you like to delete (S)tudent or (T)eacher details?: " << std::endl;
            std::cin >> option;
            ignoreCin();
            system("cls");
            if(option == 'S' || option == 's')
            {
                pM.deleteStudentData();    // This will add the student to the list of students which is within the student manager
            }
            else if(option == 'T' || option == 't')
            {
                pM.deleteTeacherData();
            }
            else
            {
                std::cout << "No valid input.. please try again" << std::endl;
            }
            system("pause");
            break;
        }
        
        case '6': {
            pM.setGrade();
            break;
        }

        case '7':{
            // s1.addStudent();
            return 0;
            break;
        }
        
        default:{
            std::cout << "Invalid input" << std::endl;
            system("pause");
        }
    }

}while(option !='7');
}

