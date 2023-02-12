#include "binary_trees.h"

void find_leaves2(const binary_tree_t *tree, int *is_bst);


/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to tree to check.
 *
 * Algorithm: this algorithm uses in-order traversal to visit each node in
 * the tree. If the current node (CN) is a leaf node (LN), the algorithm
 * follows the path from the CN to the root node (RN), checking, along the way,
 * if a node's value satisfies the BST criteria when compared with its
 * parent's value; this check also simultaneously occurs between this
 * parent and the first node in
 * the path (the LN). Once the criteria fails, recursion returns.
 *
 * Return: an int indicating if @tree is a BST.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int is_bst = 1;

	if (!tree)
	{
		return (0);
	}

	if (!tree->left && !tree->right)
	{
		/* Only one node in tree - root node */
		return (1);
	}

	find_leaves2(tree, &is_bst);

	return (is_bst);
}



/**
 * find_leaves2 - find the leaves of a tree.
 * @tree: the tree to find the leaves of.
 * @is_bst: address of the is_bst variable,
 * indicating if a tree is a binary search tree or not.
 */
void find_leaves2(const binary_tree_t *tree, int *is_bst)
{
	binary_tree_t *curr_node, *parent, *curr_node_bkup, *tree_cpy;

	if (tree == NULL)
	{
		/* Base case */
		return;
	}

	/* In-order traversal implementation */
	find_leaves2(tree->left, is_bst);  /* recursively traverse left tree */
	if (!tree->left && !tree->right)
	{
		/* Leaf found */
		tree_cpy = (binary_tree_t *)tree;  /* store the address of original node */
		curr_node = (binary_tree_t *)tree;
		curr_node_bkup = curr_node;  /* for when curr_node updates to root */
		parent = curr_node->parent;
		while (curr_node)
		{
			if (parent == NULL)
			{
				/* curr_node is root node */
				if (curr_node_bkup == curr_node->left && tree_cpy->n >= curr_node->n)
				{
					*is_bst = 0;
					return;
				}
				if (curr_node_bkup == curr_node->right && tree_cpy->n <= curr_node->n)
				{
					*is_bst = 0;
					return;
				}
				break;
			}

			if (curr_node == parent->left)
			{
				/* curr_node is left child of parent */
				if (curr_node->n >= parent->n || tree_cpy->n >= parent->n)
				{
					*is_bst = 0;
				}
			}
			else
			{
				/* curr_node is right child of parent */
				if (curr_node->n <= parent->n || tree_cpy->n <= parent->n)
				{
					*is_bst = 0;
				}
			}
			if (!(*is_bst))
			{
				return;
			}

			curr_node_bkup = curr_node;
			curr_node = parent;
			parent = curr_node->parent;
		}
	}

	find_leaves2(tree->right, is_bst); /* recursively traverse right tree */
}
