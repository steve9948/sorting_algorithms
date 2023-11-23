#include "sort.h"

/**
 * swap_ints - Swaps two integers of an array.
 * @a: First integer to be swapped.
 * @b: Second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in a top down order.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Display the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *small;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		small = array + i;
		for (j = i + 1; j < size; j++)
			small = (array[j] < *small) ? (array + j) : small;

		if ((array + i) != small)
		{
			swap_ints(array + i, small);
			print_array(array, size);
		}
	}
}

