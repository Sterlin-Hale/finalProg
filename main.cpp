/*
 * Your header here
 */

#include "main.h"

int main(int argc, char **argv) {
    People *people = NULL;

    if (argc != 2) {
        cout << "Incorrect number of parameters. You must supply a file name." << endl;
    } else {

        cout << "Loading people... ";
        try {
            people = new People(argv[1]);
        } catch (const char* error) {
            cout << error << endl;
        }

        if (people) {
            cout << "done." << endl << endl;
            cout << "Displaying all people in the People object... " << endl;
            people->displayPeople();
            cout << endl << endl;
            cout << "Displaying all people by ID... " << endl;
            people->displayPeople(ID);
            cout << endl << endl;
            cout << "Displaying all people by age... " << endl;
            people->displayPeople(AGE);
            cout << endl << endl;
            cout << "Displaying all people unsorted again... " << endl;
            people->displayPeople();
            cout << endl << endl;

            cout << "Clearing all people from the People object... ";
            people->clear();
            cout << "Done." << endl << endl;
            cout << "Displaying all people in the People object... " << endl;
            people->displayPeople();
            cout << endl << endl;
        }
    }

    return 0;
}

