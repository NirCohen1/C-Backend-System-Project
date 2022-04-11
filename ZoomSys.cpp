#include "ZoomSys.h"
#include <sstream>

int num=0;

ZoomSys::ZoomSys(string path) {
    m_rooms =  new map<int,Room*>;
    m_students = new map<int,Student*>;
	//read from file
    ifstream f(path);
    string line="", first_name="", last_name="", input="";
    int id,avg,counter=0;
    char character;
    Student* student;

    if (f.is_open()) {
        while (getline(f, line)) {
            //insert to map
            istringstream iss(line);
            while (getline(iss,input,'\t')){
                switch (counter) {
                    case 0:
                        first_name=input;
                        break;
                    case 1:
                        last_name=input;
                        break;
                    case 2:
                        id = stoi(input);
                        break;
                    case 3:
                        avg = stoi(input);
                        break;
                    case 4:
                        character= input[0];
                        break;
                }

                counter++;
            }
			if (character=='W')
				student = new DiligentStudent(first_name,last_name,id,avg);
			if (character=='L')
				student = new LazyStudent(first_name,last_name,id,avg);
			if (character=='R')
				student = new ResponsibleStudent(first_name, last_name, id, avg);
			if (student != nullptr){
				m_students->insert({num, student});
				vec_student.push_back(student);
				num++;
			}
			student = nullptr;
			counter=0;
        }
    }
    f.close();
}

void ZoomSys::addStudenthelp(){
	string first_name="", last_name="";
	int id,avg;
	char character;
	printf("--Create Student---\n");
	printf("First Name:\n");
	cin >> first_name;
	printf("Last Name:\n");
	cin >> last_name;
	printf("ID:\n");
	cin >> id;

	map<int,Student*>::iterator it;
	int n = findNum(id);
	it = m_students->find(n);

	printf("avg:\n");
	cin >> avg;

	printf("Worker(W) or Lazy(L) or Responsible(R) Student?\n");
	cin >> character;
	if (character!='W' && character!='L' && character!='R')
		throw invalidDetails();
	if (avg>100 || avg<0)
		throw invalidDetails();
	if (it != m_students->end())
		throw invalidDetails();


	Student* student= nullptr;
	if (character=='W')
		student = new DiligentStudent(first_name,last_name,id,avg);
	if (character=='L')
		student = new LazyStudent(first_name,last_name,id,avg);
	if (character=='R')
		student = new ResponsibleStudent(first_name, last_name, id, avg);
	if (student != nullptr){
		m_students->insert({num, student});
		vec_student.push_back(student);
		num++;
	}
}

void ZoomSys::addStudent() {
	try{
		addStudenthelp();
	}
	catch (exception& e) {
		cout<<e.what();
		return;
	}
}

void ZoomSys::removeStudenthelp() {
	int id,student_room=-1;
	cout << "---Remove Student---\n";
	cout << "Enter the id:\n";
	cin >> id;
	int n = findNum(id);
	map<int,Student*>::iterator it = m_students->find(n);
	map<int,Room*>::iterator it_room;
	if(it!=m_students->end()) {
		for (it_room = m_rooms->begin(); it_room != m_rooms->end(); it_room++) {
			student_room = it_room->second->find(it->second->getID());
			if(student_room != -1)
				break;
		}
		if (student_room==-1)
			m_students->erase(n);
		else{
			it_room->second->removeStudent(id);
			m_students->erase(n);
			return;
		}
	}
	else {
		throw id_exception();
	}
}

void ZoomSys::removeStudent() {
	try{
		removeStudenthelp();
	}
	catch (exception& e) {
		cout<<e.what();
		return;
	}
}

