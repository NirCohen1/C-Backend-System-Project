#include "LazyRoom.h"


bool LazyRoom::addResponsibleStudent(Student* student) {
	return false;
}

bool LazyRoom::addLazyStudent(Student* student) {
	m_students.push_back(student);
	return true;
}

bool LazyRoom::addDiligentStudent(Student* student) {
	return false;
}
