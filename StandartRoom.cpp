#include "StandartRoom.h"


StandartRoom::StandartRoom() : Room(){

}

StandartRoom::StandartRoom(Room *father):Room(father) {

}

bool StandartRoom::addResponsibleStudent(Student* student) {
	m_students.push_back(student);
	return true;
}

bool StandartRoom::addLazyStudent(Student* student) {
	return false;
}

bool StandartRoom::addDiligentStudent(Student* student) {
	return false;
}


