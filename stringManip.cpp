//The purpose of this code is to reverse a string using 2 copies of the sampleString (will be updated later to
//incorporate user defined strings when I eventually implement a UI)

//The method that we will be following involves having one string as the original value and the second being the reversed string.

//it will achieve this by looping through string x backwards and copying that indexes letter, and building it in string y.
#include "stringManip.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <cctype>
#include "ctype.h"
#include "windows.h"
#include <cstdio>

using namespace std;

//default constructor
stringManip::stringManip(string sampleString)
{}

//default deconstructor
stringManip::~stringManip()
{}

string lowercaseString(string);

//function for reversing a string
string stringManip::reverseString0(string sampleString)
{
	string x = sampleString;
	string y = "";

	for (int i = x.length() - 1; i >= 0; i--)
	{
		y += x[i];
	}

	return y;
}

//function for changing a string's color
//C++ doesn't switch on strings so we have to do this dumb s**t to make certain strings have attributed values
int stringManip::returnColorValue(string determineColor)
{
	//convert all letters in the string to be lowercase for comparison purposes just in case the user submitted a capital letter on accident.
	if (lowercaseString(determineColor) == "blue")
		return 1;
	else if (lowercaseString(determineColor) == "green")
		return 2;
	else if (lowercaseString(determineColor) == "cyan")
		return 3;
	else if (lowercaseString(determineColor) == "red")
		return 4;
	else if (lowercaseString(determineColor) == "purple")
		return 5;
	else if (lowercaseString(determineColor) == "dark yellow")
		return 6;
	else if (lowercaseString(determineColor) == "white")
		return 7;
	else if (lowercaseString(determineColor) == "grey")
		return 8;
	else if (lowercaseString(determineColor) == "gray")
		return 8;
	else if (lowercaseString(determineColor) == "bright blue")
		return 9;
	else if (lowercaseString(determineColor) == "bright green")
		return 10;
	else if (lowercaseString(determineColor) == "bright cyan")
		return 11;
	else if (lowercaseString(determineColor) == "bright red")
		return 12;
	else if (lowercaseString(determineColor) == "pink")
		return 13;
	else if (lowercaseString(determineColor) == "magenta")
		return 13;
	else if (lowercaseString(determineColor) == "yellow")
		return 14;
	else if (lowercaseString(determineColor) == "bright white")
		return 15;
	else if (lowercaseString(determineColor) == "gurple")
		return 16;
	else
		return 0;
}

//function to lowercase strings for consistency and ease of use in logic checks
string stringManip::lowercaseString(string stringToConvert)	//function for making an entire string lowercase we essentially do this by adding 32 to any strings ascii value
{
	for (int i = 0; stringToConvert[i] != '\0'; i++)
	{
		if (stringToConvert[i] >= 'A' && stringToConvert[i] <= 'Z')
			stringToConvert[i] = stringToConvert[i] + 32;
	}

	return stringToConvert;
}

//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Bright green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Driving function for changing colors
void stringManip::textColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//List builder, complete with list checking for duplicate values
map<string, int> ::iterator itr; //traversal for maps
void stringManip::buildList(string input1, int input2)
{
	//initialize other data
	string userResponse;
	int updateQuantityResponse;
	bool runLoop;
	bool runInnerLoop;

	//if a map entry is already present allow the user to revise the quantity if they wish
	if (catalog.count(input1) != 0)
	{
		textColor(2);
		cout << input1 << " is already in this list! Would you like to change it's quantity Y/N?" << endl << "-> ";
		textColor(15);
		cin >> userResponse;

		do
		{
			runLoop = true;
			cin.clear();
			cin.ignore(10000, '\n');

			//we are changing the quantity
			if (lowercaseString(userResponse) == "y" || lowercaseString(userResponse) == "yes")
			{
				do
				{
					runInnerLoop = true;
					userResponse = "";
					cin.clear();
					cin.ignore(10000, '\n');

					textColor(2);
					cout << endl << "Please input the new amount:" << endl << "-> ";
					textColor(15);
					cin >> updateQuantityResponse;

					if (updateQuantityResponse > 0)
					{
						catalog[input1] = updateQuantityResponse;
						textColor(2);
						cout << endl << "Updated!" << endl << endl;
						runInnerLoop = false;
					}
					else if (updateQuantityResponse < 0)
					{
						textColor(2);
						cout << "Please enter a non-negative number." << endl << endl;
					}
					else
					{
						textColor(2);
						cout << endl << "Removing " << input1 << " from the list..." << endl << endl;
						itr = catalog.find(input1);
						catalog.erase(itr);
						runInnerLoop = false;
					}
				} while (runInnerLoop == true);

				runLoop = false;
			}
			//quantity remains the same
			else if (lowercaseString(userResponse) == "n" || lowercaseString(userResponse) == "no")
			{
				cout << endl;
				runLoop = false;
			}
			//invalid catch-all case
			else
			{
				cout << "Error please provide a proper response!" << endl << endl;
			}
		} while (runLoop == true);

	}
	//otherwise add a new map entry
	else
	{
		catalog[input1] = input2;
		textColor(2);
		cout << input1 << " added with a quantity of " << input2 << "!" << endl << endl;
	}
}

//local function for printing any dictionaries with structure <string, int>
void stringManip::printList(map <string, int>& catalog)
{
	textColor(2);
	cout << "Here is your compiled list:" << endl;
	cout << "---------------------------" << endl;
	textColor(15);
	for (auto& itr : catalog)
	{
		cout << itr.first << " " << itr.second << endl;
	}
}