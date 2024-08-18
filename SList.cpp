#include "SList.h"

template <typename T>
Node<T>::Node(T data) :data(data), next(0) {};


template <typename T>
void SList<T>::generic_insert(Node<T>* p_beg, Node<T>* p_mid, Node<T>* p_end)
{
	 p_beg->next = p_mid;
	 p_mid->next = p_end;
}

template <typename T>
void SList<T>::generic_delete(Node<T>* prevNode)
{
	 Node<T>* temp = prevNode->next;
	 prevNode->next = prevNode->next->next;
	 delete temp;
}

template <typename T>
Node<T>* SList<T>::search_node(T data)
{
	 Node<T>* p_run = p_head_node->next;
	 while (p_run != nullptr)
	 {
		 if (p_run->data == data)
			 return p_run;
	 }
	return nullptr;
}

 template <typename T>
 SList<T>::SList(T a):p_head_node(new Node<T>(a))
 {
 }

template <typename T>
void SList<T>::insert_at_start(T data)
{
	generic_insert(p_head_node, new Node<T>(data), p_head_node->next);
}

template <typename T>
void SList<T>::insert_at_end(T data)
{
}

template <typename T>
void SList<T>::insert_after(T data)
{
}

template <typename T>
void SList<T>::insert_before(T data)
{
}