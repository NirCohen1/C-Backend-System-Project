
#include "diligentRoom.h"

bool diligentRoom::addResponsibleStudent(Student* student) {
	return false;
}

bool diligentRoom::addLazyStudent(Student* student) {
	return false;
}

bool diligentRoom::addDiligentStudent(Student* student) {
	m_students.push_back(student);
	return true;
}
