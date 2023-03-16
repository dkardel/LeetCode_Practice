#include "LinkedList.h"

void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
	void* node = NULL;
	node = calloc(nr_of_elements, size_per_element);
	if (node == NULL)
	{
		fprintf(stderr, "Out Of virtual memory\n");
		exit(EXIT_FAILURE);
	}
	return node;
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
	p_mid->prev = p_beg;
	p_mid->next = p_end;
	p_beg->next = p_mid;
	p_end->prev = p_mid;
}

static void generic_delete(node_t* p_delete_node)
{
	p_delete_node->prev->next = p_delete_node->next;
	p_delete_node->next->prev = p_delete_node->prev;
	free(p_delete_node);
	p_delete_node = NULL;
}

static node_t* search_node(list_t* p_list, data_t search_data)
{
	node_t* p_run = p_list->next;
	for (p_run; p_run != p_list; p_run = p_run->next)
	{
		if (p_run->data == search_data)
		{
			return p_run;
		}
	}
	return (NULL);
}

static node_t* get_node(data_t new_data)
{
	node_t* new_node = (node_t*)xcalloc(1, sizeof(node_t));
	new_node->data = new_data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

list_t* create_list(void)
{
	list_t* p_head = NULL;
	p_head = get_node(-1);
	p_head->next = p_head;
	p_head->prev = p_head;
	return p_head;
}

status_t insert_start(list_t* p_list, data_t new_data)
{
	generic_insert(p_list, get_node(new_data), p_list->next);
	return SUCCESS;
}

status_t insert_end(list_t* p_list, data_t new_data)
{
	generic_insert(p_list->prev, get_node(new_data), p_list);
	return SUCCESS;
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
	node_t* node = search_node(p_list, e_data);
	if (node == NULL)
	{
		return LIST_DATA_NOT_FOUND;
	}
	generic_insert(node, get_node(new_data), node->next);
	return SUCCESS;
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
	node_t* node = search_node(p_list, e_data);
	if (node == NULL)
	{
		return LIST_DATA_NOT_FOUND;
	}
	generic_insert(node->prev, get_node(new_data), node);
	return SUCCESS;
}

status_t get_start(list_t* p_list, data_t* p_start_data)
{
	if (is_list_empty(p_list) == TRUE)
		return LIST_EMPTY;
	*p_start_data = p_list->next->data;
	return SUCCESS;
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
	if (is_list_empty(p_list) == TRUE)
		return LIST_EMPTY;
	*p_end_data = p_list->prev->data;
	return SUCCESS;
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
	if (is_list_empty(p_list) == TRUE)
		return LIST_EMPTY;
	*p_start_data = p_list->next->data;
	generic_delete(p_list->next);
	return SUCCESS;
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
	if (is_list_empty(p_list) == TRUE)
		return LIST_EMPTY;
	*p_end_data = p_list->prev->data;
	generic_delete(p_list->prev);
	return SUCCESS;
}

status_t remove_start(list_t* p_list)
{
	if (is_list_empty(p_list) == TRUE)
		return LIST_EMPTY;
	generic_delete(p_list->next);
	return SUCCESS;
}

status_t remove_end(list_t* p_list)
{
	if (is_list_empty(p_list) == TRUE)
		return LIST_EMPTY;
	generic_delete(p_list->prev);
	return SUCCESS;
}

status_t remove_data(list_t* p_list, data_t e_data)
{
	node_t* node = search_node(p_list, e_data);
	if (node == NULL)
	{
		return LIST_DATA_NOT_FOUND;
	}
	generic_delete(node);
	return SUCCESS;
}

status_t is_list_empty(list_t* p_list)
{
	if (p_list->next == p_list && p_list == p_list->prev)
		return TRUE;
	else
		return FALSE;
}

len_t get_length(list_t* p_list)
{
	node_t* p_run = NULL;
	len_t length = 0;
	for (p_run = p_list->next; p_run != p_list; p_run = p_run->next)
	{
		length++;
	}
	return length;
}

void show_list(list_t* p_list)
{
	fprintf(stdout, "[Start] <-> ");
	node_t* p_run = NULL;
	for (p_run = p_list->next; p_run != p_list; p_run = p_run->next)
	{
		fprintf(stdout, "%d <-> ", p_run->data);
	}
	fprintf(stdout, " [End] \n");
}

void destroy_list(list_t** pp_list)
{
	list_t* p_list = *pp_list;
	node_t* p_run  = p_list->next;
	node_t* p_run_next = NULL;
	while (p_run != p_list)
	{
		p_run_next = p_run->next;
		generic_delete(p_run);
		p_run = p_run_next;
	}
	free(p_list);
	p_list = NULL;
	*pp_list = NULL;
}

