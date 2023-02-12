#include "binary_trees.h"


/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: pointer to the tree to count.
 *
 * Return: the number of nodes with at least one child.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t non_leaf;

	non_leaf = binary_tree_size(tree) - binary_tree_leaves(tree);

	return (non_leaf);
}



void find_leaves(const binary_tree_t *tree, size_t *size);


/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: the tree whose number of leaves to count.
 *
 * Return: the number of leaves in @tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	find_leaves(tree, &leaves);

	return (leaves);
}



/**
 * find_leaves - find the number of leaves of a tree.
 * @tree: the tree to find the leaves of.
 * @leaves: address of the leaves variable.
 */
void find_leaves(const binary_tree_t *tree, size_t *leaves)
{
	if (tree == NULL)
	{
		/* Base case */
		return;
	}

	/* In-order traversal implementation */
	find_leaves(tree->left, leaves);  /* recursively traverse left tree */
	if (!tree->left && !tree->right)
	{
		/* No child */
		*leaves = *leaves + 1;  /* visit, or use, current node - left first */
	}
	find_leaves(tree->right, leaves); /* recursively traverse right tree */
}



void find_size(const binary_tree_t *tree, size_t *size);


/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: the tree ro get the size of.
 *
 * Return: the size of @tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	find_size(tree, &size);

	return (size);
}



/**
 * find_size - find the size of a tree.
 * @tree: the tree to find the size of.
 * @size: address of the size variable.
 */
void find_size(const binary_tree_t *tree, size_t *size)
{
	if (tree == NULL)
	{
		/* Base case */
		return;
	}

	/* In-order traversal implementation */
	find_size(tree->left, size);  /* recursively traverse left tree */
	*size = *size + 1;  /* visit, or use, current node - left first */
	find_size(tree->right, size); /* recursively traverse right tree */
}
