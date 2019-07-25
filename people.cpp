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
    std::ifstream infile(fileName);
    numPeople = lineCount(fileName);

    if (infile && numPeople > 0) {
        persons = new Person *[numPeople];
        if (numPeople > 0) {
            for (int i = 0; i < numPeople; i++) {  //Reads line by line through file
                getline(infile, fName, ' ');
                getline(infile, lName, ',');
                getline(infile, idNumber, ',');
                getline(infile, ageValue, ',');
                getline(infile, favFood, '\n');

                //converts ID and age to integers
                id = stoi(idNumber);
                age = stoi(ageValue);


                persons[i] = new Person(fName, lName, id, age, favFood);
            }
            infile.close();
        }
    } else{
        const char* error = "Error: bad file name or empty file.";
        throw error;
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

void People::displayPeople(Sel x) {
    switch (x){
        case 1:bubbleSortArray(persons, 1);
                for (int i = 0; i < numPeople; i++) {
                    std::cout << "    " << std::setfill('0') << std::setw(4) << temp[i]->getid();
                    std::cout << ": " << temp[i]->getlName() << ", " << temp[i]->getfName() << " is " << temp[i]->getAge() << " years old and likes " << temp[i]->getFavoriteFood() << "." << std::endl;
                }
                break;
        case 2:bubbleSortArray(persons, 2);
                for (int i = 0; i < numPeople; i++) {
                    std::cout << "    " << std::setfill('0') << std::setw(4) << temp[i]->getid();
                    std::cout << ": " << temp[i]->getlName() << ", " << temp[i]->getfName() << " is " << temp[i]->getAge() << " years old and likes " << temp[i]->getFavoriteFood() << "." << std::endl;
                }
                break;
        default:for (int i = 0; i < numPeople; i++) {
                    std::cout << "    " << std::setfill('0') << std::setw(4)  << persons[i]->getid();
                    std::cout << ": " << persons[i]->getlName() << ", " << persons[i]->getfName() << " is " << persons[i]->getAge() << " years old and likes " << persons[i]->getFavoriteFood() << "." << std::endl;
                }
                break;
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
        duplicator(persons);
        for ( i = 0; i < numPeople - 1; i++){
            for ( j = 0; j < numPeople - i - 1; j++){
                if (temp[j]->getid() > temp[j + 1]->getid()){
                    swap(&temp[j], &temp[j+1]);
                }
            }
        }
    } else if ( x == 2){
        duplicator(persons);
        for ( i = 0; i < numPeople - 1; i++){
            for ( j = 0; j < numPeople - i - 1; j++){
                if (temp[j]->getAge() > temp[j + 1]->getAge()){
                    swap(&temp[j], &temp[j+1]);
                }
            }
        }
    }
}

void People::duplicator(Person **array){
    temp = new Person*[numPeople];
    for (int i = 0; i < numPeople; i++){
        temp[i] = array[i];
    }

}