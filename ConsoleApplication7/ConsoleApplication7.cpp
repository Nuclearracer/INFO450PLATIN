// ConsoleApplication7.cpp : Defines the entry point for the console application.
//INFO450 Rickey Morris A program that translates a word into pig latin.

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void translateToPigLatin(char word[50]);

int main()
{
	bool again = false;
	do
	{
		char userWord[51];
		char rerun;
		cout << "Please enter a word." << endl;
		translateToPigLatin(userWord);
		cout << "Would you like to translate another word? Press 'y' for yes or 'n' for no, then press enter. ";
		cin >> rerun;
		//Allows user to enter another word if they enter a valid character.
		switch (rerun)
		{
		case 'Y':
		case 'y':
			again = true;
			break;
		case 'N':
		case 'n':
			again = false;
			break;
		default:
			cout << "Thanks for using my program!" << endl;
			again = false;
			break;
		}
	} while (again == true);
	return 0;
}

void translateToPigLatin(char word[50])
{
	bool validInput = false;
	do
	{
		//cin >> ws prevents the 'enter' key from being transferred to the buffer if the user reruns the program.
		//Also ignores any whitespace before a word or character.
		cin >> ws;
		cin.getline(word, 50);
		//Checks for a number at the beginning of the word and continues to prompt for a valid input.
		if (isdigit(word[0]))
		{
			validInput = false;
			cout << "Numbers are not allowed as the first character. Please try again." << endl;
		}
		//If first character is not a number, the program then chekcs whether or not the word is two characters long.
		else
		{
			if (strlen(word) == 2)
			{
				validInput = true;
			}
			else
			{
				//If word is less than or greater than two characters, a switch case checks for vowels. Default case runs
				//if a value is not the first character.
				switch (word[0])
				{
				case 'a':
				case 'A':
				case 'e':
				case 'E':
				case 'i':
				case 'I':
				case 'o':
				case 'O':
				case 'u':
				case 'U':
					strcat_s(word, 50, "ay");
					break;
				default:
				{
					validInput = true;
					unsigned int leadLetter, tandemLetter;
					for (leadLetter = 0, tandemLetter = 1; leadLetter < strlen(word) - 1; leadLetter++, tandemLetter++)
					{
						char token[50] = "";
						strcpy_s(token, word);
						token[leadLetter] = word[tandemLetter];
						token[tandemLetter] = word[leadLetter];
						strcpy_s(word, 50, token);
					}
					strcat_s(word, 50, "ay");
				}
				break;
				}
			}cout << "Translation: " << word << endl;
		}
	} while (validInput == false);