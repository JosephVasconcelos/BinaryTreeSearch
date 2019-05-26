#pragma once
class BST
{
private:
	struct node {
		int key;
		node* Left;
		node* Right;
	};
	node* root; // reference root node
	void AddLeafPrivate(int key, node* ptr);
	void PrintInOrderPrivate(node* ptr);
	node* returnNodePrivate(int key, node* ptr);
	int findSmallestPrivate(node* ptr);
	void removeNodePrivate(int key, node* parent);
	void removeRootMatch();
	void removeMatch(node* parent, node* match, bool left);
public:
	BST();
	node* CreateLeaf(int key);
	void AddLeaf(int key);
	void PrintInOrder();
	node* returnNode(int key);
	int returnRootKey();
	void printChildren(int key);
	int findSmallest();
	void removeNode(int key);

};

