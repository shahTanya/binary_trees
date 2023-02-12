#include "binary_trees.h"


void check_full(const binary_tree_t *tree, int *is_full);

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: address of the tree to check if full.
 *
 * Return: 1 if @tree is full,
 * i.e. all nodes have either 0 or 2 children; 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 1;

	if (!tree)
	{
		return (0);
	}

	check_full(tree, &is_full);

	return (is_full);
}



/**
 * check_full - checks that a binary tree is full using in-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @is_full: address of flag indicating if a tree is full, or not.
 */
void check_full(const binary_tree_t *tree, int *is_full)
{
	if (tree == NULL)
	{
		/* Base case */
		return;
	}

	/* In-order traversal implementation */
	check_full(tree->left, is_full);  /* recursively traverse left tree */

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
	{
		/* Tree is not full as there exists a node with only one child */
		*is_full = 0;
		return;
	}

	check_full(tree->right, is_full); /* recursively traverse right tree */
}
