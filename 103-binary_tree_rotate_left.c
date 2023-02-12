#include "binary_trees.h"


/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: pointer to the root of the tree to rotate left.
 *
 * Return: pointer to the new root node of the tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_left, *old_root_parent;

	/* printf("1\n"); */
	if (tree == NULL || tree->right == NULL)
	{
		/* tree is null or no right child to rotate up */
		return (tree);
	}

	/* printf("2\n"); */
	new_root = tree->right;  /* will become new root */
	new_root_left = new_root->left;  /* will become new right child of old root */
	old_root_parent = tree->parent;  /* will be new parent of new root */

	/* printf("3\n"); */
	/* Rotate left */
	new_root->parent = old_root_parent;  /* will be NULL if tree was root */
	new_root->left = tree;
	tree->parent = new_root;
	/* printf("4\n"); */
	tree->right = new_root_left;
	/* printf("4a\n"); */
	if (tree->right)
	{
		tree->right->parent = tree;
	}
	/* printf("5\n"); */

	return (new_root);
}
