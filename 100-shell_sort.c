#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using Shell sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;
	int temp;

	/* Calculate the starting interval */
	while (interval < size / 3)
		interval = interval * 3 + 1;

	/* Decrease interval over time */
	while (interval > 0)
	{
		/* Perform insertion sort for each interval */
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		/* Print array after each decrease in interval */
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
