#include "binary_trees.h"

/**
 * check_sub_tree_Left - function that performs a left-rotation on a
 * binary tree
 * @node: the node in the tree to verify condition
 * @max: the value to compare
 * Return: a pointer to the new root node of the tree once rotated
 */

int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = check_sub_tree_Left(node->left, max);
		right = check_sub_tree_Left(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * check_sub_tree_Right - function that performs a right-rotation on
 * a binary tree
 * @node: the node in the tree to verify condition
 * @min: the value to compare
 * Return: a pointer to the new root node of the tree once rotated
 */

int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_sub_tree_Right(node->left, min);
		right = check_sub_tree_Right(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * binary_tree_is_bst - function that checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: the node that point to the tree to check
 * Return: If tree is NULL, return 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
