#pragma once
#include<iostream>
#include<string>
using std::string;
struct person {
	int age;
	double height;
	string name;

};

typedef struct person P;
typedef struct Node {
	struct Node* ppre;
	struct Node* next;
	struct person host;
}node;
typedef struct List {
	struct Node node_header;
	int the_size;
}list;