
#ifndef LAZYROOM_H_
#define LAZYROOM_H_
#include "Room.h"

class LazyRoom : public Room {
public:
    LazyRoom(Room* room) : Room(room){};
	LazyRoom() {};
    virtual bool addResponsibleStudent(Student* student);
    virtual bool addLazyStudent(Student* student);
    virtual bool addDiligentStudent(Student* student);
	~LazyRoom() {};
};

#endif /* LAZYROOM_H_ */
