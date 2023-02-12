#include "binary_trees.h"


/**
 * queue_empty - checks if a queue is empty, or not.
 * @queue: queue to check for emptiness.
 *
 * Return: 1 if empty, 0 otherwise.
 */
int queue_empty(queue_t *queue)
{
	if (!queue->top)
	{
		return (1);
	}

	return (0);
}
