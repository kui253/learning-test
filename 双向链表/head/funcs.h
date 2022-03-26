#pragma once
#include"List.h"
using std::cout;
void for_each(list* L, void(*myprint)(void*));

void myprint(void* data);//to show the date in a list
bool mycompare(void* data1, void* data2);

list* init_list();

//list* creat_list();
void insert_node(P man, list* LList);

void delete_node(P man, list* LList,bool(*mycompare)(void*,void*));

node* find_node(list* LList,string tmpname);

//待开发的功能，读取数据
void clear_list(list* LList);