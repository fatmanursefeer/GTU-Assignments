#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

namespace PA3
{
    class Student;   /* for Student** students */
    
    class Course
    {
    public:
        Course();  /* no parameter constructor */
        Course(string courseName, string courseCode);  /* constructor takes two parameter */
        Course(const Course& other);   /* copy constructor */
        Course& operator =(const Course& other);   /* overloaded assigment operator */
        string getCourseName() const;  /* getter for name */
        string getCourseCode() const;  /* getter for code */
        int getStudentsSize() const;  /* getter for size */
        void setCourseName(string courseName);  /* setter for name */
        void setCourseCode(string courseCode);  /* setter for code */
        void addStudent(string studentName, string studentID);  /* this function adds the student */
        void deleteStudent(string studentName, string studentID);   /* this function deletes the student */
        ~Course();   /* destructor */
        Student** students;  /* dynamic array */
    private:
        string name;
        string code;
        int studentsSize, numberOfStudents;
    };
}

#endif