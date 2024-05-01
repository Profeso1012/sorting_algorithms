#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *temp;

	temp = left->prev;

	if (temp)
		temp->next = right;
	right->prev = temp;
	left->prev = right;
	left->next = right->next;
	if (right->next)
		right->next->prev = left;
	right->next = left;
	if (!temp)
		*list = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *					   using the Cocktail Shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		temp = *list;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->next;
		}

		if (swapped == 0)
			break;
		swapped = 0;
		temp = temp->prev;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->prev;
		}
	} while (swapped);
}
