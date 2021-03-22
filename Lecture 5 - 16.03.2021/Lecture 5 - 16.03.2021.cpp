// Lecture 5 - 16.03.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Polynomial {
	private:
		int degree; double* coefficients;

	public:
		Polynomial(int degree)
		{
			this->degree = degree;
		}

		Polynomial(int degree, double coefs[])
		{
			this->degree = degree;
			this->coefficients = coefs;
		}

		Polynomial(Polynomial& other)
		{
			degree = other.degree;
			coefficients = other.coefficients;
		}

		~Polynomial()
		{
			cout << endl << "END" << endl;
		}

		Polynomial* add(Polynomial& other)
		{
			Polynomial newPoly = other;

			if (other.degree > degree)
			{
				for (int i = 0; i < degree; i++)
				{
					newPoly.coefficients[i] = coefficients[i] + other.coefficients[i];
				}
			}
			else
			{
				newPoly = *this;
				for (int i = 0; i < other.degree; i++)
				{
					newPoly.coefficients[i] = coefficients[i] + other.coefficients[i];
				}
			}

			*this = newPoly;
			return this;
		}

		void print()
		{
			cout << "Your Equation is: ";
			for (int i = degree; i >= 0; i--)
			{
				if (i == 0)
				{
					cout << coefficients[i] << endl;
				}
				else
				{
					cout << coefficients[i] << "x^" << i << " + ";
				}
			}
		}
};

int main()
{
	double coefs1[] = { 1.5, -2, 0, 6 };
	Polynomial p1(4, coefs1);
	p1.print();

	double coefs2[] = { 2.3, 5, -3,0 };
	Polynomial p2(3, coefs2);
	p2.print();

	Polynomial* resultPtr = p1.add(p2);
	resultPtr->print();

	delete resultPtr;
}
