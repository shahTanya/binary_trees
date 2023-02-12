#include "binary_trees.h"

void levelorder_traversal2(queue_t *queue1, queue_t *queue2, int *is_complete);

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: address of tree to check for completeness.
 *
 * Return: 1 if @tree is complete; 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t queue1 = {NULL, NULL}, queue2 = {NULL, NULL};
	int is_complete = 1;

	if (!tree)
	{
		return (0);
	}

	enqueue(&queue1, (binary_tree_t *)tree);  /* enqueue the root node */
	/* func(tree->n); */

	levelorder_traversal2(&queue1, &queue2, &is_complete);

	return (is_complete);
}


/**
 * levelorder_traversal2 - traverses a binary tree, one level at a time.
 * @queue1: address of a queue containing
 * nodes whose children belong to present level.
 * @queue2: pointer to queue containing parents of next-level nodes.
 * @is_complete: int flag indicating if a binary tree is complete.
 */
void levelorder_traversal2(queue_t *queue1, queue_t *queue2, int *is_complete)
{
	queue_node_t *q_node;
	binary_tree_t *bt_node;
	int null_present = 0;

	q_node = dequeue(queue1);
	while (q_node)  /* even if is_complete==0, to enable freeing of queue1 */
	{
		bt_node = q_node->node;  /* fetch the binary tree data in the queue_node_t */
		/* Enqueue both children */
		if (bt_node->left && *is_complete)
		{
			/* There's a left child */
			if (null_present)
			{
				*is_complete = 0;  /* not supposed to have a child at right of NULL */
			}
			else
			{
			enqueue(queue2, bt_node->left);  /* enqueue in queue2 for next level */
			}
			/* func(bt_node->left->n); */
		}
		else
		{
			null_present = 1;
		}

		if (bt_node->right && *is_complete)
		{
			if (null_present)
			{
				*is_complete = 0;  /* not supposed to have a child at right of NULL */
			}
			else
			{
				enqueue(queue2, bt_node->right);
			}
			/* func(bt_node->right->n); */
		}
		else
		{
			null_present = 1;
		}

		free(q_node);  /* free the dequeued node */

		/* Next sibling in queue1; if none, NULL will be returned */
		q_node = dequeue(queue1);
	}

	if (queue_empty(queue2))
	{
		/* End of traversal; queue1 nodes were leaf nodes */
		return;
	}

	if (!(*is_complete))
	{
		delete_queue(queue2);  /* free any nodes that might have been queued */
		return;
	}

	levelorder_traversal2(queue2, queue1, is_complete);
}



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

