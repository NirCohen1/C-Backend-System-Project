#include "DiligentStudent.h"

void DiligentStudent::Working() const {
    cout << m_firstName << " " << m_lastName << " is working\n";
}
void DiligentStudent::Cry() const {

}

bool DiligentStudent::addStudent(Room* room){
    return room->addDiligentStudent(this);
}

void DiligentStudent::sentMessage(string mesaage, Room *room) {
    throw student_permission();
}
