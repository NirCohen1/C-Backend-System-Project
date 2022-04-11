
#ifndef DILIGENTROOM_H_
#define DILIGENTROOM_H_
#include "Room.h"
class diligentRoom : public Room{
public:
    diligentRoom() {};
    diligentRoom(Room* room) : Room(room){};
    virtual bool addResponsibleStudent(Student* student);
    virtual bool addLazyStudent(Student* student);
    virtual bool addDiligentStudent(Student* student);
    ~diligentRoom() {};
};

#endif /* DILIGENTROOM_H_ */
