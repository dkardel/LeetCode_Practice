#include "SLinkedList.h"

list_t* CreateList()
{
	return GetNewNode(-1);
}

node_t* GetNewNode(data_t data)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

status_t InsertAtStart(list_t* p_list, data_t data)
{
	GenericInsert(p_list, GetNewNode(data), p_list->next);
	return status_t(1);
}

status_t InsertAtEnd(list_t* p_list, data_t data)
{
	node_t* p_prev_node = GetPrevNode(p_list, data);
	if (!p_prev_node)
		return -1;
	GenericInsert(p_prev_node, GetNewNode(data), p_prev_node->next);
	return status_t(1);
}

status_t InsertAtAfter(list_t* p_list, data_t data, data_t s_data)
{
	node_t* p_prev_node = GetPrevNode(p_list, s_data);
	if (!p_prev_node)
		return -1;
	GenericInsert(p_prev_node->next, GetNewNode(data), p_prev_node->next->next);
	return status_t(1);
}

status_t DeleteAtStart(list_t* p_list)
{
	GenericNextDelete(p_list);
	return status_t(1);
}

status_t DeleteAtEnd(list_t* p_list)
{
	node_t* lastNode = GetLastNode(p_list);
	GenericNextDelete(lastNode);
	return status_t(1);
}

status_t DeleteNode(list_t* p_list, data_t data)
{
	node_t* p_prev_node = GetPrevNode(p_list, data);
	GenericNextDelete(p_prev_node);
	return status_t(1);
}

node_t* GetPrevNode(list_t* p_list, data_t node)
{
	node_t* p_run = p_list->next;
	if (p_run->data == node)
	{
		return p_list;
	}
	node_t* p_prev_run = p_list;
	while (p_run != NULL)
	{
		if (p_run->data == node)
		{
			return p_prev_run;
		}
		p_prev_run = p_run;
		p_run = p_run->next;
	}
	return p_prev_run;
}

node_t* GetLastNode(list_t* p_list)
{
	node_t* p_run = p_list->next;
	node_t* p_prev_run = p_list;
	while (p_run->next != NULL)
	{
		p_prev_run = p_run;
		p_run = p_run->next;
	}
	return p_prev_run;
}

void GenericInsert(node_t* p_beg, node_t* p_new, node_t* p_end)
{
 	p_beg->next = p_new;
	p_new->next = p_end;
}

void GenericNextDelete(node_t* p_prev_node)
{
	node_t* p_temp = p_prev_node->next;
	p_prev_node->next = p_temp->next;
	free(p_temp);
}

void DisplayList(list_t* p_list)
{
	node_t* p_run = p_list->next;
	printf("\nStart <-> ");
	while (p_run != NULL)
	{
		printf(" %d <-> ", p_run->data);
		p_run = p_run->next;
	}
	printf("End");
}

bool SearchRec(node_t* p_list, data_t data)
{
	if (!p_list)
		return false;
	if (p_list->data == data)
		return true;
	return SearchRec(p_list->next, data);
}

void ReverseLinkedList(node_t* p_list)
{
	node_t* p_run = p_list->next;
	node_t* next = NULL;
	node_t* prev = NULL;
	while (p_run != NULL)
	{
		next = p_run->next;
		p_run->next = prev;
		prev = p_run;
		p_run = next;
	}
	p_list->next = prev;
}

void MergeLinkedList(node_t* first, node_t* second, node_t* out)
{
	node_t* end =(node_t*) malloc(sizeof(node_t));
	end->data = -1;
	end->next = NULL;
	node_t* p3 = end;
	while (first != NULL && second != NULL)
	{
		if (first->data < second->data)
		{
			end->next = first;
			first = first->next;
		}
		else
		{
			end->next = second;
			second = second->next;
		}
		end = end->next;
	}
	while (first != NULL)
	{
		end->next = first;
		end = end->next;
		first = first->next;
	}
	while (second != NULL)
	{
		end->next = second;
		end = end->next;
		second = second->next;
	}
	end->next = NULL;
	out = p3->next;
}

node_t* FindMidOfList(node_t* p_list)
{
	return NULL;
}

unsigned int swapbytes(unsigned int number)
{
	printf("%x\n", (number & 0xff00ff00) >> 8 | (number & 0x00ff00ff) << 8);
	printf("%x\n", (number & 0x00ff00ff) << 8);
	return 0;
}

int main()
{
	int a = 4, b = 3, c = 0;
	c = a + b;

	int* p = &a;
	int* x = &b;
	int* y = p + (int)x;

	swapbytes(0x11223344);

	list_t* slist = CreateList();
	list_t* tlist = CreateList();
	list_t* xlist = CreateList();
	InsertAtStart(slist, 10);
	InsertAtEnd(slist, 20);
	InsertAtEnd(slist, 30);
	InsertAtEnd(slist, 40);
	InsertAtAfter(slist, 50, 40);

	InsertAtStart(tlist, 10);
	InsertAtEnd(tlist, 20);
	InsertAtEnd(tlist, 30);
	InsertAtEnd(tlist, 40);
	InsertAtAfter(tlist, 50, 40);
	MergeLinkedList(slist->next, tlist->next, xlist->next);

	DisplayList(slist);
	ReverseLinkedList(slist);
	DisplayList(slist);
	DeleteNode(slist, 10);
	DisplayList(slist);

	if (SearchRec(slist, 100))
		printf("\nelement found");
	DeleteAtStart(slist);
	DisplayList(slist);

	DeleteAtEnd(slist);
	DisplayList(slist);


	DeleteAtStart(slist);
	DisplayList(slist);

	DeleteAtEnd(slist);
	DisplayList(slist);

	free(slist);
	slist = NULL;
	return 0;
}