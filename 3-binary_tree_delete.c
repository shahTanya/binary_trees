#include "binary_trees.h"


/**
 * binary_tree_delete - deletes an entire binary tree.
 * @tree: the root node of the tree.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (!tree)
	{
		/* Base case */
		return;
	}

	/* Save left and right sub-trees of current node */
	left = tree->left;
	right = tree->right;

	/* Delete the current node */
	free(tree);

	/* Recursively free left and right sub-trees, starting with left */
	binary_tree_delete(left);
	binary_tree_delete(right);
}
