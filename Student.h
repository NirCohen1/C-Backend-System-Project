
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include "Room.h"
#include "StudentPremissions.h"
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
class Room;

class Student {
protected:
	int m_id;
	float m_avarage;
	string m_firstName;
	string m_lastName;
	vector<string>* m_messages;
public:
	Student(string firstname, string lastname, int id, int avg);
    virtual bool addStudent(Room* room)=0;
    virtual void sentMessage(string mesaage, Room* room)=0;
	virtual void printStudent(int room_id)const;
	virtual void Cry()const=0;
    virtual void Working()const=0;
    virtual void getMessage(string message);
    virtual string getFullName()const {return m_firstName + " " + m_lastName;}
    virtual void printMessages()const;
    virtual int getID()const { return m_id;};
    virtual ~Student();
};

#endif /* STUDENT_H_ */
