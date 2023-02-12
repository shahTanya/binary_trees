#include "binary_trees.h"


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: address of the lowest common ancestor of @first and @second.
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (!first || !second)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	/* Bring the deeper node up to the same level as the shallower one, as ... */
	/* ...there can be no common ancestor in-between */
	if (first_depth > second_depth)
	{
		/* Bring first node up the level of the second */
		while (first_depth != second_depth && first != NULL)
		{
			first = first->parent;  /* first node moved up */
			first_depth -= 1;  /* depth reduced */
		}
	}
	else if (second_depth > first_depth)
	{
		/* Bring second node up; generally ignore case where depths are same */
		while (second_depth != first_depth && second != NULL)
		{
			second = second->parent;  /* second node moved up */
			second_depth -= 1;  /* depth reduced */
		}
	}
	/* At this point, both nodes are at the same depth */
	while ((int)first_depth >= 0)  /* up until the root */
	{
		if (first == second)
			return ((binary_tree_t *)first);  /* common ancestor found; second too */
		/* Move/update both nodes and their depths together */
		first = first->parent;
		first_depth -= 1;
		second_depth -= 1;
		second = second->parent;
	}
	return (NULL);  /* nodes likely on different trees, perhaps in a forest */
}




/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth of.
 *
 * Return: the depth of @tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *tmp_tree;

	if (!tree)
	{
		return (0);
	}

	tmp_tree = (binary_tree_t *)tree;
	while (tmp_tree->parent)
	{
		/* No entrance for the root node */
		depth += 1;
		tmp_tree = tmp_tree->parent;
	}

	return (depth);
}

