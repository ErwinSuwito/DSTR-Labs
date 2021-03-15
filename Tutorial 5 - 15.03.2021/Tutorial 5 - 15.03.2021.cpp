// Tutorial 5 - 15.03.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void q1();
void q2();
void q3();

int main()
{
    q2();
}

void q1()
{
    /*Exercise 1
    *1.Store a value of "Pizza" into string datatype of the variable named 'food'.
    *2.Display output the value of 'food'
    *3.Display output the memory address of 'food'
    *4.Create a pointer with string datatype of the variable named 'ptr' to store the memory address of food.
    *5.Display output the value of 'ptr'
    *6.Get memory address and value of variable food by using pointer. Implement Referencing and Dereferencing.
    *7.Change the value of the pointer from "Pizza" to "Hamburger"
    *8.Display the new value of the pointer and variable 'food'.
    */

    // 1.
    string food = "Pizza";

    // 2.
    cout << food << endl;

    // 3.
    cout << &food << endl;

    // 4.
    string* ptr = &food;

    // 5.
    cout << ptr << endl;

    // 6.
    cout << *ptr << endl;
    cout << ptr << endl;

    // 7. 
    *ptr = "Hamburger";

    // 8.
    cout << ptr << endl;
    cout << *ptr;
}

void q2()
{
    /*Exercise 2
    * 1.Write a C++ program to get input from user for an array size.
    * 2.Prompt user to get another input of values to be stored in the
    * array according to the array size captured previously.
    * 3.Display all values in the array.
    */

    // 1.
    cout << "Enter an array size: ";
    int arrSize = 0;
    cin >> arrSize;
    string* array = new string[arrSize];

    // 2.
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Please enter a value for " << i + 1 << ": ";
        string value;
        cin >> value;

        array[i] = value;
    }

    // 3. Prints out the array
    for (int i = 0; i < arrSize; i++)
    {
        cout << array[i] << endl;
    }

}

void q3()
{

}
