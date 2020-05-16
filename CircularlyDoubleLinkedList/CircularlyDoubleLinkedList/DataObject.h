#pragma once
#include <string>
#include <cstdlib>

using namespace std;

class DataObject
{
public:
	string getName();
	void setName(string name);

private:
	string name;
};

