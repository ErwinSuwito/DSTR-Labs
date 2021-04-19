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
    cout << "4 for search records" << endl;
    cout << "5 for update record" << endl;
    cout << "6 for delete record" << endl;
    cout << "7 for reset (deletes all records)" << endl;

    cout << "0 to exit" << endl;
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

// Tutorial 8 12.04.2021 codes starts here
void searchRecord()
{
    classInfo* ptr = head;
    int searchString;
    cout << "Enter the student ID to search: ";
    cin >> searchString;

    cout << "Searching for " << searchString << "...";
    cout << endl << "Student ID, Midterm test, Assignment, Quiz, Final Exam";

    while (ptr != NULL)
    {
        
        if (ptr->stud_id == searchString)
        {   
            cout << endl << ptr->stud_id << ", " << ptr->test << ", " << ptr->assignment << ", " << ptr->quiz << ", " << ptr->final;
        }

        ptr = ptr->next;
    }

    cout << endl << "End of search";
}

void updateRecord()
{
    classInfo* ptr = head;
    int searchString;
    cout << endl << "Enter a student id to edit: ";
    cin >> searchString;

    while (ptr != NULL)
    {
        if (ptr->stud_id == searchString)
        {
            float test, assignment, quiz, final;
            cout << endl << "Editing student id: " << ptr->stud_id << endl;

            cout << "What is the midterm test mark of student [0-20]: ";
            cin >> test;

            cout << "What is quiz mark of student [0-10]: ";
            cin >> quiz;

            cout << "What is the assignment mark of student [0-20]: ";
            cin >> assignment;

            cout << "What is final exam mark of student [0-50]: ";
            cin >> final;

            ptr->test = test;
            ptr->assignment = assignment;
            ptr->quiz = quiz;
            ptr->final = final;

            cout << "New student data saved successfully.";
        }

        ptr = ptr->next;
    }
}

void deleteRecord()
{
    classInfo* ptr = head;
    int searchString;
    cout << endl << "Enter a student id to delete: ";
    cin >> searchString;

    while (ptr != NULL)
    {
        if (ptr->stud_id == searchString)
        {
            classInfo* before = head;
            if (before->next != NULL)
            {
                while (before != NULL)
                {
                    if (before->next == ptr)
                    {
                        before->next = ptr->next;
                    }
                    before = before->next;
                }
            }
            else
            {
                head = NULL;
            }
            
            delete(ptr);
            return;
        }
        ptr = ptr->next;
    }

}

void reset()
{
    classInfo* ptr = head;

    while (ptr != NULL)
    {
        classInfo* newPtr = ptr->next;
        delete(ptr);
        ptr = newPtr;
    }

    head = NULL;

    cout << "Deleted all records";
}

int main()
{
    int choice;
    showSelection();
    cin >> choice;

    while (choice != 0)
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
            searchRecord();
            break;
        case 5:
            updateRecord();
            break;
        case 6:
            deleteRecord();
            break;
        case 7:
            reset();
            break;
        case 0:
            return 1;
        default:
            cout << "Invalid selection." << endl;
        }

        showSelection();
        cin >> choice;
    }

}

