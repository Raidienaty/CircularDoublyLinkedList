#include <iostream>
#include <Regex>
#include "Node.h"
#include "DataObject.h"

using namespace std;

int main()
{
	string input = "";
	do
	{
		printf("Welcome to my circular doubly linked list!\n");
		printf("Please choose one of the following options:\n");
		printf("1: Display the list\n 2: Add an item\n 3: Delete an item\n 4: Exit\n");

		getline(cin, input);
		
		input = regex_replace(input, regex(R"([^\d]+)"), "");

		cout << input << endl;

		//cout << regex_replace(input, regex("[a-zA-z;:'\n\t\h\r ]+"), "") << "\n";

		/*if (regex_match(input, regex("[a-zA-Z]+")))
			printf("Non-digit!");
		else
			printf("Digit!");*/
	} while (true);
}