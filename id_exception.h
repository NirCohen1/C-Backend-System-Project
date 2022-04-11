#ifndef UNTITLED10_ID_EXCEPTION_H
#define UNTITLED10_ID_EXCEPTION_H

#include <exception>

class id_exception: public exception{
public:
	virtual const char* what()const throw () {
		return "id doesn't exists\n";
	}
};

#endif //UNTITLED10_ID_EXCEPTION_H
