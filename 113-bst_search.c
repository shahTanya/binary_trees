#include "binary_trees.h"


/**
 * bst_search - searches for a value in a Binary Search Tree.
 * @tree: address of tree to search in.
 * @value: key to search for.
 *
 * Return: pointer to the found node, or NULL on search failure.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *curr_node;

	if (!tree)
	{
		return (NULL);
	}

	curr_node = (binary_tree_t *)tree;
	while (curr_node)
	{
		if (value == curr_node->n)
		{
			break;
		}

		if (value > curr_node->n)
		{
			curr_node = curr_node->right;
		}
		else
		{
			curr_node = curr_node->left;
		}
	}

	return (curr_node);
}
