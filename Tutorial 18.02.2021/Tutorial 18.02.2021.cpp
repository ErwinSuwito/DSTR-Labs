// Tutorial 18.02.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    /*
    std::string name;
    std::cout << "What is your name? ";
    getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";
    
    std::string first;
    std::string last;

    std::cout << "First name: ";
    getline(std::cin, first);
    std::cout << "Last name: ";
    getline(std::cin, last);
    std::cout << first + " " + last;
   

    // lecturer answer
    string first;
    string last;

    cin >> first;
    cin >> last;

    cout << "Hello" << first << " " << last;
     */

    /*
    * Write a program to accept input of height in meter.
    * then convert and display it in foothand inches.
    * Conversion: 1 inch = 2.45 cm, 1 feet = 12 inches
    */

    // Declare variable height and convert meter to cm
    float height;
    cout << "Enter your height in meter: ";
    cin >> height;

    float cm = height * 100;
    float inch = cm / 2.54;
    float foot = inch / 12;

    string helo = "hello";

    // endl is the same \n;
    cout << "Your height in inch is: " << inch << endl;
    cout << "Your height in foot is: " << foot << endl;

    cout << "Your height is  " << floor(foot) << " feet and " << round(remainder(foot, inch)) << " inch." << endl;
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
