// Tutorial 4 - 08.03.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <iomanip> 
#include <algorithm>
using namespace std;

void q1();

void q2();
int getMin(int values[]);
int getMax(int values[]);

void q3();
void q4();
void q5();
void arraySort(int param[]);


int main()
{
	//q1();
	//q2();
	//q3();
	//q4();
	q5();
}

void q1()
{
	int billy[] = { 16, 2, 77, 40, 12071, 51 };

	int total = 0;

	for (int i : billy)
	{
		total = total + i;
	}

	cout << "Output: " << total;
}

void q2()
{
	int values[10];
	cout << endl << "Enter 10 numbers" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "Enter a number: ";
		cin >> values[i];
	}

	int min = getMin(values);
	int max = getMax(values);

	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
}

int getMin(int values[])
{
	int min = values[0];

	for (int i = 0; i < 10; i++)
	{
		if (min > values[i])
		{
			min = values[i];
		}
	}

	return min;
}

int getMax(int values[])
{
	int max = values[0];

	for (int i = 0; i < 10; i++)
	{
		if (max < values[i])
		{
			max = values[i];
		}
	}

	return max;
}

void q3()
{
	char s1[100];
	bool flag = true;

	cout << "Testing for palindrome." << endl;
	cout << "Enter the string: ";
	cin >> s1;

	int length1 = strlen(s1);

	for (int i = 0; i < length1; i++)
	{
		if (s1[i] != s1[length1 - i - 1])
		{
			flag = false;
			break;
		}
	}

	if (flag)
	{
		cout << "Is a palindrom";
	}
	else
	{
		cout << "Not a palindrome";
	}
}

void q4()
{
	int correctTimes = 0;
	char correctAnswers[15] = {
		'A', 'C', 'B', 'B', 'D',
		'D', 'C', 'A', 'B', 'A',
		'A', 'A', 'D', 'D', 'C',
	};

	char answers[15];

	for (int i = 0; i < 15; i++)
	{
		cout << "Enter answer for question number " << i +1 << ": ";
		cin >> answers[i];
	}

	for (int i = 0; i < 15; i++)
	{
		if (answers[i] == correctAnswers[i])
		{
			correctTimes++;
		}
	}

	if (correctTimes > 11)
	{
		cout << "You passed the exam";
	}
	else
	{
		cout << "You failed the exam";
	}
}

void q5()
{
	int a[5] = { 4, 2, 7, 9, 6 };
	arraySort(a);
	for (int i = 0; i < 5; ++i) {
		cout << a[i];
	}
}

void arraySort(int param[]) {
	sort(param, param + 5);
}