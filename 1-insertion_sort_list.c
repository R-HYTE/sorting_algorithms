#include "sort.h"

/**
 * swap_nodes - Swaps a node with its previous one in a doubly linked list.
 * @node: The node to be swapped.
 * @list: The doubly linked list containing the nodes.
 * Return: A pointer to the node that was moved.
 */
listint_t *swap_nodes(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev;
	listint_t *current_node = node;

	prev_node->next = current_node->next;

	if (current_node->next)
	{
		current_node->next->prev = prev_node;
	}

	current_node->next = prev_node;
	current_node->prev = prev_node->prev;
	prev_node->prev = current_node;

	if (current_node->prev)
	{
		current_node->prev->next = current_node;
	}
	else
	{
		*list = current_node;
	}

	return (current_node);
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm.
 * @list: Double linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;

	while (node)
	{
		while (node->prev && (node->prev->n > node->n))
		{
			node = swap_nodes(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
