#pragma once
#include<iostream>
#include<stack>
namespace dsa
{
	class BST
	{
		int data;
	public:
		BST* left, * right;
		BST();
		BST(int);
		BST* Insert(BST*, int);
		BST* InsertItr(BST*, int);
		void Inorder(BST*);
		void InorderItr(BST*);
		void Preorder(BST*);
		void PreorderItr(BST*);
		void Postorder(BST*);
		void PostorderItr(BST*);
		dsa::BST* DeleteNode(BST*, int);
	private:
		BST* successorOfNode(BST*);
	};
}