#pragma once
#include <string>
#include <cstdlib>

using namespace std;

class DataObject
{
public:
	DataObject();
	~DataObject();
	string getName();
	void setName(string name);
	bool compare(string name);

private:
	string name;
};

