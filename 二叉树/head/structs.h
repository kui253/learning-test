#pragma once
typedef struct People{
	int age;//�����������
	double height;
	char name[10];
}p;
typedef struct BinaryNode {
	p person;
	BinNode* lChild;
	BinNode* rChild;
}BinNode;

typedef BinNode* position;