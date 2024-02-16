#include <iostream>
#include <cmath>

using namespace std;

//Function Prototypes
void displayMenu();
bool validateSelection(char selection);
int doubleNumber(int& number);
int reverseNumber(int& number);
bool isPrime(int number);
int checkNumber(int& number);
int raisePower(int& number);
int sumNumbers(int& number);
int raisePowOneToTwo(int& number);
int raisePowOneToLast(int& number);

int main()
{
	int number;			//Integer to store the number to be manipulated
	char selection;		//Variable to store the users selection
	char q;

	srand(time(0));
	number = rand() % 90 + 10;	//Generate a random number 10 - 99

	cout << "Anthony Cantu\t" << "L3-1\t" << "L3-3.exe" << endl;
	cout << "The two digit number is: " << number << endl;
	displayMenu();	//Display the menu
	do
	{
		cin >> selection;
		if (validateSelection(selection))
		{
			switch (selection)
			{
			case '1':
				number = doubleNumber(number);
				break;
			case '2':
				number = reverseNumber(number);
				break;
			case '3':
				number = raisePower(number);
				break;
			case '4':
				number = sumNumbers(number);
				break;
			case '5':
				number = raisePowOneToTwo(number);
				break;
			case '6':
				number = raisePowOneToLast(number);
				break;
			case '9':
				cout << endl << "Press any key to Exit.";
				cin.ignore(2, '\n');
				cin.get(q);
				return 0;
			}
			checkNumber(number);
		}
		else
			cout << "Invalid selection." << endl;
		displayMenu();
	} while (selection != '9');
}

//Display selection menu to user
void displayMenu()
{
	cout << "1: Enter 1 to double the number." << endl;
	cout << "2: Enter 2 to reverse the digitis of the number." << endl;
	cout << "3: Enter 3 to raise the number to the power of 2, 3 or 4." << endl;
	cout << "4: Enter 4 to Sum the digits of the number." << endl;
	cout << "5: Enter 5 to raise the first digit to the power of the second digit." << endl;
	cout << "6: Enter 6 to raise the first two digits he power of the last digit." << endl;
	cout << "9: Enter 9 to terminate the program." << endl;
}

//Validate user menu selection
bool validateSelection(char selection)
{
	switch (selection)
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '9':
		return true;
	default:
		return false;
	}
}

//Check the current number
int checkNumber(int& number)
{
	cout << endl; //Line Break
	cout << number << " is " << (isPrime(number) ? "" : "not ")
		 << "prime." << endl;

	if (number < 10)
	{
		cout << number << " is less than 10, "
			 << "so adding 10 to it." << endl;
		number += 10;
	}
	return number;
}

//Double the number
int doubleNumber(int& number)
{
	number *= 2;
	return number;
}

//Reverse the number
int reverseNumber(int& number)
{
	int num = 0,
		reversed = 0;

	while (number > 0)
	{
		num = number % 10;
		reversed = reversed * 10 + num;
		number /= 10;
	}
	number = reversed;
	return number;
}

//Raise the number to the power of 2, 3 or 4
int raisePower(int& number)
{
	bool validSelection;
	char selection;

	do
	{
		cout << endl << "Enter power (2, 3, or 4): ";
		cin >> selection;
		switch (selection)
		{
		case '2':
			number = pow(number, 2);
			validSelection = true;
			break;
		case '3':
			number = pow(number, 3);
			validSelection = true;
			break;
		case '4':
			number = pow(number, 4);
			validSelection = true;
			break;
		default:
			cout << "Invalid selection!" << endl;
			validSelection = false;
		}
	} while (!validSelection);
	return number;
}

//Sum of all digits in the number
int sumNumbers(int& number)
{
	int num = 0,
		sum = 0;

	while (number > 0)
	{
		num = number % 10;
		sum += num;
		number /= 10;
	}
	number = sum;
	return number;
}

//Raise the first digit of the number 
//to the power of the second digit
int raisePowOneToTwo(int& number)
{
	int numOne = number;
	int numTwo = number;

	//Find second digit
	while (numTwo > 99)
		numTwo /= 10;

	numTwo %= 10;

	//Find first digit
	while (numOne > 10)
		numOne /= 10;

	number = pow(numOne, numTwo);

	return number;
}

//Raise the first digit of the number
//to the power of the last digit
int raisePowOneToLast(int& number)
{
	int numOne = number;
	int numTwo = number;

	//Find first digit
	while (numOne > 10)
		numOne /= 10;

	//Find last digit
	numTwo %= 10;

	number = pow(numOne, numTwo);
	return number;
}

//Check if the number is prime
bool isPrime(int number)
{
	if (number <= 1)
		return false;

	for (int i = 2; i * i <= number; i++)
		if (number % i == 0)
			return false;

	return true;
}