#pragma once
#include "structs.h"
//�������ĳ�ʼ��
BinNode* tree_init();

//�������ı���
void tree_in_recursion(BinNode* root);//min traverse
void tree_pre_recursion(BinNode* root);//pre traverse
void tree_nex_recursion(BinNode* root);//lase traverse
//�������Ĳ���
void tree_insert(BinNode* T, int cour, int e);
void tree_depth(BinNode* T,int& num);
void tree_insert(BinNode* T, int num);
