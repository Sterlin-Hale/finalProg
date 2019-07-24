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

People::People(std::string fileName){

    numPeople = lineCount(fileName);

    persons = new Person*[numPeople];

    std::ifstream infile(fileName);

    if (numPeople > 0) {
        for (int i = 0; i < numPeople; i++) {
            getline(infile, fName, ' ');
            getline(infile, lName, ',');
            getline(infile, idNumber, ',');
            id = stoi(idNumber);
            getline(infile, ageValue, ',');
            age = stoi(ageValue);
            getline(infile, favFood, '\n');
            persons[i] = new Person(fName, lName, id, age, favFood);
        }

        infile.close();
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

void People::displayPeople(int x) {

    if (numPeople > 0) {
        bubbleSortArray(persons, x);
        for (int i = 0; i < numPeople; i++) {
            std::cout << persons[i]->getid() << ": " << persons[i]->getlName() << ", " << persons[i]->getfName()
                      << " is " << persons[i]->getAge()
                      << " years old and likes " << persons[i]->getFavoriteFood() << "." << std::endl;
        }
    }else{
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

/*
 * other methods
 */

int People::lineCount (std::string fileName){

    std::ifstream infile(fileName);

    numLines = 0;
    while (getline(infile, line)) {
        numLines++;
    }

    infile.close();

    return numLines;
}

void People::swap(Person **array1, Person **array2) {

    Person *holder;

    holder = *array2;
    *array2 = *array1;
    *array1 = holder;

    return;
}

void People::bubbleSortArray(Person **array, int x) {

    int i, j;
    if ( x == 1){
        for ( i = 0; i < numPeople - 1; i++){
            for ( j = 0; j < numPeople - i - 1; j++){
                if (array[j]->getid() > array[j + 1]->getid()){
                    swap(&array[j], &array[j+1]);
                }
            }
        }
    } else if ( x == 2){
        for ( i = 0; i < numPeople - 1; i++){
            for ( j = 0; j < numPeople - i - 1; j++){
                if (array[j]->getAge() > array[j + 1]->getAge()){
                    swap(&array[j], &array[j+1]);
                }
            }
        }
    }
}