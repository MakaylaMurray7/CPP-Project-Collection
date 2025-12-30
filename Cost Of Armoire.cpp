#include <iostream>
#include <iomanip>
#include "Cost Of Armoire.h"
#include "ClearScreen.h"
#include "Wait For Key Press.h"
#include <limits>

using namespace std;

void get_measurements(double &length, double &depth, double &height)
{
    cout << "Enter the length of the Armoire (in inches), must be more than 18 inches: ";
    cin >> length;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input, you must enter a numeric value.\n";
        waitForKeyPress();
    }
    while(length < 18)
    {
            cout << "Invalid input, size is out of range. The length of the Armoire must be more than 18 inches.\n";
            cout << "Enter the length of the Armoire (in inches), must be more than 18 inches: ";
            cin >> length;
    }
    cout << "Enter the depth of the Armoire (in inches), must be more than 18 inches: ";
    cin >> depth;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input, you must enter a numeric value.\n";
        waitForKeyPress();
    }
    while(depth < 18)
    {
        cout << "Invalid input, size is out of range. The depth of the Armoire must be more than 18 inches.\n";
        cout << "Enter the depth of the Armoire (in inches), must be more than 18 inches: ";
        cin >> depth;
    }
    cout << "Enter the height of the Armoire (in inches), must be between [18-60] inches: ";
    cin >> height;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input, you must enter a numeric value.\n";
        waitForKeyPress();
    }
    while(height < 18 || height > 60)
    {
        cout << "Invalid input, size is out of range. The height of the Armoire must be more than 18 inches and less 60 inches.\n";
        cout << "Enter the height of the Armoire (in inches), must be between [18-60] inches: ";
        cin >> height;
    }
}

double calc_Large_Volume(double length, double depth, double height)
{
    double cubicAdditionalCharge;
    double cubicVolume = length * depth * height;
    if (cubicVolume > 25000)
    {
        cubicAdditionalCharge += 100;
    }
    else
    {
        cubicAdditionalCharge = 0;
    }
    return cubicAdditionalCharge;
}

double calc_Charge(const double baseCost, double cubicAdditionalCost, const double premiumCharge, bool &refTeakOption)
{
    string customLiningChoice;
    double priceOfArmoire = baseCost + cubicAdditionalCost + premiumCharge;
    cout << "Do you want the custom lining made of teak wood, which is an additional $100. Please enter (Y/N): ";
    cin >> customLiningChoice;
    for (char &character : customLiningChoice)
    {
        character = toupper(character);
    }
    if(customLiningChoice == "Y" || customLiningChoice == "YES")
    {
        priceOfArmoire += 100;
        refTeakOption = true;
    }
    else
    {
        refTeakOption = false;
    }
    return priceOfArmoire;
}

double calc_Charge(const double baseCost, double cubicAdditionalCost)
{
    double priceOfArmoire = baseCost + cubicAdditionalCost;
    return priceOfArmoire;
}

void calculateArmoireCost()
{
    const double baseCost = 450.0, premiumCost = 300.0;
    double length, depth, height, priceOfArmoire;
    string premiumChoice;
    string repeat;
    bool teakOption = false;

    do
    {
        ClearScreen();
        cout << "\tCost of Armoire Calculation" << endl;
        cout << "This program will calculate the cost of a Armoire." << endl;
        get_measurements(length, depth, height);
        double cubicAdditionalCharge = calc_Large_Volume(length, depth, height);
        cout << "Would you like to upgrade to the premium Armoire option that is made of Maple, which is an additional $300? Please enter (Y/N): ";
        cin >> premiumChoice;
        for (char &character : premiumChoice)
        {
            character = toupper(character);
        }
        if (premiumChoice == "Y" || premiumChoice == "YES")
        {
            priceOfArmoire = calc_Charge(baseCost, cubicAdditionalCharge, premiumCost,
            teakOption);
            cout << "\nThe premium Armoire has been selected and is an upcharge of $300 to the basic Armoire cost of $450. " << endl;
        }
        else
        {
            priceOfArmoire = calc_Charge(baseCost, cubicAdditionalCharge);
            cout << "\nThe basic Armoire has been selected and is $450. " << endl;
        }
        if (teakOption)
        {
            cout << "Teak lining option was selected and the charge was $100. " << endl;
        }
        if(cubicAdditionalCharge != 0)
            cout << "The large cubic volume charge was incurred and was $100. " << endl;
        cout << fixed << setprecision(2) << "Total cost of the Armoire is $" <<
        priceOfArmoire << "." << endl;
        waitForKeyPress();
        cout << "Do you want to calculate the cost for another Armoire? (Y/N): ";
        cin >> repeat;
        for (char &character : repeat)
        {
            character = toupper(character);
        }
        if(repeat!= "Y" && repeat!= "YES")
        {
            break;
        }
    }while(repeat == "Y" || repeat == "YES");
}
