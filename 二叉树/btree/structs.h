#pragma once
#define link 0
#define thread 1
typedef struct BinaryNode {
	int elem;
	int depth;
	int id;//后面用在栈堆中
	int Ltag, Rtag;//这个是用来显示线索的
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;
}BinNode;
typedef struct BinT {
	BinNode* root;
	int tree_size;
	int tree_depth;
}BinTree,*BT;
typedef BinNode* position;