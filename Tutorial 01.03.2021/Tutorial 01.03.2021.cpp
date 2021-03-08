// Tutorial 01.03.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
using namespace std;

double convert(double input);

int main()
{
    double measurement;
    cout << "Enter a length in inches, and i will convert \n";
    cout << "it in to centimeters: \n";
    cin >> measurement;
    measurement = convert(measurement);
    cout << fixed << setprecision(4);
    cout << "Value in centromeres: " << measurement << endl;
}

double convert(double input)
{
   return input * 2.54;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
