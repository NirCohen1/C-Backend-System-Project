#ifndef UNTITLED10_STANDARTROOM_H
#define UNTITLED10_STANDARTROOM_H

#include "Room.h"
class StandartRoom : public Room {
public:
    StandartRoom() ;// Room() {};
    StandartRoom(Room* room); // Room(room) {};
    virtual bool addResponsibleStudent(Student* student);
    virtual bool addLazyStudent(Student* student);
    virtual bool addDiligentStudent(Student* student);
    virtual int getRoomId()const {return m_id;};
    virtual bool isSplited()const {return m_is_split;}
    ~StandartRoom() {};
};


#endif //UNTITLED10_STANDARTROOM_H
