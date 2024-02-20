#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 * using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 * This function applies the Cocktail shaker sort algorithm to sort
 * a doubly linked list of integers in ascending order
 */

void cocktail_sort_list(listint_t **list)
{
	int is_swapped = 1;
	listint_t *current, *tail;

	if (!list || !*list || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL; tail = tail->next)
		;

	while (is_swapped)
	{
		is_swapped = 0;

		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes_forward(list, &tail, &current);
				print_list((const listint_t *) *list);
				is_swapped = 1;
			}
		}

		/* Move current back to the last sorted element */
		for (current = tail; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes_backward(list, &tail, &current);
				print_list((const listint_t *) *list);
				is_swapped = 1;
			}
		}
	}
}

/**
 * swap_nodes_forward - Swaps the current node with its next node
 * in a doubly linked list.
 * @head: Double pointer to the head of the doubly linked list.
 * @tail: Double pointer to the tail of the doubly linked list.
 * @curr: Double pointer to the current node to be swapped.
 * This function performs a forward swap of nodes in a doubly linked list.
 */

void swap_nodes_forward(listint_t **head, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->next;

	/* Update the previous node's next pointer to skip the current node */
	if ((*curr)->prev != NULL)
		(*curr)->prev->next = temp;
	else
		*head = temp;

	/* Update the previous pointer of the temporary node */
	temp->prev = (*curr)->prev;
	/* Update the next pointer of the current node to skip the next node */
	(*curr)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *curr;
	else
		*tail = *curr; /* If the next node is the tail, update the tail */

	(*curr)->prev = temp;
	temp->next = *curr;
	*curr = temp;
}

/**
 * swap_nodes_backward - Swaps the current node with its previous node in
 * a doubly linked list.
 * @head: Double pointer to the head of the doubly linked list.
 * @tail: Double pointer to the tail of the doubly linked list.
 * @curr: Double pointer to the current node to be swapped.
 * This function performs a backward swap of nodes in a doubly linked list.
 */

void swap_nodes_backward(listint_t **head, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*curr)->next;
	(*curr)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *curr;
	else
		*head = *curr;

	(*curr)->next = temp;
	temp->prev = *curr;
	*curr = temp;
}