void ZoomSys::assignStudenthelp() {
	int student_id, room_id, id=-1;
	cout << "---Assign Student---\n";
	cout << "Enter student id:\n";
	cin >> student_id;
	cout << "Enter room id:\n";
	cin >> room_id;
	int n = findNum(student_id);
	map<int,Student*>::iterator it = m_students->find(n);
	if(it==m_students->end())
		throw id_exception();
	map<int,Room*>::iterator it_room = m_rooms->find(room_id);
	if(it_room==m_rooms->end() && room_id!=-1)
		throw id_exception();

	if(room_id==-1){
        map<int,Room*>::iterator find_student;
        for (find_student=m_rooms->begin(); find_student!=m_rooms->end(); ++find_student) {
            id = find_student->second->find(student_id);
            if (id != -1) {
                find_student->second->removeStudent(student_id);
                break;
            }
        }
        return;
	}

	//check if student already in another room
	map<int,Room*>::iterator find_student;
    for (find_student=m_rooms->begin(); find_student!=m_rooms->end(); ++find_student) {
        id = find_student->second->find(student_id);
		if (id != -1) {
		    find_student->second->removeStudent(student_id);
			break;
		}
	}
	it_room->second->addStudent(it->second);
}

void ZoomSys::assignStudent() {
	try{
		assignStudenthelp();
	}
	catch (exception& e) {
		cout<<e.what();
	}
}

void ZoomSys::addRoom() {
    Room* room;
    room = new StandartRoom();
    m_rooms->insert({room->getRoomId(), room});
    vec_room.push_back(room);
    printf("New room created\n");
}

void ZoomSys::splitRoomhelp() {
	int id,num_split;
	cout << "--Split Room---\n" ;
	cout << "Room id:\n";
	cin >> id;
	map<int,Room*>::iterator it_room = m_rooms->find(id);
	if (it_room==m_rooms->end())
		throw id_exception();
	if (it_room->second->isSplited())
		throw split_before();
	cout << "1.Character split\n";
	cout << "2.Size split\n";
	cin >> num_split;
	if (num_split!=1 && num_split!=2)
		throw invalidDetails();
	if (num_split==1){
		diligentRoom* DiligentRoom;
		LazyRoom* lazyRoom;
		DiligentRoom = new diligentRoom(it_room->second);
		lazyRoom = new LazyRoom(it_room->second);
		m_rooms->insert({DiligentRoom->getRoomId(), DiligentRoom});
		m_rooms->insert({lazyRoom->getRoomId(),lazyRoom});
		vec_room.push_back(DiligentRoom);
		vec_room.push_back(lazyRoom);

		it_room->second->splitRoomByCharacter(m_rooms->find(lazyRoom->getRoomId())->second,m_rooms->find(DiligentRoom->getRoomId())->second);
	}
	else {
		Room* room1;
		Room* room2;
		room1 = new StandartRoom(it_room->second);
		room2 = new StandartRoom(it_room->second);
		m_rooms->insert({room1->getRoomId(),room1});
		m_rooms->insert({room2->getRoomId(),room2});
		vec_room.push_back(room1);
		vec_room.push_back(room2);

		it_room->second->splitRoomByNum(m_rooms->find(room1->getRoomId())->second , m_rooms->find(room2->getRoomId())->second);
	}
}

void ZoomSys::splitRoom() {
	try{
		splitRoomhelp();
	}
	catch(exception& e){
		cout<<e.what();
		return;
	}
}

void ZoomSys::removeRoomhelp(){
    int id;
    cout << "--Remove Room---\n" ;
    cout << "Enter room id:\n";
    cin >> id;

    map<int,Room*>::iterator it_room = m_rooms->find(id);
    if (it_room==m_rooms->end())
    	throw id_exception();

    Room* room_to_remove;
    Room* father;
    room_to_remove=it_room->second;

    while(room_to_remove->getLeftRoom()!= nullptr || room_to_remove->getRightRoom()!= nullptr || room_to_remove->getRoomId()!=id){
    	if(room_to_remove->getLeftRoom() != nullptr){
    		room_to_remove = room_to_remove->getLeftRoom();
    		continue;
    	}
    	if(room_to_remove->getRightRoom() != nullptr){
    		room_to_remove = room_to_remove->getRightRoom();
    		continue;
    	}
    	father=room_to_remove->getFatherRoom();
    	m_rooms->erase(room_to_remove->getRoomId());
    	room_to_remove->deleteRoom();
    	room_to_remove=father;
    }
    int delete_id = it_room->second->getRoomId();
    it_room->second->deleteRoom();
    m_rooms->erase(delete_id);
}

