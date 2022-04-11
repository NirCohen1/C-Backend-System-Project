#include "Room.h"
int Room::m_num=0;
class StandartRoom;

Room::Room(){
    m_is_split=false;
    m_has_father=false;
    m_father=nullptr;
    left=nullptr;
    right=nullptr;
	m_id=m_num;
    m_num++;
}

Room::Room(Room *father) {
    m_is_split=false;
    m_has_father=true;
    m_father=father;
    left=nullptr;
    right=nullptr;
    m_id=m_num;
    m_num++;
}

void Room::removeStudent(int id) {
    vector<Student*>::iterator it;
    for(it=m_students.begin(); it!=m_students.end(); it++){
    	if((*it)->getID()==id) {
            m_students.erase(it);
            return;
        }
    }
    throw id_exception();
}

void Room::addStudent(Student* const student) {
    vector<Student*>::iterator it;
	for(it=m_students.begin(); it!=m_students.end(); it++){
		if((*it)->getID()==student->getID()){
            throw id_exception();
            return;
		}
	}
    m_students.push_back(student);
}

void Room::splitRoomByNum(Room* room1, Room* room2) {
    this->left=room1;
    this->right=room2;
    right->m_father=this;
    left->m_father=this;
    m_is_split = true;
    int num = m_students.size()/2;
    int m_students_size = m_students.size();

    vector<Student*>::iterator it=m_students.begin(), it2;
    if(m_students_size==1){
    	room1->addStudent((*it));
        m_students.erase(it);
    	return;
    }
    if(m_students_size==0)
       	return;

    for (int i=0; i<num; i++){
        room1->addStudent((*it));
        m_students.erase(m_students.begin());
        it=m_students.begin();
    }

    for (int i=num ; i<m_students_size; i++){
        room2->addStudent((*it));
        m_students.erase(m_students.begin());
        it=m_students.begin();
    }

}

void Room::splitRoomByCharacter(Room* m_right, Room* m_left) {
    this->right=m_right;
    this->left=m_left;
    right->m_father=this;
    left->m_father=this;
    m_is_split = true;
    if(m_students.size()==1){
    	if ((*m_students.begin())->addStudent(right) || (*m_students.begin())->addStudent(left))
			m_students.erase(m_students.begin());
       	return;
    }
    if(m_students.size()==0)
        return;

    vector<Student*>::iterator it = m_students.begin();
    for(it = m_students.begin(); it!=m_students.end(); it++){
    	if ((*it)->addStudent(right))
    		m_students.erase(it--);
		else if((*it)->addStudent(left)==true)
			m_students.erase(it--);
    }

}


void Room::deleteRoom() {
	if (m_has_father) {
		if(this==m_father->left)
			m_father->left=nullptr;
		else if(this==m_father->right)
			m_father->right=nullptr;
		int num = m_students.size();
		for (int i=0; i<num ; i++) {
			m_father->addStudent(*m_students.begin());
			(*m_students.begin())->Cry();
			m_students.erase(m_students.begin());
		}
	}
	else {
		int num = m_students.size();
		for (int i=0; i<num ; i++) {
			(*m_students.begin())->Cry();
			m_students.erase(m_students.begin());
		}
	}
}

void Room::printRoom() const {
    cout << "room id:" << m_id << ", students:" << m_students.size() << endl;
}

int Room::find(int student_id) {
    vector<Student*>::iterator it=m_students.begin();
    for(it=m_students.begin(); it!=m_students.end(); it++){
    	if((*it)->getID()==student_id)
    		return this->m_id;
    }
    return -1;
}

bool Room::isSplited()const{
	return m_is_split;
}
int Room::getRoomId()const{
	return m_id;
}
Room* Room::getLeftRoom()const{
	if(m_is_split){
		if(left!=nullptr)
			return left;
		return nullptr;
	}
	return nullptr;
}
Room* Room::getRightRoom()const{
	if(m_is_split){
		if(right!=nullptr)
			return right;
		return nullptr;
	}
	return nullptr;
}
Room* Room::getFatherRoom()const{
	if(m_has_father){
		return m_father;
	}
	return nullptr;
}

vector<Student*> Room::getStudentsInRoom() const{
	return m_students;
}


Room::~Room(){
    m_students.clear();
}
