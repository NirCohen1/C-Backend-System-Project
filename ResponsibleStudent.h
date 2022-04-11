#ifndef UNTITLED10_RESPONSIBLESTUDENT_H
#define UNTITLED10_RESPONSIBLESTUDENT_H

#include "Student.h"

class ResponsibleStudent : public Student {
public:
    ResponsibleStudent(string firstname, string lastname, int id, int avg) : Student(firstname, lastname, id, avg) {};
    virtual void Cry()const;
    virtual void Working()const;
    virtual bool addStudent(Room* room);
    virtual void sentMessage(string mesaage, Room* room);
    ~ResponsibleStudent() {};
};


#endif //UNTITLED10_RESPONSIBLESTUDENT_H
