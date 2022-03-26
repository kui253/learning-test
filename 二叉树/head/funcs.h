#pragma once
#include "structs.h"
//二叉树的初始化
BinNode* tree_init();

//二叉树的遍历
void recursion1(BinNode* root);//先序遍历
void recursion2(BinNode* root);//中序遍历
void recursion3(BinNode* root);//后序遍历

void recurMode(BinNode* root, int mode);

//二叉树的插入 
void tree_insert(BinNode* treeNode, BinNode* dataNode);

//二叉树寻找最大值
position findMax(BinNode* T);

//二叉树寻找最小值
position findMin(BinNode* T);

//二叉树的释放
void free_tree(BinNode* root);

//二叉树的查找
position find(BinNode* T,const char* name);