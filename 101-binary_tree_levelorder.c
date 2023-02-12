#include "binary_trees.h"

void levelorder_traversal(queue_t *queue1, queue_t *queue2, void (*func)(int));


/**
 * binary_tree_levelorder - goes through a
 * binary tree using level-order traversal.
 * @tree: address of tree to traverse.
 * @func: function to call on each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t queue1 = {NULL, NULL}, queue2 = {NULL, NULL};

	if (!tree || !func)
	{
		return;
	}

	enqueue(&queue1, (binary_tree_t *)tree);  /* enqueue the root node */
	func(tree->n);

	levelorder_traversal(&queue1, &queue2, func);
}


/**
 * levelorder_traversal - traverses a binary tree, one level at a time.
 * @queue1: address of a queue containing
 * nodes whose children belong to present level.
 * @queue2: pointer to queue containing parents of next-level nodes.
 * @func: logic to apply to each visited node's value.
 */
void levelorder_traversal(queue_t *queue1, queue_t *queue2, void (*func)(int))
{
	queue_node_t *q_node;
	binary_tree_t *bt_node;

	q_node = dequeue(queue1);
	while (q_node)
	{
		bt_node = q_node->node;  /* fetch the binary tree data in the queue_node_t */
		/* Enqueue both children */
		if (bt_node->left)
		{
			/* There's a left child */
			enqueue(queue2, bt_node->left);  /* enqueue in queue2 for next level */
			func(bt_node->left->n);
		}
		if (bt_node->right)
		{
			enqueue(queue2, bt_node->right);
			func(bt_node->right->n);
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

	levelorder_traversal(queue2, queue1, func);
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
