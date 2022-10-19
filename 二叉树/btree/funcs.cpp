#include "funcs.h"
#include<iostream>
using std::cout;
using std::endl;
BinNode* tree_init() {
	BinNode* root = new BinNode;
	root->elem = 5;
	root->depth = 1;
	root->Ltag = link;
	root->Rtag = link;
	root->lChild = NULL;
	root->rChild = NULL;
	return root;
}

void tree_in_recursion(BinNode* root)
{
	if (!root) { return; }
	tree_in_recursion(root->lChild);
	cout << root->elem <<" ";
	tree_in_recursion(root->rChild);

}

void tree_pre_recursion(BinNode* root)
{
	if (!root)return;
	cout << root->elem << " ";
	tree_pre_recursion(root->lChild);
	tree_pre_recursion(root->rChild);

}

void tree_nex_recursion(BinNode* root)
{
	if (!root)return;
	tree_nex_recursion(root->lChild);
	tree_nex_recursion(root->rChild);
	cout << root->elem << " ";
}

void tree_insert(BinNode* T, int cour, int e)
{
	if (cour == 0) {
		if (!T->lChild) {
			BinNode* Bnew = new BinNode;
			Bnew->elem = e;
			T->lChild = Bnew;
			Bnew->rChild = NULL;
			Bnew->lChild = NULL;
			Bnew->Rtag = link;
			Bnew->Ltag = link;
			Bnew->depth = T->depth;
			if (!T->rChild)Bnew->depth++;
			return;
		}
		tree_insert(T->lChild, 0, e);

	}
	else if (cour == 1) {
		if (!T->rChild) {
			BinNode* Bnew = new BinNode;
			Bnew->elem = e;
			T->rChild = Bnew;
			Bnew->rChild = NULL;
			Bnew->lChild = NULL;
			Bnew->Rtag = link;
			Bnew->Ltag = link;
			Bnew->depth = T->depth;
			if (!T->lChild)Bnew->depth++;
			return;
		}
		tree_insert(T->rChild, 1, e);
	}
	else {
		cout << "error,this cour is not valid." << endl;
		return;
	}
}

void tree_depth(BinNode* T,int &num)
{
	if (!T)return;
	tree_depth(T->lChild,num);
	num = (num > T->depth) ? num : T->depth;
	tree_depth(T->rChild,num);
	
}
void tree_insert(BinNode* T, int num)
{

	if (num < T->elem) {
		if (!T->lChild) {
			BinNode* Bnew = new BinNode;
			Bnew->elem = num;
			T->lChild = Bnew;
			Bnew->rChild = NULL;
			Bnew->lChild = NULL;
			Bnew->Rtag = link;
			Bnew->Ltag = link;
			Bnew->depth = T->depth;
			if (!T->rChild)Bnew->depth++;
			return;
		}
		tree_insert(T->lChild, num);
	}
	else {
		if (!T->rChild) {
			BinNode* Bnew = new BinNode;
			Bnew->elem = num;
			T->rChild = Bnew;
			Bnew->rChild = NULL;
			Bnew->lChild = NULL;
			Bnew->Rtag = link;
			Bnew->Ltag = link;
			Bnew->depth = T->depth;
			if (!T->lChild)Bnew->depth++;
			return;
		}
		tree_insert(T->rChild, num);
	}
}

