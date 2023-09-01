#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order
 * traversal
 * @tree: the tree to go through
 * @func: the function to use
 * Return: If tree or func is NULL, return nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
