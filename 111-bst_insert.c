#include "binary_trees.h"

#ifndef BST_INSERT
#define BST_INSERT

void insert_at_parent(bst_t **new_node, bst_t **field, bst_t *parent);

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: pointer to variable storing the address of a BST.
 * @value: data to store in new BST node.
 *
 * Return: a pointer to new node.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *tree_root, *curr_node, *parent;

	if (!tree)
	{
		return (NULL);
	}

	tree_root = *tree;  /* get root of tree pointed to by var whose add is tree */
	new_node = malloc(sizeof(bst_t));
	if (!new_node)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (tree_root == NULL)
	{
		/* Empty tree; make new node root */
		new_node->parent = NULL;
		*tree = new_node;  /* affect the outside variable storing pointer to tree */
		return (new_node);
	}

	curr_node = tree_root;
	parent = curr_node->parent;  /* will be NULL for root node */
	while (curr_node)
	{
		if (value > curr_node->n)
		{
			/* Go right */
			parent = curr_node;
			curr_node = curr_node->right;
			if (curr_node == NULL)
			{
				/* insert at parent right */
				insert_at_parent(&new_node, &parent->right, parent);
				return (new_node);
			}

			continue;  /* to next iteration */
		}
		else if (value < curr_node->n)
		{
			parent = curr_node;
			curr_node = curr_node->left;
			if (curr_node == NULL)
			{
				/* insert at parent left */
				insert_at_parent(&new_node, &parent->left, parent);
				return (new_node);
			}

			continue;
		}
		else
		{
			/* Value already exists */
			free(new_node);
			break;  /* to return NULL */
		}
	}

	return (NULL);
}



/**
 * insert_at_parent - assign a new child node to a parent.
 * @new_node: node to assign.
 * @field: the field to assign @new_node to.
 * @parent: node with the field @field.
 */
void insert_at_parent(bst_t **new_node, bst_t **field, bst_t *parent)
{
	*field = *new_node;
	(*new_node)->parent = parent;
}

#endif
