#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a
 * binary tree
 * @tree: the tree to go through
 * Return: height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((l > r) ? l : r);
		}
}

/**
 * bal_avl - function that compare each subtree if its AVL
 * @tree: the node pointing to the tree
 * @high: the node pointing to the higher node selected
 * @lower: the node pointing to the lower node selected
 * Return: 1 if tree is AVL, 0 if not.
 */

int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t height_l, height_r, balancer;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		height_l = binary_tree_height(tree->left);
		height_r = binary_tree_height(tree->right);
		balancer = height_l > height_r ? height_l - height_r : height_r - height_l;
		if (balancer > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - function that checks if a binary tree is a
 * valid AVL Tree
 * @tree: the node pointing to the tree
 * Return: 1 if tree is a valid AVL Tree or otherwise 0. If tree is
 * NULL, return 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
