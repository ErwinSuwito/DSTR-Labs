// Tutorial 6 - 22.03.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
public:
    void Mark() {
        float quiz, assignment, exam;
        int num;

        cout << "Enter number of students in the class: ";
        cin >> num;

        float* markarray = new float[num];

        for (int i = 0; i < num; i++) {
            cout << "\nStudents " << i + 1 << endl;
            cout << "What is quiz mark of student [0-20] ";
            cin >> quiz;

            while (quiz < 0 || quiz > 20) {
                cout << "Invalid input\n";
                cout << "What is quiz mark of student [0-20] ";
                cin >> quiz;
            }

            cout << "What is assignment mark of student [0-30]";
            cin >> assignment;

            while (assignment < 0 || assignment > 30) {
                cout << "Invalid input\n";
                cout << "What is assignment mark of student [0-30]";
                cin >> assignment;
            }

            cout << "What is exam mark of student [0-50]";
            cin >> exam;

            while (exam < 0 || exam > 50) {
                cout << "Invalid input\n";
                cout << "What is exam mark of student [0-50]";
                cin >> exam;
            }
            markarray[i] = quiz + assignment + exam;
        }

        float average = 0;

        for (int i = 0; i < num; i++) {
            average = average + markarray[i];
        }
        cout << "Total average mark for all student = " << average / num << endl;
    }
};

void Q1()
{
    Student student;
    student.Mark();
}

class cashRegister
{
    float cashOnHand = 500;

public:
    void acceptAmount(float amount)
    {
        cashOnHand += amount;
    }

    void printBalance()
    {
        cout << "Cash on hand: " << cashOnHand << endl;
    }
};

void showSelection()
{
    cout << "*** Welcome to Candy Shop ***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for Candy" << endl;
    cout << "2 for Chips" << endl;
    cout << "3 for Gum" << endl;

    cout << "4 Print Balance in Cash Register" << endl;
    cout << "5 to exit" << endl;
}

void Q2()
{
    int choice, quantity;
    float getamount;

    showSelection();
    cin >> choice;

    cashRegister counter;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter quantity of candy:";
            cin >> quantity;
            cout << "Candy price is RM" << fixed << setprecision(2) << quantity * 0.65 << endl;
            //10*0.65=6.50
            cout << "Enter amount of cash from customer:";
            cin >> getamount; //6.50
            counter.acceptAmount(getamount);
            //assume all amount cash from customer = price of sales
            break;
        case 2:
            cout << "Enter quantity of chips:";
            cin >> quantity;
            cout << "Chips price is RM" << fixed << setprecision(2) << quantity * 2.50 << endl;
            cout << "Enter amount of cash from customer:";
            cin >> getamount;
            counter.acceptAmount(getamount);
            //assume all amount cash from customer = price of sales
            break;
        case 3:
            cout << "Enter quantity of gum:";
            cin >> quantity;
            cout << "Gum price is RM" << fixed << setprecision(2) << quantity * 1.25 << endl;
            cout << "Enter amount of cash from customer:";
            cin >> getamount;
            counter.acceptAmount(getamount);
            //assume all amount cash from customer = price of sales
            break;
        case 4:
            counter.printBalance();
            break;
        default:
            cout << "Invalid selection." << endl;
        }
        showSelection();
        cin >> choice;
    }
}

class BankAccount 
{
private:
    double balance;
    double interest_rate;

public:
    // The account balance is set to $dollars.cents
    void set(int dollars, int cents);
    // One year of simple interest is added to the account balance
    void update();
    // Return the current account balance
    double get_balance();
    // Return the current interest rate
    double get_rate();
    // rate is set to interest rate
    void set_rate(int rate);
};

void BankAccount::set(int dollars, int cents)
{
    double _cents = cents / (double)100;
    balance = dollars + _cents;
}

void BankAccount::update()
{
    balance = (balance * interest_rate * 1) + balance;
}

double BankAccount::get_balance()
{
    return balance;
}

double BankAccount::get_rate()
{
    return interest_rate;
}

void BankAccount::set_rate(int rate)
{
    interest_rate = rate;
}

void Q3()
{
    BankAccount ba;
    int dollar, cent;
    double rate;

    cout << "Dollar: ";
    cin >> dollar;

    cout << "Cents: ";
    cin >> cent;

    ba.set(dollar, cent);

    cout << "Current balance of account is $";
    printf("%.2f", ba.get_balance());

    cout << endl << "Enter yearly rate: ";
    cin >> rate;
    ba.set_rate(rate);
    ba.update();

    cout << "New balance of account is $";
    printf("%.2f", ba.get_balance());
}

class Population
{
private:
    int population;
    int noOfBirths;
    int noOfDeaths;

public:
    void setPopulation(int i)
    {
        population = i;
    }

    void setBirths(int i)
    {
        noOfBirths = i;
    }

    void setDeaths(int i)
    {
        noOfDeaths = i;
    }

    double getBirthRate()
    {
        double brate;
        brate = (double)noOfBirths / population;
        return brate;
    }

    double getDeathRate()
    {
        double drate;
        drate = (double)noOfDeaths / population;
        return drate;
    }
};

void Q4()
{
    Population population;
    int noOfPopulation = 0;
    int noOfBirth = 0; 
    int noOfDeath = 0;

    while (noOfPopulation < 1)
    {
        cout << endl << "Enter numer of population: ";
        cin >> noOfPopulation;
    }

    while (noOfBirth < 1)
    {
        cout << endl << "Enter numer of births: ";
        cin >> noOfBirth;
    }

    while (noOfDeath < 1)
    {
        cout << endl << "Enter numer of deaths: ";
        cin >> noOfDeath;
    }

    population.setPopulation(noOfPopulation);
    population.setBirths(noOfBirth);
    population.setDeaths(noOfDeath);

    cout << "Death rate is: " << population.getDeathRate() << endl;
    cout << "Birth rate is: " << population.getBirthRate() << endl;
}

int main()
{
    Q4();
}

