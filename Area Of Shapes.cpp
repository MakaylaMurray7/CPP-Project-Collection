#include "Area Of Shapes.h"
#include "ClearScreen.h"
#include "Wait For Key Press.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

void calculateAreaOfShapes()
{
    int decision;
    string repeatChoice;
    string exitAnswer;
    bool exitProgram;
    double lengthOfSquare, areaOfSquare, triangleBase, triangleHeight,
    areaOfTriangle, circleDiameter, areaOfCircle;
    const double PI = 3.1415927;

    while(!exitProgram)
    {
        ClearScreen();
        cout << "\tEquations Menu" << endl;
        cout << "1. Calculate the Area of a Square" << endl;
        cout << "2. Calculate the Area of a Triangle" << endl;
        cout << "3. Calculate the Area of a Circle" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice [1-4]: ";
        cin >> decision;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input, you must choose a menu option that is between 1 and 4.\n";
            waitForKeyPress();
            continue;
        }

        switch(decision)
        {
            case 1: cout << "\nWhat is the length of one side of the square? ";
                cin >> lengthOfSquare;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input, you must enter a numeric value.\n";
                    waitForKeyPress();
                    continue;
                }
                if (lengthOfSquare < 0)
                cout << "\nThat is an invalid value. Please run the program again and enter a number that is positive.";
                else
                { areaOfSquare = pow(lengthOfSquare,2.0);
                cout << "The area of the square is: " << setprecision(2) << fixed << areaOfSquare << endl;
                waitForKeyPress();
                }
                break;
            case 2: cout << "\nWhat is the length of the triangle's base? ";
                cin >> triangleBase;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input, you must enter a numeric value.\n";
                    waitForKeyPress();
                    continue;
                }
                cout << "What is the length of the triangle's height? ";
                cin >> triangleHeight;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input, you must enter a numeric value.\n";
                    waitForKeyPress();
                    continue;
                }
                if (triangleBase < 0 || triangleHeight < 0)
                cout << "\nThat is an invalid value. Please run the program again and enter a number that is positive.";
                else
                {
                areaOfTriangle = 0.5 * triangleHeight * triangleBase;
                cout << "The area of the triangle is: " << setprecision(2) << fixed << areaOfTriangle << endl;
                waitForKeyPress();
                }
                break;
            case 3: cout << "\nWhat is the length of the circle's diameter? ";
                cin >> circleDiameter;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input, you must enter a numeric value.\n";
                    waitForKeyPress();
                    continue;
                }
                if (circleDiameter < 0)
                cout << "That is an invalid value. Please run the program again and enter a number that is positive.";
                else
                {
                areaOfCircle = PI/4 * pow(circleDiameter,2.0);
                cout << "The area of the circle is: " << setprecision(2) << fixed << areaOfCircle << endl;
                waitForKeyPress();
                }
                break;
            case 4: cout << "Are you sure you want to return to the main menu? (Y/N): ";
                cin >> exitAnswer;
                for (char &character : exitAnswer)
                {
                    character = toupper(character);
                }
                if (!exitAnswer.empty() && (exitAnswer == "Y" || exitAnswer == "YES"))
                {
                    exitProgram = true;
                }
                break;
            default: cout << "\nThat is an invalid choice. Please enter a valid choice which are numbers 1 through 4." << endl;
                break;
        }
            if(!exitProgram)
            {
               cout << "Do you want to calculate the area of a shape again? (Y/N): ";
               cin >> repeatChoice;
               for (char &character : repeatChoice)
                {
                    character = toupper(character);
                }
               if(!repeatChoice.empty() && (repeatChoice == "Y" || repeatChoice == "YES"))
               {
                   exitProgram = false;
               }
               else
               {
                   exitProgram = true;
               }
            }
    }
}
