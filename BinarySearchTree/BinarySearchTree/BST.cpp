#include "stdafx.h"
#include "BST.h"
#include <cstdlib>
#include <iostream>
using namespace std;


BST::BST()
{
	root = NULL;
};
BST::node* BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->Left = NULL;
	n->Right = NULL;

	return n;
};
void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
};
void BST::AddLeafPrivate(int key, node* ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if (key < ptr->key)
	{
		if (ptr->Left != NULL) // less than
		{
			AddLeafPrivate(key, ptr->Left);
		}
		else
		{
			ptr->Left = CreateLeaf(key);
		}
	}
	else if (key > ptr->key) // greater than
	{
		if (ptr->Right != NULL)
		{
			AddLeafPrivate(key, ptr->Right);
		}
		else
		{
			ptr->Right = CreateLeaf(key);
		}
	}
	else // equal to
	{
		cout << "Key " << key << "Has already been added to the tree \n";
	}
};
void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);	
};
void BST::PrintInOrderPrivate(node* ptr)
{
	if (root != NULL)
	{
		if (ptr->Left != NULL)
		{
			PrintInOrderPrivate(ptr->Left);
		}
		cout << ptr->key << " ";
		if (ptr->Right != NULL)
		{
			PrintInOrderPrivate(ptr->Right);
		}
	}

	else
	{
		cout << "the tree is empty" << endl;
	}
};
BST::node* BST::returnNode(int key)
{
	return returnNodePrivate(key, root);
};
BST::node* BST::returnNodePrivate(int key, node* ptr)
{
	if (ptr != NULL)
	{
		if (ptr->key == key)
		{
			return ptr;
		}
		else
		{
			if (key < ptr->key)
			{
				return returnNodePrivate(key, ptr->Left);
			}
			else
			{
				return returnNodePrivate(key, ptr->Right);
			}
		}
	}
	else
	{
		return NULL;
	}
};
int BST::returnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
	{
		return -1000; // no negatives in our search tree
	}
};
void BST::printChildren(int key)
{
	node* ptr = returnNode(key);

	if (ptr != NULL)
	{
		cout << "Parent node = " << ptr->key << endl;

		ptr->Left == NULL ?
			cout << "Left Child = NULL \n" :
			cout << "Left Child = " << ptr->Left->key << endl;
		ptr->Right == NULL ?
			cout << "Right Child = NULL \n" :
			cout << "Right Child = " << ptr->Right->key << endl;

			
	}
	else
	{
		cout << "The Key " << key << "Is not in the tree \n";
	}
};
int BST::findSmallest()
{
	return findSmallestPrivate(root);
};
int BST::findSmallestPrivate(node* ptr)
{
	if (root = NULL)
	{
		cout << "The Tree is Empty" << endl;
		return -1000;
	}
	else
	{
		if (ptr->Left != NULL)
		{
			return findSmallestPrivate(ptr->Left);
		}
		else
		{
			return ptr->key;
		}
	}
};
void BST::removeNode(int key)
{
	removeNodePrivate(key, root);
};
void BST::removeNodePrivate(int key, node* parent)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			removeRootMatch();
		}
		else
		{
			if (key < parent->key && parent->Left != NULL)
			{
				parent->Left->key == key ?
				removeMatch(parent, parent->Left, true) :
				removeNodePrivate(key, parent->Left);
			}
			else if (key > parent->key && parent->Right != NULL)
			{
				parent->Right->key == key ?
				removeMatch(parent, parent->Right, false) :
				removeNodePrivate(key, parent->Right);
			}
			else
			{
				cout << "The Key " << key << " was not found in the tree " << endl;
			}
		}
	}
	else
	{
		cout << "EMPTY" << endl;
	}
};
void BST::removeRootMatch()
{
	if (root != NULL)
	{
		node* delPtr = root;
		int rootKey = root->key;
		int smallestInRightSubTree;


		// case 0 - 0 children x`
		if (root->Left == NULL && root->Right == NULL)
		{
			root = NULL;
			delete delPtr;
		}
		// case 1- 1 child
		else if (root->Left == NULL && root->Right != NULL)
		{
			root = root->Right;
			delPtr->Right = NULL;
			delete delPtr;
			cout << "the root node with " << rootKey << "has been deleted, the new root contains key" << root->key << endl;
		}
		else if (root->Left != NULL && root->Right == NULL)
		{
			root = root->Left;
			delPtr->Left = NULL;
			delete delPtr;
			cout << "the root node with " << rootKey << "has been deleted, the new root contains key" << root->key << endl;
		}
		// case 2 - 2 children
		else
		{
			smallestInRightSubTree = findSmallestPrivate(root->Right);
			removeNodePrivate(smallestInRightSubTree, root);
			root->key = smallestInRightSubTree;
			cout << "The root key containing key " << rootKey << "was overwritten with key " << root->key << endl;
		}
	}
	else
	{
		cout << "The Tree is empty" << endl;
	}


};
void BST::removeMatch(node* parent, node* match, bool left)
{
	if (root != NULL)
	{
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubTree;

		// case 0 -  0 children
		if (match->Left == NULL & match->Right == NULL)
		{
			delPtr = match;
			left == true ? parent->Left = NULL : parent->Right = NULL;
			delete delPtr;
			cout << "The node containing " << matchKey << "was removed " << endl;
		}
		//cast 1 - 1 child
		else if (match->Left == NULL && match->Right != NULL)
		{
			left = true ? parent->Left = match->Right : parent->Right = match->Right;
			match->Right = NULL;
			delPtr = match;
			delete delPtr;

			cout << "The node containing " << matchKey << "was removed " << endl;
		}
		else if (match->Left != NULL && match->Right == NULL)
		{
			left = true ? parent->Left = match->Left : parent->Right = match->Left;
			match->Left= NULL;
			delPtr = match;
			delete delPtr;

			cout << "The node containing " << matchKey << "was removed " << endl;
		}
		// case 2 children
		else
		{
			smallestInRightSubTree = findSmallestPrivate(match->Right);
			removeNodePrivate(smallestInRightSubTree, match);
			match->key = smallestInRightSubTree;
		}


	}
	else
	{
		cout << "Cant remove match, tree is empty" << endl;
	}
}