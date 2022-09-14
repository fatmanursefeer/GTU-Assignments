#include <iostream>
#include <string>
#include "SchoolManagerSystem.h"

using namespace std;

namespace PA3
{
    SchoolManagementSystem::SchoolManagementSystem()
    {
        numberOfStudent = 0;  /* student array size = 0 */
        numberOfCourse = 0;  /* course array size = 0 */
        smsStudents = new Student*[10];  /* creates a 10 size dynamic array */
        smsCourses = new Course*[10];  /* creates a 10 size dynamic array */
        studentSize = 10;  /* student array capacity = 10 */
        courseSize = 10;  /* course array capacity = 10 */
        mainMenu();    /* calls the main menu */
    }

    SchoolManagementSystem::SchoolManagementSystem(const SchoolManagementSystem& other)  /* copy constructor */
    {
        numberOfCourse = other.numberOfCourse;   /* equalizes sizes */
        numberOfStudent = other.numberOfStudent;   /* equalizes sizes */
        studentSize = other.studentSize;   /* equalizes capacities */
        courseSize = other.courseSize;   /* equalizes capacities */
        smsStudents = new Student*[studentSize];  /* creates new dynamic array */
        smsCourses = new Course*[courseSize];    /* creates new dynamic array */
        for(int i=0; i<studentSize; i++)
            smsStudents[i] = other.smsStudents[i]; /* and fills it with other object informations */
        for(int i=0; i<courseSize; i++)
            smsCourses[i] = other.smsCourses[i]; /* and fills it with other object informations */
    }

    SchoolManagementSystem& SchoolManagementSystem::operator =(const SchoolManagementSystem& other)   /* overloaded assigment operator */
    {
        if(this == &other)  /* if the objects are same then returns the itself */
            return *this;
        else{
            numberOfCourse = other.numberOfCourse;   /* equalizes sizes */
            numberOfStudent = other.numberOfStudent;   /* equalizes sizes */
            studentSize = other.studentSize;   /* equalizes capacities */
            courseSize = other.courseSize;   /* equalizes capacities */
            delete [] smsStudents;  /* deletes the older array */
            delete [] smsCourses;  /* deletes the older array */
            smsStudents = new Student*[studentSize];  /* creates new dynamic array */
            smsCourses = new Course*[courseSize];  /* creates new dynamic array */
            for(int i=0; i<studentSize; i++)
                smsStudents[i] = other.smsStudents[i];  /* and fills it with other object informations */
            for(int i=0; i<courseSize; i++)
                smsCourses[i] = other.smsCourses[i];  /* and fills it with other object informations */
            return *this;
        }
    }

    void SchoolManagementSystem::splitForStudent(string& line, string& studentName, string& studentID)
    {
        studentName.clear();  /* clears the string */
        studentID.clear();
        int count = 0;
        for(int i=0; i<line.size(); i++){
            if(line[i] == ' ')  /* counts the spaces */
                count++;
        }
        int i=0, k=0;
        while(i < count){
            if(line[k] == ' ')
                i++;
            studentName.push_back(line[k]);  /* until the last space pushes the all char to the studentName */
            k++;
        }
        studentName.pop_back();  /* for last space */
        i = 0;
        while(line[k] != '\0'){
            studentID.push_back(line[k]);  /* until the end of the line pushes the remain chars to the studentID */
            i++;
            k++;
        }
    }

    void SchoolManagementSystem::splitForCourse(string& line, string& courseCode, string& courseName)
    {
        courseCode.clear();  /* clears the string */
        courseName.clear();
        int k=0;
        while(line[k] != ' '){
            courseCode.push_back(line[k]);  /* until the first space pushes the all char to the courseCode */
            k++;
        }
        k++;
        while(line[k] != '\0'){
            courseName.push_back(line[k]);  /* until the end of the line pushes all chars to the courseName */
            k++;
        }
    }

