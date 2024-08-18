#pragma once
#include "SList.h"

template <typename T>
class Node
{
	template <typename T>
	friend class SList;
private:
	T data;
	Node* next;
public:
	Node(T data);
};

template <typename T>
class SList
{
private:
	Node<T>* p_head_node;
	void generic_insert(Node<T>* p_beg, Node<T>* p_mid, Node<T>* p_end);
	void generic_delete(Node<T>* node);
	Node<T>* search_node(T data);
public:
	SList(T a = (T)NULL);
	void insert_at_start(T data);
	void insert_at_end(T data);
	void insert_after(T data);
	void insert_before(T data);
};

