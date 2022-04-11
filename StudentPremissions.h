#ifndef UNTITLED10_STUDENTPREMISSIONS_H
#define UNTITLED10_STUDENTPREMISSIONS_H

#include <exception>

class student_permission : public exception {
public:
	virtual const char* what()const throw () {
		return "this student don't have permission\n";
	}
};

#endif //UNTITLED10_STUDENTPREMISSIONS_H
