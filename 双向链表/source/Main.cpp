#include"List.h"
#include"funcs.h"
using namespace std;

int main() {
	P men[4] = { {15,167.6,"John"},{16,187.5,"Ann"},{19,176.5,"Jane"},{17,177.5,"Max"}};
	list* LinkList = init_list();
	node* node1;
	insert_node(men[0], LinkList);
	insert_node(men[1], LinkList);
	insert_node(men[2], LinkList);
	insert_node(men[3], LinkList);
	for_each(LinkList, myprint);
	clear_list(LinkList);


	return 0;
}