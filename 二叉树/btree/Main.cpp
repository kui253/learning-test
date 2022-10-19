#include"structs.h"
#include"funcs.h"
#include<iostream>
using std::cout;
using std::endl;
int main() {

	BinNode* T1 = tree_init();

	int num = 0;
	tree_insert(T1, 10);
	tree_insert(T1, 9);
	tree_insert(T1, 8);
	tree_insert(T1, 12);
	tree_insert(T1, 6);
	tree_insert(T1, 4);
	tree_insert(T1, 3);
	tree_insert(T1, 11);
	tree_insert(T1, 2);
	tree_insert(T1, 1);
	tree_in_recursion(T1);
	cout << endl;
	tree_pre_recursion(T1);
	tree_depth(T1, num);
	cout << "\n" << "num: " << num << endl;
	return 0;
}