#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value);

/**
 * bst_remove - removes a node from a Binary Search Tree.
 * @root: pointer to the root node of the tree where you will remove a node.
 * @value: key of node to remove in the tree.
 *
 * Return: pointer to the new root node
 * of the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node2remove, *n2r_parent, *n2r_right;
	bst_t *new_root = NULL, *replacement = NULL;
	int replace_root = 0;

	if (!root)
	{
		return (NULL);
	}

	if (!root->parent && !root->left && !root->right)
	{
		/* Root node with no child */
		if (root->n == value)
		{
			free(root);
		}
		return (new_root);
	}

	node2remove = bst_search(root, value);
	if (!node2remove)
	{
		return (new_root);  /* no node with specified value */
	}
	if (root == node2remove)
	{
		replace_root = 1;
	}

	/* root has at least one child and value exists in rooted tree */
	n2r_parent = node2remove->parent;
	if (!node2remove->left || !node2remove->right)
	{
		/* node to remove (n2r) has zero or only one child */
		if (node2remove->left)
		{
			/* The one child is on the left */
			if (replace_root)
			{
				new_root = node2remove->left;
			}
			else
			{
				new_root = root;
			}
			replacement = node2remove->left;
			replacement->parent = n2r_parent;
			if (n2r_parent)  /* non-root node to remove */
			{
				if (n2r_parent->left == node2remove)
				{
					/* Link at left of parent */
					n2r_parent->left = replacement;
				}
				else
				{
					/* Link at right */
					n2r_parent->right = replacement;
				}
			}
		}
		else if (node2remove->right)
		{
			/* The one child is on the right */
			if (replace_root)
			{
				new_root = node2remove->right;
			}
			else
			{
				new_root = root;
			}
			replacement = node2remove->right;
			replacement->parent = n2r_parent;
			if (n2r_parent)  /* non-root node to remove */
			{
				if (n2r_parent->left == node2remove)
				{
					/* Link at left of parent */
					n2r_parent->left = replacement;
				}
				else
				{
					/* Link at right */
					n2r_parent->right = replacement;
				}
			}
		}
		else
		{
			/* Node to remove has a parent but no child */
			new_root = root;  /* node2remove cannot be same as root; handled already */
			if (n2r_parent->left == node2remove)
			{
				n2r_parent->left = NULL;
			}
			else
			{
				/* Set right child of parent */
				n2r_parent->right = NULL;
			}
		}
	}
	else
	{
		/* n2r has two children */
		n2r_right = node2remove->right;  /* save right child of node to remove */
		replacement = n2r_right;
		while (replacement->left)
		{
			/* Iteratively look for leftmost leaf of right child of node to remove */
			replacement = replacement->left;
		}
		/* At this point, replacement==leftmost leaf, potentially n2r_right itself */
		if (replace_root)
		{
			new_root = replacement;
		}
		else
		{
			new_root = root;
		}

		if (n2r_parent)
		{
			/* node to remove is not root; link its parent to replacement */
			if (n2r_parent->left == node2remove)
			{
				/* Link at left of parent */
				n2r_parent->left = replacement;
			}
			else
			{
				/* Link at right */
				n2r_parent->right = replacement;
			}
		}

		if (node2remove->right == replacement)
		{
			/* Avoid loop where replacement->right is itself */
			node2remove->right = replacement->right;
		}
		else
		{
			/* Set parent of replacement->right already */
			replacement->right->parent = replacement->parent;
		}

		/* reset parent of children of node to remove */
		node2remove->left->parent = replacement;
		if (node2remove->right)
		{
			node2remove->right->parent = replacement;
		}

		/* Detach replacement from current position in tree and close gap */
		if (replacement->parent->left == replacement)
		{
			/* Link parent to grandchild at left */
			replacement->parent->left = replacement->right;
		}
		else if (replacement->parent->right == replacement)
		{
			/* Link at right */
			replacement->parent->right
= replacement->right;
		}

		/* Insert replacement in place of node to remove */
		/* Link replacement to parent */
		replacement->parent = n2r_parent;
		/* Link replacement to children */
		replacement->left = node2remove->left;
		replacement->right = node2remove->right;
	}

	free(node2remove);
	return (new_root);
}


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
