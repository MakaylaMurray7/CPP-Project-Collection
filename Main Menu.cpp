#include <iostream>
#include <limits>
#include "Main Menu.h"
#include "ClearScreen.h"
#include "Area Of Shapes.h"
#include "Cost Of Armoire.h"
#include "Search and Sort Arrays.h"
#include "Password Validation.h"
#include "Wait For Key Press.h"

using namespace std;

void displayMainMenu()
{
    int choice;
    string exitConfirmation;
    bool quitProgram = false;

    while(!quitProgram)
    {
        ClearScreen();
        cout << "Final Project Main Menu\n" << endl;
        cout << "1. Calculate Area of Shapes" << endl;
        cout << "2. Calculate Armoire Cost" << endl;
        cout << "3. Search and Sort Arrays" << endl;
        cout << "4. Password Validation" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter a menu option: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input, you must choose a menu option that is between 1 and 5.\n";
            waitForKeyPress();
            continue;
        }

        switch(choice)
        {
            case 1: calculateAreaOfShapes();
                break;
            case 2: calculateArmoireCost();
                break;
            case 3: searchAndSortArrays();
                break;
            case 4: passwordValidation();
                break;
            case 5: cout << "Are you sure you want to quit? (Y/N): ";
                cin >> exitConfirmation;
                for (char &character : exitConfirmation)
                {
                    character = toupper(character);
                }
                if (!exitConfirmation.empty() && (exitConfirmation == "Y" || exitConfirmation == "YES"))
                {
                    quitProgram = true;
                }
                break;
            default: cout << "Invalid input, you must choose a menu option that is (1-5)." << endl;
                waitForKeyPress();
                break;
        }
    }
}
