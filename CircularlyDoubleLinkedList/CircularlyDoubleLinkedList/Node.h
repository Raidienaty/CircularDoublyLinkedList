#pragma once
#include <string>
#include "DataObject.h"

using namespace std;

class Node
{
public:
	Node();
	~Node();

	shared_ptr<Node> getNext();
	void setNext(shared_ptr<Node>);

	shared_ptr<Node> getPrev();
	void setPrev(shared_ptr<Node>);

	shared_ptr<DataObject> getData();
	void setData(shared_ptr<DataObject>);
private:
	shared_ptr<Node> nextNode;
	shared_ptr<Node> prevNode;
	shared_ptr<DataObject> dataObj;
};

