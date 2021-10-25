#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * shell_sort - Sorts an array using the shell sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void shell_sort(int *array, size_t size)
{
	int i, j, tmp, gap;

	if ((array == NULL) || (size < 2))
		return;
	gap = (size / 3) + 1;
	for (; gap > 0; )
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > tmp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
