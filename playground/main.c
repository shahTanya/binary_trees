#include "binary_trees.h"


int main(void)
{
	queue_node_t *node;
	queue_t queue = {NULL, NULL};

	enqueue(&queue, binary_tree_node(NULL, 100));
	enqueue(&queue, binary_tree_node(NULL, 180));
	enqueue(&queue, binary_tree_node(NULL, 39));

	printq(&queue);
	printf("########\n");

	dequeue(&queue);
	dequeue(&queue);
	node = dequeue(&queue);
	if (node)
		printf("%d\n", node->node->n);
	printf("########\n");

	printq(&queue);

	return (0);
}
