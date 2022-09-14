#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

namespace PA3
{
    Course::Course()
    {
        students = new Student*[10];  /* creates a 10 size dynamic array */
        name = "NoName";  /* because any name information it puts this variable */
        code = "NoCode";  /* because any code information it puts this variable */
        studentsSize = 0;  /* array size = 0 */
        numberOfStudents = 10;  /* array capacity = 10 */
    }

    Course::Course(string courseName, string courseCode)
    {
        students = new Student*[10];  /* creates a 10 size dynamic array */
        name = courseName;
        code = courseCode;
        studentsSize = 0;  /* array size = 0 */
        numberOfStudents = 10;  /* array capacity = 10 */
    }

    Course::Course(const Course& other)  /* copy constructor */
    {
        numberOfStudents = other.numberOfStudents;   /* equalizes capacities */
        studentsSize = other.studentsSize;   /* equalizes sizes */
        students = new Student*[numberOfStudents];  /* creates new dynamic array */
        for(int i=0; i<numberOfStudents; i++)
            students[i] = other.students[i];  /* and fills it with other object informations */
    }

    Course& Course::operator =(const Course& other)   /* overloaded assigment operator */
    {
        if(this == &other)  /* if the objects are same then returns the itself */
            return *this;
        else{
            numberOfStudents = other.numberOfStudents;   /* equalizes capacities */
            studentsSize = other.studentsSize;  /* equalizes sizes */
            delete [] students;  /* deletes the older array */
            students = new Student*[numberOfStudents];  /* creates new dynamic array */
            for(int i=0; i<numberOfStudents; i++)
                students[i] = other.students[i];  /* and fills it with other object informations */
            return *this;
        }
    }

    string Course::getCourseName() const
    {
        return name;   /* returns name */
    }

    string Course::getCourseCode() const
    {
        return code;   /* returns code */
    }

    int Course::getStudentsSize() const
    {
        return studentsSize;   /* returns students size */
    }

    void Course::setCourseName(string courseName)
    {
        name = courseName; /* equalizes name with new one */
    }

    void Course::setCourseCode(string courseCode)
    {
        code = courseCode; /* equalizes code with new one */
    }

    void Course::addStudent(string studenetName, string studentID)
    {
        Student* temp = new Student(studenetName, studentID);   /* creates new dynamic object */
        if(studentsSize >= numberOfStudents){  /* if the array is full then increases the capacity */
            Student** temparr = new Student*[numberOfStudents + 10];  /* increase the capacity with 10 */
            for(int i=0; i<numberOfStudents; i++)   /* and fills the old informations */
                temparr[i] = students[i];
            numberOfStudents += 10;
            delete [] students; /* deletes the older array */
            students = temparr;  /* equalizes the arrays */
        }
        students[studentsSize] = temp;  /* adds new course */
        studentsSize++;   /* increase the size */
    }

    void Course::deleteStudent(string studentName, string studentID)
    {
        int index;
        for(int i=0; i<studentsSize; i++){ /* finds the index of the course */
            if((students[i]->getStudentName() == studentName) && (students[i]->getStudentID() == studentID)){
                index = i;
                break;
            }
        }
        for(int i=index; i<studentsSize-1; i++)
            students[i] = students[i+1];  /* shifts the courses */
        studentsSize--;  /* decrease the size */
    }

    Course::~Course()  /* destructor */
    {
        for(int i=0; i<numberOfStudents; i++)
            delete [] students[i];
        delete [] students;
    }
}

