// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char name[50];
	cout << "Please enter first and last name." << endl;
		cin.getline(name, 50);
	cout << "Hello " << name;
    return 0;
}

