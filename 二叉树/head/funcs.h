#pragma once
#include "structs.h"
//�������ĳ�ʼ��
BinNode* tree_init();

//�������ı���
void recursion1(BinNode* root);//�������
void recursion2(BinNode* root);//�������
void recursion3(BinNode* root);//�������

void recurMode(BinNode* root, int mode);

//�������Ĳ��� 
void tree_insert(BinNode* treeNode, BinNode* dataNode);

//������Ѱ�����ֵ
position findMax(BinNode* T);

//������Ѱ����Сֵ
position findMin(BinNode* T);

//���������ͷ�
void free_tree(BinNode* root);

//�������Ĳ���
position find(BinNode* T,const char* name);