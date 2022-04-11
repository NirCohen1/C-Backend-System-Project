#ifndef ZOOMSYS_H_
#define ZOOMSYS_H_

#include "Student.h"
#include "DiligentStudent.h"
#include "LazyStudent.h"
#include "ResponsibleStudent.h"
#include "Room.h"
#include "LazyRoom.h"
#include "StandartRoom.h"
#include "diligentRoom.h"
#include "id_exception.h"
#include "StudentPremissions.h"
#include "InvalidDetails.h"
#include "SplitBefore.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <map>
#include <vector>


class ZoomSys{
	vector<Room*> vec_room;
	vector<Student*> vec_student;
    map<int,Student*>* m_students;
    map<int,Room*>* m_rooms;

    void addStudenthelp();
    void removeStudenthelp();
    void assignStudenthelp();
    void addRoomthelp();
    void splitRoomhelp();
    void removeRoomhelp();
    void workhelp();
    int findNum(int id);
    void sendMessagehelp();
    void printStudentDetailshelp();

public:
	ZoomSys(string path);
	virtual void addStudent();
	virtual void removeStudent();
	virtual void assignStudent();
	virtual void addRoom();
	virtual void splitRoom();
	virtual void removeRoom();
	virtual void work();
	virtual void sendMessage();
	virtual void printRooms();
	virtual void printStudents();
	virtual void printStudentDetails();
    virtual ~ZoomSys();
};

#endif /* ZOOMSYS_H_ */
