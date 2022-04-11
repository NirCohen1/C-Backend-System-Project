#include "ResponsibleStudent.h"

void ResponsibleStudent::Working() const {

}
void ResponsibleStudent::Cry() const {

}

bool ResponsibleStudent::addStudent(Room* room){
    return room->addResponsibleStudent(this);
}

void ResponsibleStudent::sentMessage(string mesaage, Room* room) {
    vector<Student*> m = room->getStudentsInRoom();
    vector<Student*>::iterator it;
    for (it=m.begin(); it!=m.end() ; ++it) {
        (*it)->getMessage(mesaage);
    }
}
