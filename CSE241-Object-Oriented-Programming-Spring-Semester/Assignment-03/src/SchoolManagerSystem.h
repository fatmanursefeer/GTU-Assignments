#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

namespace PA3
{
    class SchoolManagementSystem
    {
    public:
        SchoolManagementSystem();  /* no parameter constructor */
        SchoolManagementSystem(const SchoolManagementSystem& other);  /* copy constructor */
        SchoolManagementSystem& operator =(const SchoolManagementSystem& other);  /* overloaded assigment operator */
        void mainMenu();  /* this function to contain the main menu and execute it */
        void addStudent(string studentName, string studentID);  /* this function adds the student */
        void addCourse(string courseCode, string courseName);   /* this function adds the course */
        void splitForStudent(string& line, string& studentName, string& studentID);   /* this function takes the line and split it for student informations */
        void splitForCourse(string& line, string& courseCode, string& courseName);  /* this function takes the line and split it for course informations */
    private:
        Student** smsStudents;  /* dynamic array for students */
        Course** smsCourses;  /* dynamic array for courses */
        int numberOfStudent, studentSize;
        int numberOfCourse, courseSize;
    };
}

#endif