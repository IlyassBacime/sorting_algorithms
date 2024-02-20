#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using the
 * Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Description:
 * This function implements the Counting Sort algorithm, a non-comparative
 * integer sorting technique that operates by counting occurrences of each
 * unique element in the input array. It is effective when the range of input
 * values is not significantly larger than the number of elements to
 * be sorted
 */

void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max, i, range;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	range = max + 1;
	output = malloc(size * sizeof(int));
	if (!output)
		return;

	count = malloc(range * sizeof(int));
	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	/* Update the counting array to store cumulative counts */
	for (i = 1; i < range; i++)
		count[i] += count[i - 1];

	print_array(count, range);
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
