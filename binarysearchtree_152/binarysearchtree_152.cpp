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
		else if (element > parent->info)	// if the value in the data field of the new node is greater than that of the parent
		{
			parent->leftchild = newNode;	// Make the right child of the parent point to the new node
		}
	}


	void search(string element, Node*& parent, Node*& currentNode)
	{
		//This function searches the current node of the specified node as well as the current node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empety" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empety" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr)
	{
		//Performs the postorder traversal of the tree
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main()
{
	BinaryTree obj;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case '2':
		{
			obj.inorder(obj.ROOT);
			break;
		}
		case '3':
		{
			obj.preorder(obj.ROOT);
			break;
		}
		case '4':
		{
			obj.postorder(obj.ROOT);
			break;
		}
		case '5':
		{
			return 0;
		default:
		{
			cout << "Invalid option" << endl;
			break;
		}
		}
		}
	}
}