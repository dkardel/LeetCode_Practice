#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node node_t;
typedef int data_t;
typedef int status_t;
typedef node_t list_t;

struct node
{
	data_t data;
	node_t* next;
};

list_t* CreateList();
node_t* GetNewNode(data_t data);
status_t InsertAtStart(list_t* p_list, data_t data);
status_t InsertAtEnd(list_t* p_list, data_t data);
status_t InsertAtAfter(list_t* p_list, data_t data, data_t s_data);

status_t DeleteAtStart(list_t* p_list);
status_t DeleteAtEnd(list_t* p_list);
status_t DeleteNode(list_t* p_list, data_t data);
node_t* GetPrevNode(list_t* p_list, data_t node);
void GenericInsert(node_t* p_beg, node_t* p_new, node_t* p_end);
void GenericNextDelete(node_t* p_node);
void DisplayList(list_t* p_list);

node_t* GetLastNode(list_t* p_list);
#endif
