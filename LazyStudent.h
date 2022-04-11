#ifndef UNTITLED10_LAZYSTUDENT_H
#define UNTITLED10_LAZYSTUDENT_H
#include "Student.h"

class LazyStudent : public Student {
public:
    LazyStudent(string firstname, string lastname, int id, int avg) : Student(firstname,lastname,id,avg) {};
    virtual void Cry()const;
    virtual void Working()const;
    virtual bool addStudent(Room* room);
    virtual void sentMessage(string mesaage, Room* room) ;
    ~LazyStudent() {};
};


#endif //UNTITLED10_LAZYSTUDENT_H
