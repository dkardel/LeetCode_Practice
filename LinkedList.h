#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define TRUE 1
#define FALSE 0

#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef int data_t;
typedef int status_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t list_t;

struct node
{
	data_t data;
	struct node* prev;
	struct node* next;
};

list_t* create_list(void);
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data);

status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);

status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t e_data);

status_t is_list_empty(list_t* p_list);
len_t get_length(list_t* p_list);
void show_list(list_t* p_list);
void destroy_list(list_t** pp_list);

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node);
static node_t* search_node(list_t* p_list, data_t search_data);
static node_t* get_node(data_t new_data);

void* xcalloc(size_t nr_of_elements, size_t size_per_element);

#endif /* _LIST_H */
