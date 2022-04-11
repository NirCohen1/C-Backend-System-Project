#ifndef UNTITLED10_DILIGENTSTUDENT_H
#define UNTITLED10_DILIGENTSTUDENT_H
#include "Student.h"

class DiligentStudent : public Student {
public:
    DiligentStudent(string firstname, string lastname, int id, int avg) : Student(firstname,lastname,id,avg) {};
    virtual void Cry()const;
    virtual void Working()const;
    virtual bool addStudent(Room* room);
    virtual void sentMessage(string mesaage, Room* room) ;
    ~DiligentStudent() {};
};


#endif //UNTITLED10_DILIGENTSTUDENT_H
