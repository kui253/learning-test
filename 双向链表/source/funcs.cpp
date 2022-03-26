#include"funcs.h"
using std::endl;
void for_each(list* L, void(*myprint)(void*))
{
	node* pcur = &L->node_header;
	pcur = pcur->next;
	if (L == NULL) {
		return;
	}
	for (int i = 0; i < L->the_size; i++) {
		myprint(pcur);
		pcur = pcur->next;
	}
}// run well

void myprint(void* data)
{
	node* n = (node*)data;
	cout << n->host.name << "  " << n->host.age <<"  " << n->host.height << endl;
}
bool mycompare(void* data1, void* data2) {
	P* man1 = (P*)data1;
	P* man2 = (P*)data2;
	if (man1->age == man2->age && (man1->height - man2->height) < 0.001 && man1->name == man2->name)
		return true;
	else
		return false;
}// run well

list* init_list()
{
	list* L = new(list);//头节点里不存储信息
	L->the_size = 0;
	L->node_header.host.age = 0;//感觉还是这里的host使用了指针的缘故内存开辟相当于就只有一个host* 内存冲突？
	L->node_header.host.height = 0;
	L->node_header.host.name = "c";
	L->node_header.next = NULL;
	L->node_header.ppre = NULL;

	return L;
}// run well

void insert_node(P man, list* LList)//现在仅仅支持尾插
{
	//头节点里不存储数据
	if (LList == NULL) {
		return;
	}
	node* pnew,*pnext, * pcur = &LList->node_header;
	pnext = pcur->next;
	pnew = new (node);
	for (int i = 0; i < LList->the_size; i++) {
		pcur = pnext;
		pnext = pnext->next;
	}
	pnew->host.name = man.name;
	pnew->host.age = man.age;
	pnew->host.height = man.height;
	pnew->next = pnext;//先给他赋完值
	pcur->next = pnew;
	pnew->ppre = pcur;
	LList->the_size++;
}//run well

void delete_node(P man, list* LList,bool(*mycompare)(void *,void *))
{
	node* ppre , * pnext, * pcur = &LList->node_header;
	pnext = pcur->next;
	ppre = pcur->ppre;
	while(pcur!= NULL){
		if (mycompare(&pcur->host, &man)) {
			ppre->next = pnext;
			if (pnext != NULL) {
				pnext->ppre = ppre;
			}
			delete pcur;
			pcur = NULL;
			LList->the_size--;
			return;
		}
		ppre = pcur;
		pcur = pnext;
		pnext = pnext->next;
	}
	cout << "sorry can't find this person :(" << endl;
}// run well

node* find_node(list* LList, string tmpname)
{
	if (LList == NULL) {
		return NULL;
	}
	node* pcur = &LList->node_header, * pnext = pcur->next;
	while (pnext != NULL)
	{
		if (pcur->host.name == tmpname) {
			return pcur;
			break;
		}
		pcur = pnext;
		pnext = pnext->next;
	}
	cout << "no such person" << endl;
	return NULL;
}//run well

void clear_list(list* LList)
{
	node* pcur = &LList->node_header, * pnext = pcur->next;
	while (pnext != NULL) {
		delete pcur;
		pcur = pnext;
		pnext = pnext->next;
	}
	delete pcur;
}// run well

//list* creat_list()
//{
//	list* LList;
//	node* pcur,*ppre,*pnext;
//	
//	return LList;
//}

