//***********************************************************
//Name: Sterlin Hale
//Assignment: 07
//Purpose:Object Oriented Programming: Create a "person" object that will then be used to create a "People" object which contains an array of pointers to "Person" object.
//Notes: main.cpp and main.h were supplied by instructor
//***********************************************************

#include "people.h"

/*
 * Constructors
 */

People::People(std::string *ns, int *years, std::string *fs, const int DATASIZE){
    numPeople = DATASIZE;
    persons = new Person*[numPeople];
    for( int i = 0; i < numPeople; i++){
        persons[i] = new Person(ns[i], years[i], fs[i]);
    }
}

/*
 * Deconstructors
 */

People::~People(){
    clear();
}

/*
 * Getters
 */

void People::displayPeople(){

    if (numPeople > 0) {
        for (int i = 0; i < numPeople; i++) {
            std::cout << persons[i]->getid() << ": " << persons[i]->getName() << " is " << persons[i]->getAge()
                      << " years old and likes " << persons[i]->getFavoriteFood() << "." << std::endl;
        }
    }else {
        std::cout << "\tThere are no people to display." << std::endl;
    }
}

/*
 * Setters
 */

void People::clear(){
    for (int i = 0; i < numPeople; i++) {
        delete persons[i];
    }
    persons = NULL;
    delete persons;
    numPeople = 0;
}
