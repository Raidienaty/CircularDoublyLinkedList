#include "DataObject.h"

DataObject::DataObject()
{
	name = "";
}

DataObject::~DataObject()
{
}

string DataObject::getName()
{
	return name;
}

void DataObject::setName(string name)
{
	this->name = name;
}

bool DataObject::compare(string name)
{
	if (this->name == name)
		return true;
	else
		return false;
}
