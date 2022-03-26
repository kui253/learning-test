#include "funcs.h"
#include<iostream>
using namespace std;
BinNode* tree_init() {
	BinNode* root = new BinNode;
	root->person.age = 0;
	root->person.height = 0.0;
	strcpy_s(root->person.name , "0");
	root->lChild = NULL;
	root->rChild = NULL;
	return root;
}

void recursion1(BinNode* root)
{
	if (root == NULL) {
		return;
	}
	recursion1(root->lChild);
	cout << root->person.name << "  " << root->person.age << "  " << root->person.height << endl;
	recursion1(root->rChild);		
}

void recursion2(BinNode* root)
{
	if (root == NULL) {
		return;
	}
	cout << root->person.name << "  " << root->person.age << "  " << root->person.height << endl;
	recursion2(root->lChild);
	recursion2(root->rChild);
}

void recursion3(BinNode* root)
{
	if (root == NULL) {
		return;
	}
	recursion2(root->lChild);
	recursion2(root->rChild);
	cout << root->person.name << "  " << root->person.age << "  " << root->person.height << endl;
	
}

void recurMode(BinNode* root, int mode)
{
	switch (mode)
	{
	case 1: {
		recursion1(root);
		break;
	}
	case 2: {
		recursion2(root);
		break;
	}
	case 3: {
		recursion3(root);
		break;
	}
	default:
		break;
	}
		
}

void tree_insert(BinNode* treeNode, BinNode* dataNode)
{
	if (dataNode == NULL) {
		return;
	}
	if (treeNode == NULL) {
		treeNode = new BinNode;
		if (treeNode == NULL) {
			cout << "out of memory" << endl;
		}
		else {
			treeNode->person.age = dataNode->person.age;
			treeNode->person.height = dataNode->person.height;
			strcpy_s(treeNode->person.name, dataNode->person.name);
			treeNode->lChild = NULL;
			treeNode->rChild = NULL;
		}
		if (treeNode->person.age < dataNode->person.age) {
			tree_insert(treeNode->lChild, dataNode);
		}
		else {
			tree_insert(treeNode->rChild, dataNode);
		}
	}

}

position findMax(BinNode* T)
{
	if (T != NULL) {
		while (T->rChild !=NULL)
		{
			T = T->rChild;
		}
	}
	return T;
}

position findMin(BinNode* T)
{
	if (T == NULL) {
		return NULL;
	}
	else if(T->rChild ==NULL){
		return T;
	}
	else
		return findMin(T->lChild);
}

void free_tree(BinNode* root)
{
	if (root == NULL) {
		return;
	}
	free_tree(root->lChild);
	free_tree(root->rChild);
	free_tree(root);
}

position find(BinNode* T, const char* name)
{
	return T;
}

