// Tutorial 25.02.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>

int main()
{
    /*
    * Question 1: Areas of Rectangles
    * The area of a rectangle is the rectangle’s length times its width. Write a program that asks for
      the length and width of two rectangles. The program should tell the user which rectangle has
      the greater area, or if the areas are the same.
    */
    float length1, width1, length2, width2, area1, area2;

    cout << "Enter the width and length of the first rectangle:" << endl;

    cout << "Width: ";
    cin >> width1;
    cout << "Length: ";
    cin >> length1;

    cout << "Enter the width and length of the second rectangle:" << endl;

    cout << "Width: ";
    cin >> width2;
    cout << "Length: ";
    cin >> length2;

    area1 = width1 * length1;
    area2 = width2 * length2;

    if (area1 > area2)
    {
        cout << "Rectangle 1 is bigger";
    }
    else
    {
        cout << "Rectangle 2 is bigger";
    }

    /*
    * Question 2: Roman Numeral Converter
    * Write a program that asks the user to enter a number within the range of 1 through 10. Use a
      switch statement to display the Roman numeral version of that number.

      Input validation: Do not accept a number less than 1 or greater than 10.
    */

    int q2input = 0;

    do
    {
        cout << endl << "Enter a number between one and ten: ";
        cin >> q2input;

        switch (q2input)
        {
            case 1:
                cout << "The roman number is I";
                break;
            
            case 2:
                cout << "The roman number is II";
                break;

            case 3:
                cout << "The roman number is III";
                break;

            case 4:
                cout << "The roman number is IV";
                break;

            case 5:
                cout << "The roman number is V";
                break;

            case 6:
                cout << "The roman number is VI";
                break;

            case 7:
                cout << "The roman number is VII";
                break;

            case 8:
                cout << "The roman number is VIII";
                break;

            case 9:
                cout << "The roman number is IX";
                break;

            case 10:
                cout << "The roman number is X";
                break;

            default:
                cout << "You did not enter a valid number.";
                break;
        } 
        cout << endl;
    } while (q2input < 0 || q2input > 10);


    /*
    * Question 3: Calories Burned
    * Running on a particular treadmill you burn 3.9 calories per minute. Write a program that uses
      a loop to display the number of calories burned after 10, 15, 20, 25, and 30 minutes.
    */

    int workoutDuration = 0;
    const float calBurnedPerMinute = 3.9;
    float burnedCal = 0;

    while (workoutDuration < 31)
    {
        workoutDuration = workoutDuration + 5;
        burnedCal = burnedCal + calBurnedPerMinute;
        cout << "You have worked out for " << workoutDuration << " minutes. You have burned " << burnedCal << " calories." << endl;
    }

    /*
    * Question 4: Sum value
    * Write a program that asks the user for a positive integer value. The program should use a loop
      to get the sum of all the integers from 1 up to the number entered. For example, if the user
      enters 50, the loop will find the sum of 1, 2, 3, 4, … 50.
      
      Input validation: Do not accept a negative number.
    */

    int q4input = 0;
    do
    {
        cout << endl << "Enter a positive number: ";
        cin >> q4input;

        if (!(q4input < 0))
        {
            int sum = 0;

            for (int i = 0; i < q4input + 1; i++)
            {
                sum = sum + i;
            }

            cout << "The sum from 1 to " << q4input << " is: " << sum;
        }

    } while (q4input < 0);
}