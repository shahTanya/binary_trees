#include "binary_trees.h"


/**
 * enqueue - adds a new node to a queue.
 * @queue: a struct storing the top and rear of the queue to enqueue.
 * @node: the data to store in the new node.
 */
void enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node;

	new_node = malloc(sizeof(queue_node_t));
	if (!new_node)
	{
		perror("enqueue-malloc");
		exit(EXIT_FAILURE);
	}

	new_node->node = node;
	new_node->prev = NULL;
	new_node->next = queue->top;

	if (queue->top)
	{
		queue->top->prev = new_node;
	}

	queue->top = new_node;

	if (!queue->rear)
	{
		/* Only set for the first node in queue; subsequently set by dequeue */
		queue->rear = new_node;
	}
}
