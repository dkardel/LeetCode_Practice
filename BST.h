#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct bst_node
{
	int data;
	int level;
	int height;
	struct bst_node* left, * right, * root;
}node;

typedef struct bst
{
	node* p_root;
	int N;
}bst;

typedef struct lst_node
{
	node* p_bst_node;
	struct lst_node* prev, * next;
}lst_node;

typedef lst_node queue;

bst* create_bst(void);
int insert_bst(bst* p_bst, int data);
void inorder(bst* p_bst);
void assign_heights(bst* p_bst);
void show_levelwise(bst* p_bst);
void destroy_bst(bst** p_bst);

void destroy_bst_nodelevel(node* p_node);
void assign_heights_nodelevel(node* p_node);
void inorder_node(node* p_node);
node* get_node(int data);
int height(node* p_node);

lst_node* get_lst_node(node* p_bst_node);
void generic_insert(lst_node* beg, lst_node* mid, lst_node* end);
void generic_delete(lst_node* p_node);
queue* create_queue(void);
void enqueue(queue* p_queue, node* p_bst_node);
void dequeue(queue* p_queue, node** pp_bst_node);

int is_queue_empty(queue* p_queue);
void destroy_queue(queue** pp_queue);
