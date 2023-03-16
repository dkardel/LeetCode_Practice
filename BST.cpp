#include"BST.h"

bst* create_bst(void)
{
	bst* p_bst = (bst*)calloc(1, sizeof(bst));
	p_bst->p_root = NULL;
	p_bst->N = 0;
	return(p_bst);
}

int insert_bst(bst* p_bst, int data)
{
	node* p_new_node = get_node(data);
	node* p_run = NULL;

	int local_level = 0;
	if (p_bst->p_root == NULL)
	{
		p_bst->p_root = p_new_node;
		p_new_node->root = NULL;
		p_new_node->level += 1;
		p_bst->N += 1;
		return(1);
	}

	p_run = p_bst->p_root;
	local_level += 1;
	while (1)
	{
		local_level += 1;
		if (data <= p_run->data)
		{
			if (p_run->left == NULL)
			{
				p_run->left = p_new_node;
				p_new_node->data = data;
				p_new_node->level = local_level;
				break;
			}
			else
			{
				p_run = p_run->left;
				continue;
			}
		}
		else
		{
			if (p_run->right == NULL)
			{
				p_run->right = p_new_node;
				p_new_node->data = data;
				p_new_node->level = local_level;
				break;
			}
			else
			{
				p_run = p_run->right;
				continue;
			}
		}
	}
	return (1);
}

void inorder(bst* p_bst)
{
	printf("[start] <-> ");
	inorder_node(p_bst->p_root);
	printf("[end]\n ");
}

void inorder_node(node* p_node)
{
	if (p_node)
	{
		inorder_node(p_node->left);
		printf("%d <-> ", p_node->data);
		inorder_node(p_node->right);
	}
}

node* get_node(int data)
{
	node* p_node = (node*)calloc(1, sizeof(node));
	p_node->data = data;
	p_node->left = NULL;
	p_node->right = NULL;
	p_node->root = NULL;
	p_node->level = 0;
	p_node->height = 0;
	return (p_node);
}
