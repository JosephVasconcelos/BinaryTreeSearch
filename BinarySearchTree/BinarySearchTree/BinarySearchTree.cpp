// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;


int main()
{
	int treeKey[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
	BST myTree;
	int input = 0;


	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(treeKey[i]);
	}

	cout << "Printing the tree in order" << endl;
	cout << "after adding numbers " << endl;
	myTree.PrintInOrder();
	cout << endl;
	cout << endl;
	

	//printing out the parent and children nodes for every node in the tree
	for (int i = 0; i < 16; i++)
	{
		myTree.printChildren(treeKey[i]);
		cout << endl;
	}
	
	cout << "Smallest node in tree: " << myTree.findSmallest() << endl;

	cout << "Enter a key value to delete. Enter -1 to stop" << endl;
	while (input != -1)
	{
		cout << "Delete node: ";
		cin >> input;
		{
			if (input != -1)
			{
				cout << endl;
				myTree.PrintInOrder();
				myTree.removeNode(input); 
				myTree.PrintInOrder();
			
				cout << endl;
			}
		}
	}


	system("PAUSE");

    return 0;
}

