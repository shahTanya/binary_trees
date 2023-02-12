#include "binary_trees.h"


void printq(queue_t *queue)
{
	queue_node_t *tmp, *tmp2;

	if (!queue)
	{
		printf("No queue store\n");
		return;
	}

	if (!queue->top)
	{
		printf("Empty queue\n");
		return;
	}

	tmp = queue->top;
	tmp2 = tmp;
	while (tmp)
	{
		tmp2 = tmp->next;
		printf("%d\n", tmp->node->n);

		tmp = tmp2;
	}
}
