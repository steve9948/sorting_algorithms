#include "sort.h"

/**
 * swap_ints - Swap two integers of an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in an ascending order.
 * @array: An array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Displays the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool jump = false;

	if (array == NULL || size < 2)
		return;

	while (jump == false)
	{
		jump = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				jump = false;
			}
		}
		len--;
	}
}

