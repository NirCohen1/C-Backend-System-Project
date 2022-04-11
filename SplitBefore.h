#ifndef UNTITLED10_SPLITBEFORE_H
#define UNTITLED10_SPLITBEFORE_H

#include <exception>

class split_before : public exception {
public:
    virtual const char* what()const throw () {
    	return "This room was split before\n";
   }
};
#endif //UNTITLED10_SPLITBEFORE_H
