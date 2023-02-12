#include "binary_trees.h"

#ifndef BT_SIBLING
#define BT_SIBLING

/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node: address of the node whose sibling to find.
 *
 * Return: address of the sibling of @node, or NULL if none.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	if (!node || !node->parent)
	{
		return (NULL);
	}

	if (node->parent->left == node)
	{
		/* Sibling is on the right */
		sibling = node->parent->right;
	}
	else
	{
		/* Sibling is on the left */
		sibling = node->parent->left;
	}

	return (sibling);
}

#endif /* BT_SIBLING */
