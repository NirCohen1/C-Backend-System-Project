#ifndef UNTITLED10_INVALIDDETAILS_H
#define UNTITLED10_INVALIDDETAILS_H

#include <exception>

class invalidDetails : public exception {
public:
    virtual const char* what()const throw () {
        return "Please enter valid details\n";
    }
};
#endif //UNTITLED10_INVALIDDETAILS_H
