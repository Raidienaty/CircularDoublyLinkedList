#include <iostream>
#include <Regex>
#include "Node.h"
#include "DataObject.h"

using namespace std;

void displayList(shared_ptr<Node> listHead);
void addItem(shared_ptr<Node> &listHead);
void removeItem(shared_ptr<Node> &listHead);
void describeItem(shared_ptr<Node> listHead);

int main()
{
	shared_ptr<Node> listHead(new Node());
	listHead->setData(nullptr);

	string input = "";
	do
	{
		printf("Welcome to my circular doubly linked list!\n");
		printf("Please choose one of the following options:\n");
		printf("1: Display the list\n 2: Add an item\n 3: Delete an item\n 4: Exit\n");

		//Reads in all input into var input
		getline(cin, input);
		
		//Trims out all non-digit characters
		input = regex_replace(input, regex(R"([^\d]+)"), "");

		//Chooses the corresponding choice based on input
		//Try-Catch is used if the input variable is empty due to no digit inputted
		try
		{
			switch (stoi(input))
			{
			case 1:
				cout << "Display the list\n";
				displayList(listHead);
				break;

			case 2:
				cout << "Add an item\n";
				addItem(listHead);
				break;

			case 3:
				cout << "Remove an item\n";
				removeItem(listHead);
				break;

			case 4:
				cout << "Exit\n";
				return 0;

			default:
				cout << "That's not a valid choice!\n";
				break;
			}
		}
		catch (exception e)
		{
			printf("You must enter a number!\n");
		}
	} while (true);
}

void displayList(shared_ptr<Node> listHead)
{
	printf("List:\n");

	if (listHead->getData() == nullptr && listHead->getNext() == nullptr)
	{
		printf("List is empty!\n");
		return;
	}
	else
	{
		shared_ptr<Node> temp = listHead;

		while (temp->getNext() != listHead)
		{
			printf("%s\n", temp->getData()->getName().c_str());

			temp = temp->getNext();
		}
		printf("%s\n", temp->getData()->getName().c_str());
	}
}

void addItem(shared_ptr<Node> &listHead)
{
	string input = "";
	printf("Add an item has been selected\n");
	printf("What would you like the name of your item to be?\n");

	getline(cin, input);

	shared_ptr<Node> newNode(new Node());
	shared_ptr<DataObject> newData(new DataObject());
	newData->setName(input);
	newNode->setData(newData);

	//Checks if the list is empty
	if (listHead->getData() == nullptr && listHead->getNext() == nullptr)
	{
		listHead = newNode;
		listHead->setNext(listHead);
		listHead->setPrev(listHead);
	}
	else
	{
		shared_ptr<Node> temp = listHead;
		while (temp->getNext() != listHead)
		{
			temp = temp->getNext();
		}
		newNode->setNext(listHead);
		newNode->setPrev(temp);
		temp->setNext(newNode);
		listHead = newNode;
	}
}

void removeItem(shared_ptr<Node> &listHead)
{
	string input = "";
	printf("What item would you like to delete?\n");

	getline(cin, input);

	if (listHead->getData() == nullptr && listHead->getNext() == nullptr)
	{
		printf("List is empty!");
		return;
	}
	else if (listHead->getNext() == listHead)
	{
		listHead->setData(nullptr);
		listHead->setNext(nullptr);
		listHead->setPrev(nullptr);
	}
	else
	{
		shared_ptr<Node> temp = listHead;
		shared_ptr<Node> nextNode;

		while (temp->getNext()->getData()->compare(input))
		{
			temp = temp->getNext();
		}

		nextNode = temp->getNext()->getNext();

		temp->getNext()->setPrev(nullptr);
		temp->getNext()->setNext(nullptr);
		temp->getNext()->setData(nullptr);

		temp->setNext(nextNode);
		nextNode->setPrev(temp);

		listHead = temp;
	}
}
