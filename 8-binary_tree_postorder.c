#include "binary_trees.h"

/**
 * binary_tree_postorder - function that goes through a binary tree
 * using post-order traversal
 * @tree: the tree to go through
 * @func: the function to use
 * Return: If tree or func is NULL, return nothing
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}