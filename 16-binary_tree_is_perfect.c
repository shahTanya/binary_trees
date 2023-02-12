#include "binary_trees.h"

void check_perfect(
		const binary_tree_t *tree, size_t node_depth, int *is_perfect);
size_t binary_tree_depth(const binary_tree_t *tree);


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: addresss of tree to check for perfection,
 * i.e. all leaf nodes are at the same depth, and have a sibling.
 *
 * Return: 1 if @tree is perfect; 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect = 1;
	size_t node_depth;
	binary_tree_t *tmp_tree;

	if (!tree)
	{
		return (0);
	}

	if (!tree->left && !tree->right)
	{
		return (0);
	}

	/* Get a leaf node's depth to initialize @node_depth */
	tmp_tree = (binary_tree_t *)tree;
	while (tmp_tree->left)
	{
		/* Iterate until a leaf node is encountered */
		tmp_tree = tmp_tree->left;
	}
	node_depth = binary_tree_depth(tmp_tree);

	check_perfect(tree, node_depth, &is_perfect);

	return (is_perfect);
}



/**
 * check_perfect - checks that a binary tree is
 * perfect using in-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @node_depth: stores the depth of a leaf node.
 * @is_perfect: address of flag indicating if a tree is perfect, or not.
 */
void check_perfect(
		const binary_tree_t *tree, size_t node_depth, int *is_perfect)
{
	if (tree == NULL)
	{
		/* Base case */
		return;
	}

	/* In-order traversal implementation */
	check_perfect(
			tree->left, node_depth, is_perfect);  /* recursively traverse left tree */

	if (!tree->left && !tree->right)
	{
		/* tree is a leaf node */
		/* See if depth is equal to other leaf depths */
		if (node_depth != binary_tree_depth(tree))
		{
			/* Different leaf depths; root tree not perfect */
			*is_perfect = 0;
			return;
		}

		if (tree->parent)
		{
			if (!tree->parent->left || !tree->parent->right)
			{
				/* Parent of leaf node not full; root tree not perfect */
				*is_perfect = 0;
				return;
			}
		}
	}

	check_perfect(
			tree->right, node_depth, is_perfect); /* recursively traverse right tree */
}


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
