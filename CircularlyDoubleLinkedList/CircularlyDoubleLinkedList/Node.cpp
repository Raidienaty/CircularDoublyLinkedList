#include "Node.h"

Node::Node()
{
	nextNode = nullptr;
	prevNode = nullptr;
	dataObj = nullptr;
}

Node::~Node()
{
}

shared_ptr<Node> Node::getNext()
{
	return nextNode;
}

void Node::setNext(shared_ptr<Node> newNode)
{
	nextNode = newNode;
}

shared_ptr<Node> Node::getPrev()
{
	return prevNode;
}

void Node::setPrev(shared_ptr<Node> newNode)
{
	prevNode = newNode;
}

shared_ptr<DataObject> Node::getData()
{
	return dataObj;
}

void Node::setData(shared_ptr<DataObject> newData)
{
	dataObj = newData;
}
