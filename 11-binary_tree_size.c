#include "binary_trees.h"

void find_size(const binary_tree_t *tree, size_t *size);


/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: the tree ro get the size of.
 *
 * Return: the size of @tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	find_size(tree, &size);

	return (size);
}



/**
 * find_size - find the size of a tree.
 * @tree: the tree to find the size of.
 * @size: address of the size variable.
 */
void find_size(const binary_tree_t *tree, size_t *size)
{
	if (tree == NULL)
	{
		/* Base case */
		return;
	}

	/* In-order traversal implementation */
	find_size(tree->left, size);  /* recursively traverse left tree */
	*size = *size + 1;  /* visit, or use, current node - left first */
	find_size(tree->right, size); /* recursively traverse right tree */
}
