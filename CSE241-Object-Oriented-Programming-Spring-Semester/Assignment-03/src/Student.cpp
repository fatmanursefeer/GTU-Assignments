#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

namespace PA3
{
    Student::Student()
    {
        courses = new Course*[10];  /* creates a 10 size dynamic array */
        name = "NoName";  /* because any name information it puts this variable */
        id = "NoID";  /* because any id information it puts this variable */
        coursesSize = 0;  /* array size = 0 */
        numberOfCourses = 10;  /* array capacity = 10 */
    }

    Student::Student(string studentName, string studentID)
    {
        courses = new Course*[10];  /* creates a 10 size dynamic array */
        name = studentName;
        id = studentID;
        coursesSize = 0;  /* array size = 0 */
        numberOfCourses = 10;  /* array capacity = 10 */
    }

    Student::Student(const Student& other)  /* copy constructor */
    {
        numberOfCourses = other.numberOfCourses;   /* equalizes capacities */
        coursesSize = other.coursesSize;   /* equalizes sizes */
        courses = new Course*[numberOfCourses];  /* creates new dynamic array */
        for(int i=0; i<numberOfCourses; i++)  /* and fills it with other object informations */
            courses[i] = other.courses[i];
    }

    Student& Student::operator =(const Student& other)   /* overloaded assigment operator */
    {
        if(this == &other)  /* if the objects are same then returns the itself */
            return *this;
        else{
            numberOfCourses = other.numberOfCourses;   /* equalizes capacities */
            coursesSize = other.coursesSize;   /* equalizes sizes */
            delete [] courses;     /* deletes the older array */
            courses = new Course*[numberOfCourses];  /* creates new dynamic array */
            for(int i=0; i<numberOfCourses; i++)
                courses[i] = other.courses[i];  /* and fills it with other object informations */
            return *this;
        }
    }

    string Student::getStudentName() const
    {
        return name;   /* returns name */
    }

    string Student::getStudentID() const
    {
        return id;  /* retruns id */
    }

    int Student::getCoursesSize() const
    {
        return coursesSize;  /* returns courses size */
    }

    void Student::setStudentName(string studentName)
    {
        name = studentName;  /* equalizes name with new one */
    }

    void Student::setStudentID(string studentID)
    {
        id = studentID;  /* equalizes id with new one */
    }

    void Student::addCourse(string courseCode, string courseName)
    {
        Course* temp = new Course(courseName, courseCode);   /* creates new dynamic object */
        if(coursesSize >= numberOfCourses){   /* if the array is full then increases the capacity */
            Course** temparr = new Course*[numberOfCourses + 10];  /* increase the capacity with 10 */
            for(int i=0; i<numberOfCourses; i++)  /* and fills the old informations */
                temparr[i] = courses[i];
            numberOfCourses += 10;
            delete [] courses;  /* deletes the older array */
            courses = temparr;  /* equalizes the arrays */
        }
        courses[coursesSize] = temp;  /* adds new student */
        coursesSize++;  /* increase the size */
    }

    void Student::deleteCourse(string courseCode, string courseName)
    {
        int index;
        for(int i=0; i<coursesSize; i++){  /* finds the index of the student */
            if((courses[i]->getCourseCode() == courseCode) && (courses[i]->getCourseName() == courseName)){
                index = i;
                break;
            }
        }
        for(int i=index; i<coursesSize-1; i++)
            courses[i] = courses[i+1];  /* shifts the students */
        coursesSize--;  /* decrease the size */
    }

    Student::~Student()   /* destructor */
    {
        for(int i=0; i<numberOfCourses; i++)
            delete [] courses[i];
        delete [] courses;
    }
}