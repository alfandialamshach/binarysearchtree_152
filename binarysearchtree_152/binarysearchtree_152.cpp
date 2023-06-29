#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Contructor for the node class
	Node(string i, Node * l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL;	//initializing ROOT to NULL
	}

	void insert(string element)		//Insert a node in the binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL);	//Allocate memory for the new node
		newNode->info = element;	// Assign value to the data field of the new node
		newNode->leftchild = NULL;  // Make the left child of the new node point to null
		newNode->rightchild = NULL; //Make the right child of the new node point to null

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode);	//Locate the node which will be parent of the node to be inserted

		if (parent == NULL) // If the parent is NULL (TREE is empety)
		{
			ROOT = newNode;	//Mark the new node as ROOT
			return; //Exxit
		}

		if (element < parent->info)	//if the value in the data field of the new node is less than of the parent
		{
			parent->leftchild = newNode;	//Make the left child of the parent point the new node
		}
	}

};