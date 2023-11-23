#include "sort.h"

/**
 * change_ints - Swap two integers in an array.
 * @a: First integer to be swapped.
 * @b: Second integer to be swapped.
 */
void change_ints(int *first, int *second)
{
	int tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Donald Knuth interval algorithim sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
			 change_ints(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}

