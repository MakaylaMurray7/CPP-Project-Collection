#include "Password Validation.h"
#include "ClearScreen.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include "Wait For Key Press.h"

using namespace std;

void verifyPassword(const char password[], bool&validPassword)
{
    bool upper = false,
    lower = false,
    digit = false,
    specCharacters = false;
    validPassword = true;
    const char specChar[] = "?#%&!@{}\^";
    if(strlen(password) < 5)
    {
        cout << "Password must at least be five characters long." << endl;
    }
    for(int index = 0; index < strlen(password); index++)
    {
    if(isupper(password[index]))
    {
    upper = true;
    }
    if(islower(password[index]))
    {
    lower = true;
    }
    if(isdigit(password[index]))
    {
    digit = true;
    }
    if(strchr(specChar, password[index]))
    {
    specCharacters = true;
    }
    }
    if(!(upper))
    {
    cout << "Password must have at least one uppercase letter." << endl;
    validPassword = false;
    }
    if(!(lower))
    {
    cout << "Password must have at least one lowercase letter." << endl;
    validPassword = false;
    }
    if(!(digit))
    {
    cout << "Password must have at least one digit." << endl;
    validPassword = false;
    }
    if(!(specCharacters))
    {
    cout << "Password must have at least one of the following special characters: ? # % & ! @ { } \ ^" << endl;
    validPassword = false;
    }
    if(validPassword)
    {
        cout << "Password is valid." << endl;
    }
    else
    {
        cout << "Password is not valid." << endl;
    }
}
void passwordValidation()
{
    const int SIZE = 45;
    char password[SIZE];
    string repeatProcess;
    bool valid;
    do
    {
        ClearScreen();
        cout << "\tPassword Validation" << endl;
        cout << "\nPlease enter a password that meets the following criteria:" << endl;
        cout << "At least 5 characters long" << endl;
        cout << "At least 1 uppercase and 1 lowercase letter." << endl;
        cout << "At least 1 digit" << endl;
        cout << "Contains at least one of the following ten characters: ?#%&!@{}^\ " << endl;
        cout << "Enter password: ";
        cin.ignore();
        cin.getline(password,SIZE);
        verifyPassword(password, valid);
        waitForKeyPress();
        cout << "Do you want to enter another password? (Y/N): ";
        cin >> repeatProcess;
        for (char &character : repeatProcess)
        {
            character = toupper(character);
        }
        if(repeatProcess!= "Y" && repeatProcess != "YES")
        {
            break;
        }
    }while(repeatProcess == "Y" || repeatProcess == "YES");
}

