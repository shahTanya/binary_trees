#include "binary_trees.h"


/**
 * dequeue - remove an item from a queue.
 * @queue: the queue to remove an item from.
 *
 * Return: the removed queue item. It is the responsibility of the
 * caller to free the item when no longer in use.
 */
queue_node_t *dequeue(queue_t *queue)
{
	queue_node_t *rear;

	if (queue->rear == NULL)
	{
		return (NULL);
	}

	rear = queue->rear;

	if (rear->prev)
	{
		/* rear's previous not NULL */
		rear->prev->next = NULL;  /* rear's previous now new rear...unofficially */
	}

	if (queue->top == rear)
	{
		queue->top = NULL;
	}
	queue->rear = rear->prev;  /* now official */

	return (rear);
}
