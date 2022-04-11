#ifndef ROOM_H_
#define ROOM_H_
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "id_exception.h"
#include <map>
#include <vector>
class Student;

class Room {
protected:
	static int m_num;
	int m_id;
	bool m_is_split;
	bool m_has_father;
	Room* m_father;
    Room* right;
    Room* left;
	vector<Student*> m_students;
public:
	Room();
	Room(Room* father);
	virtual void addStudent(Student* const student);
    virtual bool addResponsibleStudent(Student* student)=0;
    virtual bool addLazyStudent(Student* student)=0;
    virtual bool addDiligentStudent(Student* student)=0;
    virtual void removeStudent(int id);
    virtual void splitRoomByNum(Room* right, Room* left);
    virtual int find(int student_id);
    virtual bool isSplited()const;
    virtual int getRoomId()const;
    virtual Room* getLeftRoom()const;
    virtual Room* getRightRoom()const;
    virtual Room* getFatherRoom()const;
    virtual vector<Student*> getStudentsInRoom() const;
    virtual void splitRoomByCharacter(Room* right, Room* left);
    virtual void deleteRoom();
    virtual void printRoom()const;
	virtual ~Room();
};

#endif /* ROOM_H_ */
