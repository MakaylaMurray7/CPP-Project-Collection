#include "Search and Sort Arrays.h"
#include "ClearScreen.h"
#include <iostream>
#include "Wait For Key Press.h"
#include <limits>

using namespace std;

void populateArray(int arr[], int Size)
{
    for(int index = 0; index < Size; index++)
    {
        cout << "Enter number " << index + 1 << ": ";
        cin >> arr[index];
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input, you must enter a numeric value.\n";
            index -= 1;
            waitForKeyPress();
            continue;
        }
    }
}
void linearSearch(int arr[], int Size, int SearchValue, int &Comparisons)
{
    Comparisons = 0;
    for(int index = 0; index < Size; index++)
    {
        Comparisons++;
        if(arr[index] == SearchValue)
        {
            return;
        }
    }
}
void binarySearch(int arr[], int Size, int SearchValue, int &comparisons)
{
    comparisons = 0;
    int first = 0,
    last = Size - 1,
    middle;
    while(first <= last)
    {
        comparisons++;
        middle = (first + last)/2;
        if(arr[middle] == SearchValue)
        {
            return;
        }
        else if (arr[middle] > SearchValue)
            last = middle - 1;
        else
            first = middle + 1;
    }
}
void bubbleSort(int arr[], int Size)
{
    for(int maxIndex = Size - 1; maxIndex > 0; maxIndex--)
    {
        for(int index = 0; index < maxIndex; index++)
        {
            if(arr[index] > arr[index + 1])
            {
                swap(arr[index], arr[index + 1]);
            }
        }
    }
}
void swap(int &val, int &num)
{
    int temp = val;
    val = num;
    num = temp;
}
void displayArray(const int arr[], int Size)
{
    for(int index = 0; index < Size; ++index)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
}
void searchAndSortArrays()
{
    const int SIZE = 20;
    int arr[SIZE];
    int searchValue;
    int linearSearchComparisons;
    int binarySearchComparisons;
    string exitChoice;

    do
    {
        ClearScreen();
        cout << "\tSearch and Sort Arrays" << endl;
        cout << "\nEnter 20 numbers in unsorted order." << endl;
        populateArray(arr, SIZE);
        cout << "Enter a value you would like to search for: ";
        cin >> searchValue;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input, you must enter a numeric value.\n";
            waitForKeyPress();
            continue;
        }
        bubbleSort(arr, SIZE);
        linearSearch(arr, SIZE, searchValue, linearSearchComparisons);
        binarySearch(arr, SIZE, searchValue, binarySearchComparisons);
        string leastComparisons = (linearSearchComparisons < binarySearchComparisons)?"linear search": "binary search";

        cout << "\nThe numbers in sorted order (before binary search): " << endl;
        displayArray(arr, SIZE);
        cout << "\nWhen conducting the linear search it took " <<
        linearSearchComparisons << " searches to find the value." << endl;
        cout << "The binary search took " << binarySearchComparisons << " searches to find the value." << endl;
        cout << "So, the method that is more efficient in searching for the value is the " << leastComparisons << ", because it took fewer searches to find the value." << endl;
        waitForKeyPress();
        cout << "Do you want to perform another search and sort operation on a array? (Y/N): ";
        cin >> exitChoice;
        for (char &character : exitChoice)
        {
            character = toupper(character);
        }
        if(exitChoice != "Y" && exitChoice != "YES")
        {
            break;
        }
    }while(exitChoice == "Y" || exitChoice == "YES" );
}
