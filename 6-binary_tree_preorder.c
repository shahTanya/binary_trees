#include "binary_trees.h"


/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node. The value in the
 * node must be passed as a parameter to this function.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		/* Base case */
		return;
	}

	/* Pre-order traversal implementation */
	func(tree->n);  /* visit, or use, current node - parent first */
	binary_tree_preorder(tree->left, func);  /* recursively traverse left tree */
	binary_tree_preorder(tree->right, func); /* recursively traverse right tree */
}