    void SchoolManagementSystem::mainMenu()
    {
        int option;
        string studentName, studentID, courseName, courseCode, line;
        while(1){
            cout << "Main_menu\n0 exit\n1 student\n2 course\n3 list_all_students\n4 list_all_courses\n>> ";
            cin >> option;
            if(option == 0)   /* if the option = 0 finish writes the menu */
                break;
            else if(option == 1){  /* for student menu */
                while(1){
                    cout << "0 up\n1 add_student\n2 select_student\n>> ";
                    cin >> option;
                    if(option == 0)  /* if the option = 0 past the upper menu */
                        break;
                    else if(option == 1){  /* if the option = 1 takes the student informations */
                        cout << ">> ";
                        getchar();  /* for \n */
                        getline(cin, line);
                        splitForStudent(line, studentName, studentID);
                        addStudent(studentName, studentID);  /* adds the student */
                    }
                    else if(option == 2){  /* if the option = 2 takes the student informations */
                        int flag = 0, index;
                        cout << ">> ";
                        getchar();  /* for \n */
                        getline(cin, line);
                        splitForStudent(line, studentName, studentID);
                        for(int i=0; i<numberOfStudent; i++){  /* checks the informations are correct or not */
                            if((smsStudents[i]->getStudentName() == studentName) && (smsStudents[i]->getStudentID() == studentID)){
                                index = i;
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 1){  /* if they are correct then this block works */
                            while(1){
                                cout << "0 up\n1 delete_student\n3 add_selected_student_to_a_course\n4 drop_selected_student_from_a_course\n>> ";
                                cin >> option;
                                if(option == 0)  /* if the option = 0 past the upper menu */
                                    break;
                                else if(option == 1){  /* if the option = 1 deletes the student */
                                    for(int i=index; i<numberOfStudent-1; i++)
                                        smsStudents[i] = smsStudents[i+1];
                                    numberOfStudent--;  /* decreases the size */
                                    for(int i=0; i<numberOfCourse; i++)
                                        smsCourses[i]->deleteStudent(studentName, studentID);  /* deletes it from the courses it has been added to */
                                    break;
                                }
                                else if(option == 3){  /* if the option = 3 adds the student to a course */
                                    while(1){
                                        int flag, count = 1, size = 10;
                                        string* codes = new string[10];
                                        string* names = new string[10];
                                        cout << "0 up";
                                        for(int i=0; i<numberOfCourse; i++){
                                            flag = 0;
                                            for(int j=0; j<smsStudents[index]->getCoursesSize(); j++){
                                                if((smsCourses[i]->getCourseCode() == smsStudents[index]->courses[j]->getCourseCode()) 
                                                        && (smsCourses[i]->getCourseName() == smsStudents[index]->courses[j]->getCourseName())){
                                                    flag = 1;
                                                }
                                            }
                                            if(flag == 0){
                                                if(count-1 >= size){
                                                    string* temp1 = new string[size+10];    /* stores courses information with this arrays */
                                                    string* temp2 = new string[size+10];
                                                    for(int k=0; k<size; k++){
                                                        temp1[k] = codes[k];
                                                        temp2[k] = names[k];
                                                    }
                                                    size += 10;
                                                    delete [] codes;
                                                    delete [] names;
                                                    codes = temp1;
                                                    names = temp2;
                                                }
                                                codes[count-1] = smsCourses[i]->getCourseCode();
                                                names[count-1] = smsCourses[i]->getCourseName();
                                                /* prinst all courses except taken by before */
                                                cout << "\n" << count << " " << smsCourses[i]->getCourseCode() << " " << smsCourses[i]->getCourseName();
                                                count++;
                                            }
                                        }
                                        cout << "\n>> ";
                                        cin >> option;
                                        if(option == 0)    /* if the option = 0 past the upper menu */
                                            break;
                                        else if((option > 0) && (option <= count)){  /* if the option is correct interval then adds the selected course */
                                            smsStudents[index]->addCourse(codes[option-1], names[option-1]); /* adds the course */
                                            for(int i=0; i<numberOfCourse; i++){
                                                if((smsCourses[i]->getCourseCode() == codes[option-1]) && (smsCourses[i]->getCourseName() == names[option-1])){
                                                    smsCourses[i]->addStudent(studentName, studentID);  /* adds the student this course */
                                                    break;
                                                }
                                            }
                                            break;
                                        }       
                                    }
                                }
                                else if(option == 4){  /* if the option = 4 delete the student to course */
                                    while(1){
                                        int flag, count = 1, size = 10;
                                        string* codes = new string[10];
                                        string* names = new string[10];
                                        cout << "0 up";
                                        for(int i=0; i<numberOfCourse; i++){
                                            flag = 0;
                                            for(int j=0; j<smsStudents[index]->getCoursesSize(); j++){
                                                if((smsCourses[i]->getCourseCode() == smsStudents[index]->courses[j]->getCourseCode()) 
                                                        && (smsCourses[i]->getCourseName() == smsStudents[index]->courses[j]->getCourseName())){
                                                    flag = 1;
                                                }
                                            }
                                            if(flag == 1){
                                                if(count-1 >= size){
                                                    string* temp1 = new string[size+10]; /* stores courses information with this arrays */
                                                    string* temp2 = new string[size+10];
                                                    for(int k=0; k<size; k++){
                                                        temp1[k] = codes[k];
                                                        temp2[k] = names[k];
                                                    }
                                                    size += 10;
                                                    delete [] codes;
                                                    delete [] names;
                                                    codes = temp1;
                                                    names = temp2;
                                                }
                                                codes[count-1] = smsCourses[i]->getCourseCode();
                                                names[count-1] = smsCourses[i]->getCourseName();
                                                /* prinst all courses taken by before */
                                                cout << "\n" << count << " " << smsCourses[i]->getCourseCode() << " " << smsCourses[i]->getCourseName();
                                                count++;
                                            }
                                        }
                                        cout << "\n>> ";
                                        cin >> option;
                                        if(option == 0)  /* if the option = 0 past the upper menu */
                                            break;
                                        else if((option > 0) && (option <= count)){  /* if the option is correct interval then deletes the selected course */
                                            smsStudents[index]->deleteCourse(codes[option-1], names[option-1]);  /* deletes the selected course */
                                            for(int i=0; i<numberOfCourse; i++){
                                                if((smsCourses[i]->getCourseCode() == codes[option-1]) && (smsCourses[i]->getCourseName() == names[option-1])){
                                                    smsCourses[i]->deleteStudent(studentName, studentID);  /* deletes the student from this course */
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if(option == 2){  /* for course menu */
                while(1){
                    cout << "0 up\n1 add_course\n2 select_course\n>> ";
                    cin >> option;
                    if(option == 0)  /* if the option = 0 past the upper menu */
                        break;
                    else if(option == 1){  /* if the option = 1 adds the course */
                        cout << ">> ";
                        getchar();  /* for \n */
                        getline(cin, line);
                        splitForCourse(line, courseCode, courseName);
                        addCourse(courseCode, courseName);  /* adds the course */
                    }
                    else if(option == 2){  /* if the option = 2 takes the course informations */
                        int flag = 0, index;
                        cout << ">> ";
                        getchar();  /* for \n */
                        getline(cin, line);
                        splitForCourse(line, courseCode, courseName);
                        for(int i=0; i<numberOfCourse; i++){  /* checks the informatinos are correct or not */
                            if((smsCourses[i]->getCourseCode() == courseCode) && (smsCourses[i]->getCourseName() == courseName)){
                                index = i;  /* takes index */
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 1){
                            while(1){
                                cout << "0 up\n1 delete_course\n2 list_students_registered_to_the_selected_course\n>> ";
                                cin >> option;
                                if(option == 0)  /* if the option = 0 past the upper menu */
                                    break;
                                else if(option == 1){  /* if option = 1 deletes the course */
                                    for(int i=index; i<numberOfCourse-1; i++)
                                        smsCourses[i] = smsCourses[i+1];
                                    numberOfCourse--;  /* decreases the size */
                                    for(int i=0; i<numberOfStudent; i++)
                                        smsStudents[i]->deleteCourse(courseCode, courseName);  /* delete the course for students */
                                    break;
                                }
                                else if(option == 2){  /* if the option = 2 list the all students which takes the this course */
                                    for(int i=0; i<smsCourses[index]->getStudentsSize(); i++)
                                        cout << i+1  << " " << smsCourses[index]->students[i]->getStudentName() << " " << smsCourses[index]->students[i]->getStudentID() << "\n";
                                }
                            }
                        }
                    }
                }
            }
            else if(option == 3){  /* if the option = 3 list the all students */
                for(int i=0; i<numberOfStudent; i++)
                    cout << i+1 << " " << smsStudents[i]->getStudentName() << " " << smsStudents[i]->getStudentID() << "\n";                
            }
            else if(option == 4){  /* if the option = 4 list the all courses */
                for(int i=0; i<numberOfCourse; i++)
                    cout << i+1 << " " << smsCourses[i]->getCourseCode() << " " << smsCourses[i]->getCourseName() << "\n"; 
            }
        }
    }

    void SchoolManagementSystem::addStudent(string studentName, string studentID)
    {
        int flag = 0;
        for(int i=0; i<numberOfStudent; i++){  /* checks if the student has already been added */
            if((smsStudents[i]->getStudentName() == studentName) && (smsStudents[i]->getStudentID() == studentID)){
                flag = 1;
                break;
            }
        }
        if(flag == 0){  /* if it not then adds the student */
            Student* temp = new Student(studentName, studentID);  /* creates new object */
            if(numberOfStudent >= studentSize){  /* if the array is full then increase the capacity */
                Student** temparr = new Student*[studentSize + 10];  /* creates new dynamic array */
                for(int i=0; i<studentSize; i++)
                    temparr[i] = smsStudents[i];  /* copy all informations */
                studentSize += 10;  /* increase the capacity with 10 */
                delete [] smsStudents;  /* deletes older array */
                smsStudents = temparr;
            }
            smsStudents[numberOfStudent] = temp;  /* adds the new student */
            numberOfStudent++;  /* increase the size */
        }
    }

    void SchoolManagementSystem::addCourse(string courseCode, string courseName)
    {
        int flag = 0;
        for(int i=0; i<numberOfCourse; i++){ /* checks if the course has already been added */
            if((smsCourses[i]->getCourseCode() == courseCode) && (smsCourses[i]->getCourseName() == courseName)){
                flag = 1;
                break;
            }
        }
        if(flag == 0){  /* if it not then adds the course */
            Course* temp = new Course(courseName, courseCode);  /* creates new object */
            if(numberOfCourse >= courseSize){ /* if the array is full then increase the capacity */
                Course** temparr = new Course*[courseSize + 10];  /* creates new dynamic array */
                for(int i=0; i<courseSize; i++)
                    temparr[i] = smsCourses[i];  /* copy all informations */
                courseSize += 10;  /* increase the capacity with 10 */
                delete [] smsCourses;  /* deletes older array */
                smsCourses = temparr;
            }
            smsCourses[numberOfCourse] = temp; /* adds the new course */
            numberOfCourse++;  /* increase the size */
        }
    }
}