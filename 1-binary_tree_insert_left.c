#include "binary_trees.h"


/**
 * binary_tree_insert_left - inserts a node as the left-child of another node.
 * @parent: a pointer to the node to insert the left-child in.
 * @value: the value to store in the new node.
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		return (NULL);
	}

	new_node->parent = parent;
	new_node->n = value;

	if (parent->left)
	{
		/* Parent has a left child already */
		new_node->left = parent->left; /* set it as left child of new node */
		(parent->left)->parent = new_node; /* change parent of prev left child */
		parent->left = new_node; /* new node now parent left child */
	}
	else
	{
		/* Parent has no left child */
		new_node->left = NULL;
		parent->left = new_node; /* new node now parent left child */
	}

	new_node->right = NULL;

	return (new_node);
}
