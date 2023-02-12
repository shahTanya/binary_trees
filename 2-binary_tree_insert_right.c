#include "binary_trees.h"


/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right- child in.
 * @value: the value to store in the new node.
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (parent->right)
	{
		/* Parent has a right child already */
		new_node->right = parent->right; /* set it as right child of new node */
		(parent->right)->parent = new_node; /* change parent of prev right child */
		parent->right = new_node; /* new node now parent right child */
	}
	else
	{
		/* Parent has no right child */
		new_node->right = NULL;
		parent->right = new_node; /* new node now parent right child */
	}

	new_node->left = NULL;

	return (new_node);
}
