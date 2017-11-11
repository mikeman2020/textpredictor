// Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "string.h"

typedef struct Node {
	char data;
	Node* next;
} node;

typedef struct {
	int count;
	node* head;
} ListHead;


ListHead *CreateTree() {
	ListHead *myLH = new ListHead;
	// Empty list is created.
	// Element counter is set to zero
	myLH->count = 0;
	// Top should address NULL as it is an empty list
	myLH->head = NULL;
	return myLH;
}

bool AddWordRecursive(node *aList, char letter) {

	if (aList->data == NULL) {
		Node* pNew = new Node;
		pNew->data = letter;
		ListHead *newList = CreateTree();
		pNew->next = newList->head;
		aList = pNew;
	}
	else {
		AddWordRecursive(aList->next, letter);
		return true;
	}

}

int AddWord(ListHead* aTree, char *word) {

	for (int i = 0; i < strlen(word); i++) {

		if (aTree->head == NULL) {
			Node* pNew = new Node;
			pNew->data = word[i];
			ListHead *newList = CreateTree();
			pNew->next = newList->head;
			aTree->head = pNew;
		}
		else {
			char *pWord = &word[i];
			Node *nextList = aTree->head->next;
			AddWordRecursive(aTree->head->next, word[i]);
			if (AddWordRecursive(aTree->head->next, word[i])) {
				printf("word added\n");
				return 1;
			}
		}

	}
}

int main()
{
	ListHead *aList = CreateTree();
	AddWord(aList, "ACT");
	system("pause");
    return 0;
}

