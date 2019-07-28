//***********************************************************
//Name: Sterlin Hale
//Assignment: Final
//Purpose: read data from file into object. sort multiple ways and display
//Notes: main.cpp and main.h were supplied by instructor
//***********************************************************


#ifndef CODING07_PEOPLE_H
#define CODING07_PEOPLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "person.h"

enum Sel {
    NONE, ID, AGE
};


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

    void displayPeople(Sel = NONE);

    /*
     * Setters
     */

    void clear();

private:

    int numPeople, numLines, id, age;
    std::string line, lName, fName, idNumber, ageValue, favFood, error;
    Person **persons, **temp;


    Sel x;

    int lineCount(std::string);
    void swap(Person **, Person **);
    void bubbleSortArray(Person **, int);
    void duplicator(Person **);
};

#endif //CODING07_PEOPLE_H
