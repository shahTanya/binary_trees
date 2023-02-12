#include "binary_trees.h"


/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root of the tree to rotate right.
 *
 * Return: pointer to the new root node of the tree.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_right, *old_root_parent;

	/* printf("1\n"); */
	if (tree == NULL || tree->left == NULL)
	{
		/* tree is null or no left child to rotate up */
		return (tree);
	}

	/* printf("2\n"); */
	new_root = tree->left;  /* will become new root */
	new_root_right = new_root->right;  /*will become new right child of old root*/
	old_root_parent = tree->parent;  /* will be new parent of new root */

	/* printf("3\n"); */
	/* Rotate right */
	new_root->parent = old_root_parent;  /* will be NULL if tree was root */
	new_root->right = tree;
	tree->parent = new_root;
	/* printf("4\n"); */
	tree->left = new_root_right;
	/* printf("4a\n"); */
	if (tree->left)
	{
		tree->left->parent = tree;
	}
	/* printf("5\n"); */

	return (new_root);
}
