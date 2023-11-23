#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly-linked list of position listint_t.
 * @h: Pointer to the head of the doubly-linked list.
 * @first: Pointer to the first node to swap.
 * @second: The second node to be swapped.
 */
void swap_nodes(listint_t **h, listint_t **first, listint_t *second)
{
	(*first)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *first;
	second->prev = (*first)->prev;
	second->next = *first;
	if ((*first)->prev != NULL)
		(*first)->prev->next = second;
	else
		*h = second;
	(*first)->prev = second;
	*first = second->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers.
 * @list: Pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after a swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

