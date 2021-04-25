// Lecture 9 - 20.04.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<int> stack2;
    string input = "(a+b((c*d)-(e+f)*g/h))*i+(j+(k/l))";
    int i = 0;

    for (char c : input)
    {
        i++;
        if (c == '(') {
            stack2.push(i);
            continue;
        }

        if (stack2.empty())
        {
            cout << "Stack is empty";
            return 0;
        }

        if (c == ')')
        {
            cout << "(" << stack2.top() << ", " << i << ")";
            stack2.pop();
        }
    }

    /*
    stack<double> stack1;
    stack1.push(20.5);
    stack1.push(90.9);
    stack1.push(99.9);
    stack1.push(72.4);

    stack1.pop();
    stack1.pop();

    stack1.push(88.2);

    while (!stack1.empty()) {
        cout << ' ' << stack1.top();
        stack1.pop();
    }
    */
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
