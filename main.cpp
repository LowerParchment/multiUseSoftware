//This is the main client code that will run everything
#include "stringManip.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
#include <limits>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	string userString;
	string userResponse;
	int temp = 0;
	int command;
	string userColorSubmission;
	//state defines whether the do while block is looping or not. If it isn't the code should eventually break out
	//causing the program to end.
	int stateOfLoop = 1;

	stringManip r0(userString);

	r0.textColor(2);
	cout << "Hello! Welcome to my word manipulation program that I wrote myself. This program will "
		<< "eventually support other functionality as well so please stay tuned!" << endl << endl;

	do {
		//clear all the values (cache) each time the loop is run
		userString = "";
		command = 0;
		userColorSubmission = "";

		r0.textColor(2);
		cout << "Please input a word you would like to change. Alternatively input % to exit the program..." << endl << "-> ";
		r0.textColor(15);
		getline(cin, userString);

		if (userString == "%")
		{
			return 0;
		}

		/*
		if (userString[0] == '/')
		{
			if (userString == "/help")
			{
				color(2);
				cout << "Hello welcome to our help menu" << endl;
			}
			else if (userString == "/ping")
			{
				color(2);
				cout << "Pong!" << endl;
			}
			else
			{
				color(2);
				cout << "Invalid Command! Please try again later." << endl;
			}
		} */

		cout << endl;

		r0.textColor(2);
		cout << "Now type the corresponding number for what you wish for me to do with this word? " <<
			"Your options are : \"0 = exit program,\" \"1 = reverse,\" \"2 = change color\" \"3 = add to a list\"" << endl << "-> ";
		r0.textColor(15);
		cin >> command;
		cout << endl;
		command = static_cast<int>(command);

		switch (command)
		{
			stateOfLoop = 1;

			//exit the program
		case 0:
		{
			stateOfLoop = 0;

			break;
		}
		//reverse the given string
		case 1:
		{
			r0.textColor(2);
			cout << "The initial word is: ";
			r0.textColor(15);
			cout << "'" << userString << "'" << endl;
			r0.textColor(2);
			cout << "Your reversed word is: ";
			r0.textColor(15);
			cout << "'" << r0.reverseString0(userString) << "'" << endl << endl;

			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		//change color
		case 2:
		{
			cin.clear();
			cin.ignore(10000, '\n');

			r0.textColor(2);
			cout << "What color would you like your text to be? Your options are: \"Blue,\" \"Green,\" \"Cyan,\" \"Red,\" \"Purple,\" \"Dark Yellow,\" \"White,\" \"Grey/Gray,\"" <<
				"\"Bright Blue/Green/Cyan/Red/White,\" \"Pink,\" \"Magenta,\" and \"Yellow,\"" << endl << "-> ";
			r0.textColor(15);
			getline(cin, userColorSubmission);
			cout << endl;

			if (r0.returnColorValue(userColorSubmission) == 16)
			{
				system("Color E5");
				cout << "GURPLE!!!" << endl << endl;
				system("Color E5");
				cin.clear();
				break;
			}
			else if (r0.returnColorValue(userColorSubmission) != 0)
			{
				r0.textColor(2);
				cout << "The initial word is: ";
				r0.textColor(15);
				cout << "'" << userString << "'" << endl;
				r0.textColor(2);
				cout << "Your new colored word is: ";
				r0.textColor(r0.returnColorValue(userColorSubmission));
				cout << "'" << userString << "'" << endl << endl;
			}
			else
			{
				r0.textColor(2);
				cout << "Invalid input, please provide a legal command as previously listed!" << endl << endl;
				cin.clear();
				break;
			}

			cin.clear();
			break;
		}
		//shopping list
		case 3:
		{
			bool runLoop;
			bool runInnerLoop = true;
			do
			{
				runLoop = true;
				command = 0;
				userResponse = "";
				cin.clear();
				cin.ignore(10000, '\n');

				r0.textColor(2);
				cout << "Welcome to our shopping list program! Start by telling me what you want to add to your list..." << endl << "-> ";
				
				r0.textColor(15);
				getline(cin, userString);

				r0.textColor(2);
				cout << endl << "Continue adding to our list Y/N?" << endl << "-> ";
				r0.textColor(15);
				getline(cin, userResponse);

				if ((r0.lowercaseString(userResponse) == "y" || r0.lowercaseString(userResponse) == "yes") && r0.catalog.count(userString) == 0)
				{
					do
					{
						command = 0;
						cin.clear();

						r0.textColor(2);
						cout << endl << "How many " << userString << " should I add to our list?" << endl << "-> ";
						r0.textColor(15);
						cin >> command;

						if (!isdigit(command))
						{
							cout << endl;
							runInnerLoop = false;

							r0.buildList(userString, command);
						}
						else
						{
							r0.textColor(2);
							cout << endl << "Please input a valid digit!" << endl;
						}

					} while (runInnerLoop == true);

					
				}
				else if ((r0.lowercaseString(userResponse) == "y" || r0.lowercaseString(userResponse) == "yes") && r0.catalog.count(userString) == 1)
				{
					r0.textColor(2);
					cout << endl;
					r0.buildList(userString, command);
				}
				else if (r0.lowercaseString(userResponse) == "n" || (r0.lowercaseString(userResponse) == "no"))
				{
					cout << endl;
					runLoop = false;
				}
				else
				{
					r0.textColor(2);
					cout << endl << "Invalid input, please provide a valid response!" << endl << endl;
					cin.clear();
				}

			} while (runLoop == true);

			r0.printList(r0.catalog);

			cout << endl;

			break;
		}
		//default case if given invalid input
		default:
		{
			r0.textColor(2);
			cout << "Invalid input, please provide a legal command as previously listed!" << endl << endl;

			cin.clear();
			break;
		}
		}

	} while (stateOfLoop != 0);

	return 0;
}