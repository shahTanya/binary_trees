#include "binary_trees.h"


#ifndef BT_HEIGHT                                 #define BT_HEIGHT

void find_height(
		const binary_tree_t *tree, size_t *height,
		size_t curr_height, binary_tree_t *root_node);


/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to root node of tree whose height to measure.
 *
 * Return: the height of @tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *root_node = (binary_tree_t *)tree;
	static size_t height;
	size_t curr_height = 0, ret_height;

	if (tree == NULL)
	{
		return (0);
	}

	find_height(tree, &height, curr_height, root_node);

	ret_height = height;
	height = 0;

	return (ret_height);
}




/**
 * find_height - recursively evaluate the height of different paths.
 * @tree: the topmost node.
 * @height: address where height will be stored.
 * @curr_height: current height in the path.
 * @root_node: address of the original node.
 */
void find_height(
		const binary_tree_t *tree, size_t *height,
		size_t curr_height, binary_tree_t *root_node)
{
	size_t node_depth = 0;

	if (tree == NULL)
	{
		/* Base case; set height of longest path */
		*height = curr_height > *height ? curr_height : *height;
		curr_height = 0;  /* reset for the next path */
		return;
	}

	if (root_node != tree)
	{
		curr_height += 1;
		node_depth = curr_height;
	}

	find_height(tree->left, height, curr_height, root_node);

	curr_height = node_depth;

	find_height(tree->right, height, curr_height, root_node);
}

#endif /*BT_HEIGHT */
