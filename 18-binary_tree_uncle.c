#include "binary_trees.h"

binary_tree_t *binary_tree_sibling(binary_tree_t *node);


/**
 * binary_tree_uncle - finds the uncle (sibling of parent) of a node.
 * @node: pointer to the node to find the uncle of.
 *
 * Return: address of the uncle of @node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node == NULL)
	{
		return (NULL);
	}

	/* Get the uncle - the sibling of node's parent */
	uncle = binary_tree_sibling(node->parent);

	return (uncle);
}


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
