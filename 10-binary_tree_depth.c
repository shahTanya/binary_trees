#include "binary_trees.h"

#ifndef BT_DEPTH
#define BT_DEPTH

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth of.
 *
 * Return: the depth of @tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *tmp_tree;

	if (!tree)
	{
		return (0);
	}

	tmp_tree = (binary_tree_t *)tree;
	while (tmp_tree->parent)
	{
		/* No entrance for the root node */
		depth += 1;
		tmp_tree = tmp_tree->parent;
	}

	return (depth);
}

#endif /* BT_DEPTH */
