:- style_check(-singleton).
:- dynamic(room/3).
:- dynamic(course/6).
:- dynamic(instructor/3).
:- dynamic(student/3).

% room(RoomID,Capacity,Needs)
room(z06,27,[smart_board,no]).
room(z10,20,[computer,handicapped,no]).
room(z11,15,[smart_board,handicapped,no]).
room(z16,21,[projector,computer,no]).
room(z23,19,[smart_board,projector,computer,handicapped,no]).
room(z30,25,[projector,no]).

% room_occupancy(CourseID,roomID,startHour)
room_occupancy(cse101,z06,10).
room_occupancy(cse101,z06,11).
room_occupancy(cse102,z23,10).
room_occupancy(cse102,z23,11).
room_occupancy(cse102,z23,12).
room_occupancy(cse107,z11,12).
room_occupancy(cse107,z11,13).
room_occupancy(cse107,z11,14).
room_occupancy(cse108,z06,11).
room_occupancy(cse108,z06,12).
room_occupancy(cse108,z06,13).
room_occupancy(cse232,z16,14).
room_occupancy(cse232,z16,15).
room_occupancy(cse341,z23,12).
room_occupancy(cse341,z23,13).
room_occupancy(cse341,z23,14).
room_occupancy(cse331,z30,11).
room_occupancy(cse331,z30,12).

% course(CourseID,Capacity,InstructorID,Hours,RoomID,Needs)
course(cse101,20,mehmet_gokturk,2,z06,[no]).
course(cse102,14,yakup_genc,3,z23,[computer,projector,handicapped,no]).
course(cse107,21,mehmet_gokturk,3,z11,[smart_board,handicapped,no]).
course(cse108,12,yakup_genc,3,z06,[computer,smart_board,no]).
course(cse232,20,habil_kalkan,2,z16,[projector,handicapped,no]).
course(cse331,22,alp_arslan,2,z30,[smart_board,projector,no]).
course(cse341,18,ysa,3,z23,[smart_board,computer,handicapped,no]).

% instructor(InstructorID,Courses,Needs)
instructor(mehmet_gokturk,[cse101,cse107],[computer]).
instructor(yakup_genc,[cse102,cse108],[smart_board,projector]).
instructor(habil_kalkan,[cse232],[projector]).
instructor(alp_arslan,[cse331],[smart_board]).
instructor(ysa,[cse341],[projector,computer]).

% student(StudentID,Course,HandicappedOrNot)
student(s_id1,[cse101],handicapped).
student(s_id2,[cse102],handicapped).
student(s_id3,[cse107],no).
student(s_id4,[cse101,cse102],no).
student(s_id5,[cse107,cse102],handicapped).
student(s_id6,[cse102,cse232],handicapped).
student(s_id7,[cse107,cse232],no).
student(s_id8,[cse107,cse341],no).
student(s_id9,[cse108,cse341],handicapped).

% This function adds new student
addStudent(StudentID,Courses,Equipments):-
    \+student(StudentID,_,_),
    assertz(student(StudentID,Courses,Equipments)).

% This function adds new course
addCourse(CourseID,Capacity,InstructorID,Hours,RoomID,Equipments):-
    \+course(CourseID,_,_,_,_,_),
    assertz(course(CourseID,Capacity,InstructorID,Hours,RoomID,Equipments)).

% This function adds new room
addRoom(RoomID,Capacity,Equipments):-
    \+room(RoomID,_,_),
    assertz(room(RoomID,Capacity,Equipments)).

% This function checks conflict
conflictCheck(Crs1,Crs2):-
    room_occupancy(Crs1,Cap1,Hrs1),
    room_occupancy(Crs2,Cap2,Hrs2),
    not(Crs1=Crs2),
    Cap1=Cap2,(Hrs1=Hrs2).  

% This function checks the element is inside the list or not
checkElementInList(Head, [Head|Remain]).
checkElementInList(Head, [Element|Remain]):-
	checkElementInList(Head, Remain).

subset([], Sub).
subset([Head|Remain], Sub):-		
	element(Head, Sub),
	subset(Remain, Sub).

element(Head, A):-
	checkElementInList(Head, A).

% This function checks which room assign the given course
assignCourseRoom(Course,Room):-
    course(Course,Cap1,_,_,_,Equipments),
    room(Room,Cap2,Needs),
    Cap1 =< Cap2,    
    subset(Equipments,Needs).

% This function checks which student can enroll given course
enrollStudentCourse(Student,Course):-    
    student(Student,_,Equipments),
    course(Course,_,_,_,_,Needs),
    checkElementInList(Equipments,Needs).  