void ZoomSys::removeRoom() {
	try{
		removeRoomhelp();
	}
	catch (exception& e) {
		cout<<e.what();
	}
}

void ZoomSys::workhelp(){
	int room_id;
	cout << "Enter the room you want to work:\n";
	cin >> room_id;
	map<int,Room*>::iterator it = m_rooms->find(room_id);
	if(it == m_rooms->end())
		throw id_exception();

	map<int,Student*>::iterator student_it;
	for (student_it=m_students->begin(); student_it!=m_students->end() ; ++student_it) {
		if (it->second->find((student_it)->second->getID())==-1)
			continue;
		else{
			student_it->second->Working();
		}
	}
}

void ZoomSys::work() {
	try{
		workhelp();
	}
	catch (exception& e) {
		cout<<e.what();
	}
}

void ZoomSys::sendMessagehelp(){
	int student_id,room_id=-1;
	string message="";
	cout << "Enter the id:\n";
	cin >> student_id;
	int n = findNum(student_id);
	map<int,Student*>::iterator it = m_students->find(n);
	if(it != m_students->end()) {
		cout << "Enter the message:\n";
		cin >> message;
		map<int,Room*>::iterator it_room;
		for (it_room=m_rooms->begin(); it_room!=m_rooms->end(); ++it_room) {
			room_id = it_room->second->find(student_id);
			if (room_id != -1) {
				message = it->second->getFullName() + ":" + message;
				it->second->sentMessage(message, it_room->second);
				return;
			}
		}
	}
	else
		throw id_exception();
}

void ZoomSys::sendMessage() {
    try{
    	sendMessagehelp();
    }
    catch (exception& e) {
		cout<<e.what();
	}
}

void ZoomSys::printRooms() {
    map<int,Room*>::iterator it;
    for (it=m_rooms->begin(); it!=m_rooms->end() ; it++) {
        it->second->printRoom();
    }
}

void ZoomSys::printStudents() {
    cout<< "First name, Last Name, ID, Avg, Room ID\n";
    map<int,Student*>::iterator it=m_students->begin();
    map<int,Room*>::iterator it_room;
    int student_room=-1;

    while( it!=m_students->end()) {
        for (it_room=m_rooms->begin(); it_room!=m_rooms->end() ; it_room++) {
            student_room = it_room->second->find(it->second->getID());
            if(student_room!=-1)
            	break;
        }
        it->second->printStudent(student_room);
        it++;
    }
}

void ZoomSys::printStudentDetailshelp(){
	int id;
	int student_room=-1;
	cout << "Enter student id:\n";
	cin >> id;
	map<int,Student*>::iterator it=m_students->begin();
	map<int,Room*>::iterator it_room;
	int n = findNum(id);
	it = m_students->find(n);
	if(it==m_students->end())
		throw id_exception();

	for (it_room=m_rooms->begin(); it_room!=m_rooms->end() ; it_room++) {
		student_room = it_room->second->find(it->second->getID());
		if(student_room!=-1)
			break;
	}
	it->second->printStudent(student_room);
	it->second->printMessages();
}

void ZoomSys::printStudentDetails() {
	try{
		printStudentDetailshelp();
	}
	catch (exception& e) {
		cout<<e.what();
	}
}

int ZoomSys::findNum(int id){
	map<int,Student*>::iterator it;
	for (it=m_students->begin();it!=m_students->end(); it++) {
		if(it->second->getID()==id)
			return it->first;
	}
	return -1;
}

ZoomSys::~ZoomSys() {
    m_students->clear();
    delete m_students;

    m_rooms->clear();
    delete m_rooms;

    for(int i=0 ; i<(int)vec_room.size(); i++){
    	delete vec_room[i];
    }
    for(int i=0 ; i<(int)vec_student.size(); i++){
    	delete vec_student[i];
    }
}
