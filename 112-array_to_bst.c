#include "binary_trees.h"

void insert_at_parent(bst_t **new_node, bst_t **field, bst_t *parent);

/**
 * array_to_bst - builds a Binary Search Tree from an array.
 * @array: pointer to first element of array to be converted.
 * @size: number of elements in the array.
 *
 * Return: pointer to the root of the BST.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	int i;
	bst_t *tree = NULL;

	if (!array)
	{
		return (NULL);
	}

	for (i = 0; i < (int)size; i++)
	{
		bst_insert(&tree, array[i]);
	}

	return (tree);
}
