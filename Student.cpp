#include "Student.h"

Student::Student(string firstname, string lastname, int id, int avg) {
	this->m_firstName=firstname;
	this->m_lastName=lastname;
	this->m_id=id;
	this->m_avarage=avg;
    this->m_messages = new vector<string>;
}

void Student::printStudent(int room_id) const {
    cout<< m_firstName << " " << m_lastName << " " << m_id << " " << m_avarage << " " << room_id << endl;
}

void Student::printMessages() const {
	cout << "---Messages---\n";
    vector<string>::iterator it = m_messages->begin();
    for (it=m_messages->begin(); it !=m_messages->end(); ++it) {
        cout << *it << endl;
    }
}

void Student::getMessage(string message) {
    m_messages->push_back(message);
}

Student::~Student() {
    m_messages->clear();
    delete m_messages;
}


