#include "binary_trees.h"

/**
 * bst_search - function that searches for a value in a Binary Search
 * Tree
 * @tree: the tree to go through
 * @value: the value to search
 * Return: a pointer to the node containing a value equals to value.
 * If tree is NULL or if nothing is found, return NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		found = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		found = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (found);
}
