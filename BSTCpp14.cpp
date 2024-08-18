#include "BSTCpp14.h"

dsa::BST::BST():data(0), left(NULL), right(NULL)
{
}

dsa::BST::BST(int data):data(data), left(NULL), right(NULL)
{
}

dsa::BST* dsa::BST::Insert(BST* root, int data)
{
	if (!root)
	{
		return new BST(data);
	}

	if (data > root->data)
	{
		root->right = Insert(root->right, data);
	}
	else if (data < root->data)
	{
		root->left = Insert(root->left, data);
	}

	return root;
}

dsa::BST* dsa::BST::InsertItr(BST* root, int data)
{
	if (!root)
	{
		return new BST(data);
	}
	BST* p_run = root;
	BST* p_prev_run = NULL;
	while (p_run)
	{
		if (data > p_run->data)
		{
			p_prev_run = p_run;
			p_run = p_run->right;
		}
		else if (data < p_run->data)
		{
			p_prev_run = p_run;
			p_run = p_run->left;
		}
	}

	if (p_prev_run->data > data)
	{
		p_prev_run->left = new BST(data);
	}
	else
	{
		p_prev_run->right = new BST(data);
	}

	return root;
}

void dsa::BST::Inorder(BST* root)
{
	if (!root)
	{
		return;
	}

	Inorder(root->left);
	std::cout << root->data << " ";
	Inorder(root->right);
}

void dsa::BST::ReInorder(BST* root)
{
	if (!root)
	{
		return;
	}

	ReInorder(root->right);
	std::cout << root->data << " ";
	ReInorder(root->left);
}


void dsa::BST::InorderItr(BST* root)
{
	BST* p_run = root;
	std::stack<BST*> bstStack;
	while (p_run != NULL || !bstStack.empty())
	{
		if (p_run != NULL)
		{
			bstStack.push(p_run);
			p_run = p_run->left;
		}
		else
		{
			p_run = bstStack.top();
			bstStack.pop();
			std::cout << p_run->data << " ";
			p_run = p_run->right;
		}
	}
}

void dsa::BST::Preorder(BST* root)
{
	if (!root)
	{
		return;
	}
	std::cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void dsa::BST::PreorderItr(BST* root)
{
	if (!root)
	{
		return;
	}
	std::stack<BST*> bstStack;
	BST* bstNode = NULL;
	bstStack.push(root);
	while (!bstStack.empty())
	{
		bstNode = bstStack.top();
		bstStack.pop();
		std::cout << bstNode->data << " ";
		if (bstNode->right)
			bstStack.push(bstNode->right);
		if (bstNode->left)
			bstStack.push(bstNode->left);
	}
}

void dsa::BST::PostorderItr(BST* root)
{
	if (!root)
	{
		return;
	}
	std::stack<BST*> firstStack;
	std::stack<BST*> secondStack;
	firstStack.push(root);
	while (!firstStack.empty())
	{
		BST* bstNode = firstStack.top();
		firstStack.pop();
		secondStack.push(bstNode);
		if (bstNode->left)
			firstStack.push(bstNode->left);
		if (bstNode->right)
			firstStack.push(bstNode->right);
	}
	while (!secondStack.empty())
	{
		std::cout << secondStack.top()->data << " ";
		secondStack.pop();
	}
}

dsa::BST* dsa::BST::DeleteNode(BST* root, int data)
{
	if (!root)
	{
		return root;
	}

	if (data < root->data)
	{
		root->left = DeleteNode(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = DeleteNode(root->right, data);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			return NULL;
		}
		else if (root->left == NULL)
		{
			BST* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			BST* temp = root->left;
			free(root);
			return temp;
		}
		BST* temp = successorOfNode(root->right);
		root->data = temp->data;
		root->right = DeleteNode(root->right, data);
	}
	return root;
}

dsa::BST* dsa::BST::successorOfNode(BST*)
{
	BST* currentNode = NULL;
	while (currentNode && currentNode->left)
	{
		currentNode = currentNode->left;
	}
	return currentNode;
}

void dsa::BST::Postorder(BST* root)
{
	if (!root)
	{
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	std::cout << root->data << " ";
}


int main()
{
	dsa::BST bst(50);
	bst.Insert(&bst, 30);
	bst.Insert(&bst, 10);
	bst.Insert(&bst, 20);
	bst.ReInorder(&bst);
	bst.DeleteNode(&bst, 10);
}