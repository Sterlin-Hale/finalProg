//***********************************************************
//Name: Sterlin Hale
//Assignment: Final
//Purpose: read data from file into object. sort multiple ways and display
//Notes: main.cpp and main.h were supplied by instructor
//***********************************************************

#ifndef CODING07_PERSON_H
#define CODING07_PERSON_H

#include <string>
#include <iostream>
#include <algorithm>

class Person{

public:

    /*
     * Constructors
     */

    Person(std::string, std::string, int, int, std::string);

    /*
     * Deconstructors
     */

    ~Person();

    /*
     * Getters
     */

    int getid();
    int getAge();
    std::string getfName();
    std::string getlName();
    std::string getFavoriteFood();

    /*
     * Setters
     */

    void setid(int);
    void setAge(int);
    void setfName(std::string);
    void setlName(std::string);
    void setFavoriteFood(std::string);

private:
    int id, age;
    std::string fName, lName, favoriteFood;

};

#endif //CODING07_PERSON_H
