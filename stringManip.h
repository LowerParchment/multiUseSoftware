//This is the header file for our reverseString functions
#pragma once
#ifndef stringManip_H
#define stringManip_H

#include <string>
#include <map>

using namespace std;

class stringManip
{
public:
	//Default Constructor
	//revStringManip(const string initialString);
	stringManip(string sampleString);

	//Default Destructor
	~stringManip();

	//*-----------------
	//Reverse functions
	//*-----------------
	//This reverse string function makes use of 2 strings, the original, and a copy.
	//The copy is changed, while the original remains unchanged in case it's needed again.
	string reverseString0(string initialString);

	//This function makes use of pass by reference to store less values and save space.
	//string reverseString1(sampleString);

	//This function will change the color of the given input
	int returnColorValue(string providedColor);

	//This function drives the color change
	void textColor(int color);

	//We build shopping lists here boi
	map<string, int>catalog; //declare a map to store our strings and their quantities, sadly it must be global to have other functions interact with it
	string lowercaseString(string input);
	void buildList(string input1, int input2);
	void printList(map<string, int>& map);

private:

};

#endif
