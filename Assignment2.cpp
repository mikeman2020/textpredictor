// Assignment2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int    data;
	node*	left;
	node*   right;
}Node;

typedef struct {
	node* root;
}Head;

//Create empty dictionary tree
Head* CreateTree() {
	Head* myTree = new Head;
	myTree->root = NULL;
	return myTree;
}

//rec
int AddNodeRecursive(Node* addnode, char data) {
	if (data < addnode->data)
		if (addnode->left == NULL) {
			// place the node on the left
			Node* pNew = new Node;
			pNew->data = data;
			pNew->left = NULL;
			pNew->right = NULL;
			addnode->left = pNew;
		}
		else {
			AddNodeRecursive(addnode->left, data);
		}

	else {
		if (addnode->right == NULL) {
			//place node on the right
			Node* pNew = new Node;
			pNew->data = data;
			pNew->left = NULL;
			pNew->right = NULL;
			addnode->right = pNew;
		}
		else {
			AddNodeRecursive(addnode->right, data);
		}
	}

}

//Function to add new node(a letter) to tree
void AddNode(Head* myTree, char data) {
	if (myTree->root == NULL) {
		Node* pNew = new Node;
		pNew->data = data;
		pNew->left = NULL;
		pNew->right = NULL;
		myTree->root = pNew;
	}
	else
		AddNodeRecursive(myTree->root, data);
}



int main()
{
	Head* dictionaryTree = CreateTree();


	system("pause");
	return 0;
}