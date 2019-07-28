//***********************************************************
//Name: Sterlin Hale
//Assignment: Final
//Purpose: read data from file into object. sort multiple ways and display
//Notes: main.cpp and main.h were supplied by instructor
//***********************************************************

#include "person.h"

/*
 * Constructors
*/

Person::Person(std::string firstWord ,std::string secWord, int idNumber, int years, std::string foodItem){

    setid(idNumber);
    setAge(years);
    setfName(firstWord);
    setlName(secWord);
    setFavoriteFood(foodItem);
}

/*
* Deconstructors
*/

Person::~Person(){

}

/*
* Getters
*/

int Person::getid(){
    return id;
}

int Person::getAge(){
    return age;
}

std::string Person::getfName(){
    return fName;
}

std::string Person::getlName(){
    return lName;
}

std::string Person::getFavoriteFood(){
    return favoriteFood;
}

/*
* Setters
*/

void Person::setAge(int years){
    if (years < 1 || years > 100){
        age = 0;
    } else {
        age = years;
    }
}

void Person::setfName(std::string firstWord){
    fName = firstWord;
}

void Person::setlName(std::string secWord){
    lName = secWord;
}

void Person::setFavoriteFood(std::string foodItem){
    if (foodItem == ""){
        favoriteFood = "Texas BBQ";
    } else {
        favoriteFood = foodItem;
    }
}

void Person::setid(int idNumber){
    id = idNumber;
}


