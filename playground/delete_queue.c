#include "binary_trees.h"


/**
 * delete_queue - free all memory occupied by a queue, if any.
 * @queue: the queue to free.
 */
void delete_queue(queue_t *queue)
{
	queue_node_t *next_node, *curr_node;

	if (!queue)
	{
		return;
	}

	curr_node = queue->top;
	next_node = curr_node;
	while (curr_node)
	{
		next_node = curr_node->next;
		free(curr_node);

		curr_node = next_node;
	}
}

