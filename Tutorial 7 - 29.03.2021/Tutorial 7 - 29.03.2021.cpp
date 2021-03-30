// Tutorial 7 - 29.03.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct classInfo {
    int stud_id;
    float test, assignment, quiz, final;
    classInfo* next;
};

struct classInfo* head = NULL;

void showSelection()
{
    cout << endl << "*** Student Mark System ***" << endl;
    cout << "To perform an action, enter " << endl;
    cout << "1 for Add New Student" << endl;
    cout << "2 for Display Student Marks" << endl;
    cout << "3 for Display Best Student" << endl;

    cout << "4 to exit" << endl;
}

bool findId(int id)
{
    classInfo* ptr;
    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->stud_id == id)
        {
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

void newRecord()
{
    int studentId;
    float test, assignment, quiz, final;

    // request info from user
    cout << "Enter student ID: ";
    cin >> studentId;

    bool duplicateId = findId(studentId);

    while (duplicateId == true)
    {
        cout << "Duplicate Student ID! Re-enter student ID: ";
        cin >> studentId;
        duplicateId = findId(studentId);
    }

    cout << "What is the midterm test mark of student [0-20]: ";
    cin >> test;

    cout << "What is quiz mark of student [0-10]: ";
    cin >> quiz;

    cout << "What is the assignment mark of student [0-20]: ";
    cin >> assignment;

    cout << "What is final exam mark of student [0-50]: ";
    cin >> final;

    // create node
    struct classInfo* newNode = (struct classInfo*)malloc(sizeof(struct classInfo));

    // move info to node
    newNode->stud_id = studentId;
    newNode->test = test * 20 / 100;
    newNode->assignment = assignment * 20 / 100;
    newNode->quiz = quiz * 10 / 100;
    newNode->final = final * 50 / 100;
    
    newNode->next = head;
    head = newNode;
}


void displayRecord()
{
    classInfo* ptr;
    ptr = head;

    if (ptr == NULL)
    {
        cout << "No record in the list";
        return;
    }

    cout << endl << "Student ID, Midterm test, Assignment, Quiz, Final Exam, Total Mark";
    while (ptr != NULL)
    {
        float total = ptr->test + ptr->assignment + ptr->final + ptr->quiz;
        cout << endl << ptr->stud_id << ", " << ptr->test << ", " << ptr->assignment << ", " << ptr->quiz << ", " << ptr->final << ", " << total;
        ptr = ptr->next;
    }
}

void bestStudent()
{
    classInfo* ptr;
    classInfo* highestStudent = NULL;
    ptr = head;
    float highestTotal = 0;

    while (ptr != NULL)
    {
        float total = ptr->test + ptr->assignment + ptr->final + ptr->quiz;
        if (highestTotal < total)
        {
            highestTotal = total;
            highestStudent = ptr;
        }
        ptr = ptr->next;
    }

    cout << "Highest Mark: " << highestTotal << endl;
    if (highestStudent != NULL)
    {
        cout << "Student ID, Midterm test, Assignment, Quiz, Final Exam, Total Mark";
        cout << endl << highestStudent->stud_id << ", " << highestStudent->test << ", " << highestStudent->assignment << ", " << highestStudent->quiz << ", " << highestStudent->final << ", " << highestTotal;
    }
}

int main()
{
    int choice;
    showSelection();
    cin >> choice;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            newRecord();
            break;
        case 2:
            displayRecord();
            break;
        case 3:
            bestStudent();
            break;
        case 4:
            return 1;
        default:
            cout << "Invalid selection." << endl;
        }
        showSelection();
        cin >> choice;
    }

}

