#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pd(x) printf("%d\n", x)

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;


/**
 * struct queue_node_s - a queue struct for storing a binary_tree_t node.
 * @next: pointer to next node.
 * @prev: pointer to previous node.
 * @node: pointer to a binary_tree_t node.
 */
typedef struct queue_node_s
{
	binary_tree_t *node;
	struct queue_node_s *next;
	struct queue_node_s *prev;
} queue_node_t;


/**
 * struct queue_s - stores the top and rear nodes of a queue_node_t struct.
 * @top: address of top of queue.
 * @rear: pointer to rear of queue.
 */
typedef struct queue_s
{
	queue_node_t *top;
	queue_node_t *rear;
} queue_t;


void binary_tree_print(const binary_tree_t *tree);  /* pretty print tree */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value); /* T0 */
binary_tree_t *binary_tree_insert_left(
		binary_tree_t *parent, int value);  /* T1 */
binary_tree_t *binary_tree_insert_right(
		binary_tree_t *parent, int value);  /* T2 */
void binary_tree_delete(binary_tree_t *tree);  /* T3 */
int binary_tree_is_leaf(const binary_tree_t *node);  /* T4 */
int binary_tree_is_root(const binary_tree_t *node);  /* T5 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int)); /*T6*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));  /*T7*/
void binary_tree_postorder(
		const binary_tree_t *tree, void (*func)(int));  /* T8 */
size_t binary_tree_height(const binary_tree_t *tree);  /* T9 */
size_t binary_tree_depth(const binary_tree_t *tree);  /* T10 */
size_t binary_tree_size(const binary_tree_t *tree);  /* T11 */
size_t binary_tree_leaves(const binary_tree_t *tree);  /* T12 */
size_t binary_tree_nodes(const binary_tree_t *tree);  /* T13 */
int binary_tree_balance(const binary_tree_t *tree);  /* T14 */
int binary_tree_is_full(const binary_tree_t *tree);  /* T15 */
int binary_tree_is_perfect(const binary_tree_t *tree);  /* T16 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);  /* T17 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);  /* T18 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second);  /* T19 */
void binary_tree_levelorder(
		const binary_tree_t *tree, void (*func)(int));  /* T20 */
int binary_tree_is_complete(const binary_tree_t *tree);  /* T21 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);  /* T22 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);  /* T23 */
int binary_tree_is_bst(const binary_tree_t *tree);  /* T24 */

/* Binary Search Tree */
bst_t *bst_insert(bst_t **tree, int value);  /* T25 */
bst_t *array_to_bst(int *array, size_t size);  /* T26 */
bst_t *bst_search(const bst_t *tree, int value);  /* T27 */
bst_t *bst_remove(bst_t *root, int value);  /* T28 */



/* Helper functions */
void enqueue(queue_t *queue, binary_tree_t *node);
queue_node_t *dequeue(queue_t *queue);
void delete_queue(queue_t *queue);
void printq(queue_t *queue);
int queue_empty(queue_t *queue);


#endif /* BINARY_TREES_H */
