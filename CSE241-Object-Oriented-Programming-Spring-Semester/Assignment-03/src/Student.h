#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

namespace PA3
{
    class Course;  /* For Course** courses */
    
    class Student
    {
    public:
        Student();   /* No parameter constructor */
        Student(string studentName, string studentID);  /* Constructor takes two parameter */
        Student(const Student& other);   /* copy constructor */
        Student& operator =(const Student& other);   /* Overloaded assigment operator */
        string getStudentName() const;  /* getter for name */
        string getStudentID() const;  /* getter for id */
        int getCoursesSize() const;  /* getter for size */
        void setStudentName(string studentName);   /* setter for name */
        void setStudentID(string studentID);   /* setter for id */
        void addCourse(string courseCode, string courseName);   /* this function adds the course */
        void deleteCourse(string courseCode, string courseName);  /* this function deletes the course */
        ~Student();  /* destructor */
        Course** courses;  /* dynamic array */
    private:
        string name;
        string id;
        int coursesSize, numberOfCourses;
    };
}

#endif