#include "LazyStudent.h"

void LazyStudent::Cry() const {
    cout << m_firstName << " " << m_lastName << " is crying\n";
}
void LazyStudent::Working() const {
}

bool LazyStudent::addStudent(Room* room){
    return room->addLazyStudent(this);
}

void LazyStudent::sentMessage(string mesaage, Room *room) {
	throw student_permission();
}
