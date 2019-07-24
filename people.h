//***********************************************************
//Name: Sterlin Hale
//Assignment: 07
//Purpose:Object Oriented Programming: Create a "person" object that will then be used to create a "People" object which contains an array of pointers to "Person" object.
//Notes: main.cpp and main.h were supplied by instructor
//***********************************************************

#ifndef CODING07_PEOPLE_H
#define CODING07_PEOPLE_H

#include <iostream>
#include <string>

#include "person.h"

class People{

public:

    /*
     * Constructors
     */

    People(std::string*, int*, std::string*, const int);

    /*
     * Deconstructors
     */

    ~People();

    /*
     * Getters
     */

    void displayPeople();

    /*
     * Setters
     */

    void clear();

private:

    int numPeople;
    Person **persons;

};

#endif //CODING07_PEOPLE_H
