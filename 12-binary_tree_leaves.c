#include "binary_trees.h"

void find_leaves(const binary_tree_t *tree, size_t *size);


/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: the tree whose number of leaves to count.
 *
 * Return: the number of leaves in @tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	find_leaves(tree, &leaves);

	return (leaves);
}



/**
 * find_leaves - find the number of leaves of a tree.
 * @tree: the tree to find the leaves of.
 * @leaves: address of the leaves variable.
 */
void find_leaves(const binary_tree_t *tree, size_t *leaves)
{
	if (tree == NULL)
	{
		/* Base case */
		return;
	}

	/* In-order traversal implementation */
	find_leaves(tree->left, leaves);  /* recursively traverse left tree */
	if (!tree->left && !tree->right)
	{
		/* No child */
		*leaves = *leaves + 1;  /* visit, or use, current node - left first */
	}
	find_leaves(tree->right, leaves); /* recursively traverse right tree */
}
