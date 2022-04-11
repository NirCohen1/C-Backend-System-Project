prog: main.o Room.o StandartRoom.o diligentRoom.o LazyRoom.o LazyStudent.o ResponsibleStudent.o DiligentStudent.o Student.o ZoomSys.o
	g++ -o prog main.o Room.o StandartRoom.o diligentRoom.o LazyRoom.o LazyStudent.o ResponsibleStudent.o DiligentStudent.o Student.o ZoomSys.o
main.o: main.cpp
	g++ -c main.cpp
	
Room.o: Room.cpp Room.h 
	g++ -c Room.cpp
	
StandartRoom.o: StandartRoom.cpp StandartRoom.h
	g++ -c StandartRoom.cpp	
	
dilgentRoom.o: diligentRoom.cpp diligentRoom.h 
	g++ -c diligentRoom.cpp
	
LazyRoom.o: LazyRoom.cpp LazyRoom.h 
	g++ -c LazyRoom.cpp
	
LazyStudent.o: LazyStudent.cpp LazyStudent.h 
	g++ -c LazyStudent.cpp
	
ResponsibleStudent.o: ResponsibleStudent.cpp ResponsibleStudent.h 
	g++ -c ResponsibleStudent.cpp
	
DiligentStudent.o: DiligentStudent.cpp DiligentStudent.h 
	g++ -c DiligentStudent.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp
	
ZoomSys.o: ZoomSys.cpp ZoomSys.h
	g++ -c ZoomSys.cpp
clean:
	rm -f *.o prog
