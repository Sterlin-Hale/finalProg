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
#include <fstream>

#include "person.h"

class People {

public:

    /*
     * Constructors
     */

    People(std::string);

    /*
     * Deconstructors
     */

    ~People();

    /*
     * Getters
     */

    void displayPeople(int);

    /*
     * Setters
     */

    void clear();

private:

    int numPeople, numLines, id, age;
    std::string line, lName, fName, idNumber, ageValue, favFood, error;
    Person **persons, **temp;

    enum selector {
        NONE, ID, AGE
    };

    int lineCount(std::string);

    void swap(Person **, Person **);

    void bubbleSortArray(Person **, int);

    void duplicator();
};

#endif //CODING07_PEOPLE_H
