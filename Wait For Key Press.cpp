#include <iostream>
#include <string>
#include "Wait For Key Press.h"

using namespace std;

void waitForKeyPress()
{
    cout << "Press the enter key to continue.";
    cin.ignore();
    cin.get();
};
