#pragma once
#include "structs.h"
//二叉树的初始化
BinNode* tree_init();

//二叉树的遍历
void tree_in_recursion(BinNode* root);//min traverse
void tree_pre_recursion(BinNode* root);//pre traverse
void tree_nex_recursion(BinNode* root);//lase traverse
//二叉树的插入
void tree_insert(BinNode* T, int cour, int e);
void tree_depth(BinNode* T,int& num);
void tree_insert(BinNode* T, int num);
